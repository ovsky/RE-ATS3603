/********************************************************************************
 *                              USDK(1100)
 *                             Module: app 
 *                 Copyright(c) 2003-2009 Actions Semiconductor,
 *                            All Rights Reserved. 
 * File : menuview.h
 * History:         
 *      <author>    <time>           <version >             <desc>
 *    songzhining    2009-2-25          v1.0               build this file 
 ********************************************************************************/
/*!
 * \file     menuview.h
 * \brief    menuview widget interface
 * \author   songzhining
 *               
 * \version 1.0
 * \date  2009/02/25
 *******************************************************************************/

/*! 
 * \defgroup   common_menuview    menuview¿Ø¼ş½Ó¿Úº¯Êı
 */

#ifndef __MENUVIEW_H__
#define __MENUVIEW_H__


#include "include_case.h"

#include "menu.h"

/*!
 * \par menuview ÏÔÊ¾ÀàĞÍ 
 *  \li MENUVIEW_OPTION: ×Ó²Ëµ¥--µ¥ĞĞÏÔÊ¾
 *  \li MENUVIEW_OPTION_INFO : ×Ó²Ëµ¥ÏêÏ¸ĞÅÏ¢--Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_MENULIST_TEXT : ²Ëµ¥ÁĞ±í--µ¥ĞĞÏÔÊ¾(²»´øÍ¼±ê)
 *  \li MENUVIEW_MENULIST_ICON : ²Ëµ¥ÁĞ±í--µ¥ĞĞÏÔÊ¾(´øÍ¼±ê)
 *  \li MENUVIEW_FILELIST_TEXT : ÎÄ¼şÁĞ±í(²»´øÍ¼±ê), µ±Ç°ĞĞ: Ë«ĞĞÏÔÊ¾, ·Çµ±Ç°ĞĞ: µ¥ĞĞÏÔÊ¾
 *  \li MENUVIEW_FILELIST_ICON : ÎÄ¼şÁĞ±í(´øÍ¼±ê), µ±Ç°ĞĞ: Ë«ĞĞÏÔÊ¾, ·Çµ±Ç°ĞĞ: µ¥ĞĞÏÔÊ¾
 *  \li MENUVIEW_PICLIST_MUSIC : ÒôÀÖÁĞ±í: Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_PICLIST_VIDEO : ÊÓÆµÁĞ±í: Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_PICLIST_PICTURE : Í¼Æ¬ÁĞ±í: Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_PICLIST_EBOOK : µç×ÓÊéÁĞ±í: Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_PICLIST_INFO : ÉèÖÃÏêÏ¸ĞÅÏ¢--Ë«ĞĞÏÔÊ¾
 *  \li MENUVIEW_MAX : ËùÓĞÖÖÀàÊıÄ¿
 */
typedef enum
{
    MENUVIEW_OPTION,
    MENUVIEW_OPTION_INFO,
    MENUVIEW_MENULIST_TEXT,
    MENUVIEW_MENULIST_ICON,
    MENUVIEW_FILELIST_TEXT,
    MENUVIEW_FILELIST_ICON,
    MENUVIEW_PICLIST_MUSIC,
    MENUVIEW_PICLIST_VIDEO,
    MENUVIEW_PICLIST_PICTURE,
    MENUVIEW_PICLIST_EBOOK,
    MENUVIEW_PICLIST_INFO,
    MENUVIEW_MAX,
    
}menuview_type_e;

/*!
 *  \par menuview ¿Ø¼ş¶ÔÍâĞÅºÅÀàĞÍ
 *  \li WIDGET_SIG_MENUVIEW_UP : ¸ßÁÁÌõÉÏÒÆÒ»ĞĞ
 *  \li WIDGET_SIG_MENUVIEW_DOWN : ¸ßÁÁÌõÏÂÒÆÒ»ĞĞ
 *  \li WIDGET_SIG_MENUVIEW_OK : ²Ëµ¥È·¶¨
 *  \li WIDGET_SIG_MENUVIEW_QUIT : ²Ëµ¥ÍË³ö
 *  \li WIDGET_SIG_MENUVIEW_EXCEED_FIRST : ³¬³öÆğÊ¼²Ëµ¥ÏîÒ»Ïî
 *  \li WIDGET_SIG_MENUVIEW_EXCEED_LAST : ³¬³ö×îºó²Ëµ¥ÏîÒ»Ïî
 *  \li WIDGET_SIG_MENUVIEW_UPDATE_ALL : ĞèÒªÍâ²¿¸üĞÂÈ«²¿Êı¾İ
 *  \li WIDGET_SIG_MENUVIEW_SHORT_MENU : MENU¶Ì°´,Èçµ¯³ö×Ó²Ëµ¥
 *  \li WIDGET_SIG_MENUVIEW_LONG_MENU : MENU³¤°´,Èç×¨¼­coverflowÇĞ»»
 *  \li WIDGET_SIG_MENUVIEW_DELETE : É¾³ı¼ü°´ÏÂ
 */
typedef enum
{
    WIDGET_SIG_MENUVIEW_UP,
    WIDGET_SIG_MENUVIEW_DOWN,
    WIDGET_SIG_MENUVIEW_OK,
    WIDGET_SIG_MENUVIEW_QUIT,
    WIDGET_SIG_MENUVIEW_EXCEED_FIRST,
    WIDGET_SIG_MENUVIEW_EXCEED_LAST,
    WIDGET_SIG_MENUVIEW_UPDATE_ALL,
    WIDGET_SIG_MENUVIEW_SHORT_MENU,
    WIDGET_SIG_MENUVIEW_LONG_MENU,
    WIDGET_SIG_MENUVIEW_DELETE,
    
}menuview_sig_e;

/*!
 *  \brief 
 *  menuview ¿Ø¼ş¾ä±ú½á¹¹¶¨Òå
 */
typedef struct menuview_s
{
    /*! ÁĞ±íÏÔÊ¾ÀàĞÍ */
    menuview_type_e type;
    
    /*! »­²¼ID */
    int canvas_id;
    
    /*! ĞÅºÅ»Øµ÷º¯Êı */
    void (*callback)( struct menuview_s *, menuview_sig_e );

    /*! ²Ëµ¥Êı¾İÖ¸Õë */
    menu_t* menu;

    /*! ÄÚ²¿Ë½ÓĞÊı¾İ½á¹¹Ö¸Õë£¬½ö¹© menuview ¿Ø¼şÄÚ²¿ÊµÏÖÊ¹ÓÃ */
    struct menuview_private_s * private; 

}menuview_t;


/*!
 *  \brief 
 *  menuview ¿Ø¼şµÄĞÅºÅ»Øµ÷º¯ÊıÀàĞÍ
 */
typedef void (*menuview_cb_t)( menuview_t *, menuview_sig_e );

/* menuview ¿Ø¼ş»ù±¾½Ó¿Ú */

/******************************************************************************/
/*!                    
* \par  Description:
*     ´´½¨Ò»¸ömenuview¿Ø¼ş  
* \ingroup common_menuview
* \param [in] type: ÁĞ±íÏÔÊ¾ÀàĞÍ
* \param [in] callback: ½ÓÊÜ menuview ĞÅºÅµÄ»Øµ÷º¯Êı 
* \return  ³É¹¦·µ»ØÒ»¸ö menuview ¾ä±ú, Ê§°Ü·µ»ØNULL      
*******************************************************************************/
menuview_t* menuview_create( menuview_type_e type, menuview_cb_t callback );

/******************************************************************************/
/*!                    
* \par  Description:
*     É¾³ıÒ»¸ömenuview¿Ø¼ş  
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
*******************************************************************************/
bool menuview_delete( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview »æÍ¼½Ó¿Ú  
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
* \note ´Ëº¯Êı»æÖÆmenuview¿Ø¼şµÄËùÓĞÔªËØ£¬Ò»°ãÓÃÓÚĞèÒªÕûÌå¸üĞÂmenuview¿Ø¼ş
*******************************************************************************/
bool menuview_paint( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼şGUIÏûÏ¢´¦Àíº¯Êı£¬µ÷ÓÃÕßĞèÒª½«GUIÏûÏ¢´«µİ¸ø´Ëº¯Êı
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \param [in] pmsg: GUIÏûÏ¢ 
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
* \note ¿Ø¼şÄÚ²¿ÓĞÊÂ¼ş·¢ÉúÊ±,ÏÈµ÷ÓÃµ±Ç°²Ëµ¥ÏîµÄ»Øµ÷, ÔÙµ÷ÓÃ¿Ø¼şµÄĞÅºÅ»Øµ÷º¯Êı
*******************************************************************************/
bool menuview_proc_gui( menuview_t *menuview, gui_wm_message_t *pmsg );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş¼ÓÔØstyle×ÊÔ´  
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \param [in] type: ÁĞ±íÏÔÊ¾ÀàĞÍ
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
* \note Íâ²¿µ÷ÓÃ½öÓÃÓÚ¶¯Ì¬ÇĞ»»ÏÔÊ¾·ç¸ñÊ±
*******************************************************************************/
bool menuview_load_style( menuview_t *menuview, menuview_type_e type );

/******************************************************************************/
/*!                    
* \par  Description:
*     ÏÔÊ¾menuview¿Ø¼ş  
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
*******************************************************************************/
bool menuview_show( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     Òş²Ømenuview¿Ø¼ş  
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
*******************************************************************************/
bool menuview_hide( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼şÉèÖÃ²Ëµ¥Êı¾İ
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \param [in] menu: ²Ëµ¥Êı¾İÖ¸Õë
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
* \note menuview Ö»¸ºÔğÏÔÊ¾ºÍÊäÈë´¦Àí, ²Ëµ¥Êı¾İ±ØĞëÓÉÍâ²¿ÉèÖÃºÍ±£´æ
*******************************************************************************/
bool menuview_set_menu( menuview_t *menuview, menu_t* menu );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡²Ëµ¥Êı¾İ
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÒ»¸ö ²Ëµ¥Êı¾İ Ö¸Õë, Ê§°Ü·µ»ØNULL   
*******************************************************************************/
menu_t* menuview_get_menu( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼şÉèÖÃÏÔÊ¾ĞĞÊı
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \param [in] lines: ÏÔÊ¾ĞĞÊı
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
* \note menuview ´´½¨Ê±¶ÁÈ¡style×ÊÔ´Ê±×Ô¶¯¼ÆËãĞĞÊı, Ò»°ãÎŞĞèµ÷ÓÃ
*******************************************************************************/
bool menuview_set_lines( menuview_t *menuview, int lines );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡ÏÔÊ¾ĞĞÊı
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÒ»¸ö ÏÔÊ¾ĞĞÊı, Ê§°Ü·µ»Ø -1  Ğ
*******************************************************************************/
int menuview_get_lines( menuview_t *menuview );


/* menuview ¿Ø¼ş¸ß¼¶½Ó¿Ú */

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡¶¯Ì¬Í¼Æ¬µÄ¿í¶È
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÒ»¸ö ¶¯Ì¬Í¼Æ¬µÄ¿í¶È, Ê§°Ü·µ»Ø -1  
* \note menuview ÖĞ¶¯Ì¬Í¼Æ¬ÓÉÍâ²¿ÁíÆğÏß³ÌÀ´½âÂë, ÈçmusicµÄ×¨¼­Í¼Æ¬»òvideoÔ¤ÀÀÍ¼,
*       ½âÂëÇ°ÏÈ»ñÈ¡Í¼Æ¬³ß´ç
*******************************************************************************/
int menuview_get_bitmap_width( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡¶¯Ì¬Í¼Æ¬µÄ¸ß¶È
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÒ»¸ö ¶¯Ì¬Í¼Æ¬µÄ¸ß¶È, Ê§°Ü·µ»Ø -1  
* \note menuview ÖĞ¶¯Ì¬Í¼Æ¬ÓÉÍâ²¿ÁíÆğÏß³ÌÀ´½âÂë, ÈçmusicµÄ×¨¼­Í¼Æ¬»òvideoÔ¤ÀÀÍ¼,
*       ½âÂëÇ°ÏÈ»ñÈ¡Í¼Æ¬³ß´ç
*******************************************************************************/
int menuview_get_bitmap_height( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»æÖÆÒ»ÕÅ¶¯Ì¬Í¼Æ¬
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú  
* \param [in] cur_index: menuview¿Ø¼şÁĞ±íÏîµÄË÷Òı
* \return  ³É¹¦·µ»ØÒ»¸ö ¶¯Ì¬Í¼Æ¬µÄ¿í¶È, Ê§°Ü·µ»Ø -1  
* \note menuview ÖĞ¶¯Ì¬Í¼Æ¬ÓÉÍâ²¿ÁíÆğÏß³ÌÀ´½âÂë, ÈçmusicµÄ×¨¼­Í¼Æ¬»òvideoÔ¤ÀÀÍ¼,
*       ½âÂëÇ°ÏÈ»ñÈ¡Í¼Æ¬³ß´ç, ½âÂë½áÊøºóµ÷ÓÃ¸Ã½Ó¿ÚÀ´»æÖÆ¶¯Ì¬Í¼Æ¬
*******************************************************************************/
bool menuview_paint_bitmap( menuview_t *menuview, int cur_index );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼şÉèÖÃÔ¤¼ÓÔØĞĞÊı
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú 
* \param [in] lines: Ô¤¼ÓÔØĞĞÊı
* \return  ³É¹¦·µ»Øtrue, Ê§°Ü·µ»Øfalse      
*******************************************************************************/
bool menuview_set_prefetch_num( menuview_t *menuview, int lines );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡Ô¤¼ÓÔØĞĞÊı
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÔ¤¼ÓÔØĞĞÊı, Ê§°Ü·µ»Ø -1  
*******************************************************************************/
int menuview_get_prefetch_num( menuview_t *menuview );

/******************************************************************************/
/*!                    
* \par  Description:
*     menuview ¿Ø¼ş»ñÈ¡Ô¤¼ÓÔØ´¦ÀíµÄÆğÊ¼ĞĞ
* \ingroup common_menuview
* \param [in] menuview: menuview¿Ø¼ş¾ä±ú     
* \return  ³É¹¦·µ»ØÔ¤¼ÓÔØ´¦ÀíµÄÆğÊ¼ĞĞ, Ê§°Ü·µ»Ø -1  
*******************************************************************************/
int menuview_get_prefetch_start( menuview_t *menuview );

#endif

