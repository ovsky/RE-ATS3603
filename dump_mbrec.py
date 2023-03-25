#!/usr/bin/env python3

# """
# Extract the core partitions from a flash dump of a BREC device.
# 
# Extract the partitions as indicated at offset 0x2000 in the flash dump (the "MBREC" signature)
# (from a flash dump containing the "ActBrm" signature at offset 0x1f4)
# """

import logging
import sys
import struct
from collections import namedtuple
import mmap

# initialize the logging system
logging.basicConfig()
log = logging.getLogger(__name__)
log.setLevel(logging.DEBUG)

# flash dump pattern for the BREC device
ACTBRM_OFFSET = 0x1F4           # 0x1F4
ACTBRM_SIGNATURE = b"ActBrm"    # 0x41 0x63 0x74 0x42 0x72 0x6d

MBREC_OFFSET = 0x2000           # 0x2000 / 8192
MBREC_BLOCK_SIZE = 0x200        # 0x200 / 512

# namedtuple is a factory function for creating tuple subclasses with named fields
Entry = namedtuple(
    "Entry",
    [
        "label",
        "type",
        "unknown",
        "offset",
        "size",
        "checksum",
    ],
)

#  0x00: 12 bytes label
def unpack_entry(offset: int, data: bytes) -> Entry:
    return Entry._make(struct.unpack_from("12sIIIII", data, offset=offset))

# Entry(label=b'bootloader', type=1, unknown=0, offset=0, size=0, checksum=0)
# unpack_entry(0x2000, mem) # 8192, 0x2000
def unpack_partition(entry: Entry, data: bytes) -> bytes:
    start = entry.offset * MBREC_BLOCK_SIZE
    end = start + entry.size
    return mem[start:end]

# get the partition info by unpacking the entry at target offset
# bootloader: 0x0-0x0 # 0x0 / 0 
# info_partition(unpack_entry(0x2000, mem)) 
def info_partition(entry: Entry) -> None:
    start = entry.offset * MBREC_BLOCK_SIZE
    end = start + entry.size
    print("{}: 0x{:x}-0x{:x}".format(entry.label.decode("utf-8"), start, end))

# dump the partition to a file with the name of the label
# dump_partition(unpack_entry(0x2000, mem), mem)
def dump_partition(entry: Entry, data: bytes) -> None:
    path = entry.label.decode("utf-8").replace("\x00", "")

    log.info("partition to path '%s', size of %d" % (path, entry.size))

    with open(path, "wb") as output:
        output.write(unpack_partition(entry, data))

# python3 extract_flash_brec.py flash_dump.bin
if __name__ == "__main__":
    path = sys.argv[1]
    dump = False
    
    log.info("Opening '%s' at: " % path)

    # open the file in read and write mode
    with open(path, "r+b") as f:
        # map the file, size 0 means whole file 
        # mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
        mem = mmap.mmap(f.fileno(), 0) 

        if (
            not mem[ACTBRM_OFFSET : ACTBRM_OFFSET + len(ACTBRM_SIGNATURE)]
            == ACTBRM_SIGNATURE
        ):
            raise Exception("There is no signature at offset: " % ACTBRM_SIGNATURE)

        log.debug("Found %s signature: " % ACTBRM_SIGNATURE)

        # entries stream cache
        entries = []
        offset = MBREC_OFFSET

        while True:

            entry = unpack_entry(offset, mem)

            # if the first byte label in the 0x00 position 
            # is its identifier (0x00) then break the loop
            if entry.label[0] == 0: 
                break
            
            # log the entry
            log.debug(repr(entry))

            # append the entry to the list
            entries.append(entry)
            offset += 0x20

        for entry in entries:
            if dump:
                dump_partition(entry, mem)
            else:
                info_partition(entry)
