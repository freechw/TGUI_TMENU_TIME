/* ----------------------------------------------------------------------------
 *                TMenu��������
 * --------------------------------------------------------------------------*/

#ifndef __T_MENU_H 
#define __T_MENU_H

//TMenu�ǽ�����TGUI֮�ϵ�һ�ײ˵�ϵͳ,���������
//��ɫ���ϵĲ�����������ʾ

#include "TMenuBase.h"       //�û��ӿ�

/**********************************************************************
                         �û��ӿ�
**********************************************************************/
//#define     NULL_TMENU        //��ʱ���ҽӲ˵�ϵͳʱ���� 
 

#ifdef NULL_TMENU
#define TMenuInit() do{}while(0)

#define TMenuKey(Key) do{}while(0)

#define TMenuTask() do{}while(0)

#else

//�û���ÿ��һ�˵�����ɫ��ʵ��һ��TMenu_t(��TMenuBase.h��);

//-------------------------------TMenu��ʼ������----------------------
//����ʱ���ó�ʼ���˵�ϵͳ
void TMenuInit(void);

//-------------------------------TMenu������������----------------------------
//���˵����ڲ˵��ڲ�ʱ�����˺���
//���ط�0ʱ��ʾ�˳��˵�ϵͳ
signed char TMenuKey(unsigned char Key);

//-------------------------------TMenu���̺���----------------------------
//10ms����һ��
void TMenuTask(void);

#endif

/**********************************************************************
                     ��Ա��������
//֧�ֳ���ָ��ʱ��ֱ�ӵ���
**********************************************************************/

//-----------------------�õ���ǰ�˵�ָ��----------------------------
//ָ��ΪNULLʱ��ʾ���ڲ˵���
const TMenu_t *pTMenu_GetCurMenu(void);


//-----------------------�õ���ǰ�˵����----------------------------
unsigned char TMenu_GetCurMenuLayer(void);

//-----------------------ǿ�ƽ���ָ���˵�------------------------
void TMenu_GogoMenu(const TMenu_t *pCurMenu, //ǿ������Ĳ˵��ṹ
                    unsigned short MenuID,  //�˵�ID,��ЧʱΪ0
                    unsigned char Layer);    //�ýṹ���ڲ˵��ڵĲ��

//-----------------------ǿ��ˢ�µ�ǰ�˵�����--------------------------
//���ô˺���������ˢ�µ�ǰ�˵���������ʾ����
//ͨ����ָ���˵����ڵ��ô˺�������ʵ�����ݵĶ�̬ˢ��
void TMenu_Refresh(void);

//-------------------------�����ػ����к���-------------------------
//�Դ�Ϊ������Ӧ�ó���(�Ǽ̳���)��ʼ����ɺ���ô˺����ػ�����
#define TMenu_PaintAll(pListboxEx) \
  do{ListBox_PaintAll((TListbox_t *)(pListboxEx));}while(0)

//--------------------------------�˳��˵�����--------------------------
void TMenu_ExitMenu(void);

//-----------------���ݴ���ID�õ����ھ���õ�����-------------------
//��������,����ϵͳ��ʼ��ʱʹ��
TWin_t *TMenu_pGetTWin(unsigned char WinID);

//-----------------�����ǿ���ƶ���ָ��λ�ú���-------------------
void TMenu_MoveCousor(unsigned char Pos);

/**********************************************************************
                         TMenu�û��ص�����
**********************************************************************/

//--------------�õ�TMenu����Ҫ���������ݻ���------------------
//>һ���õ�����ַ�
extern void *TMenu_pGetBuf(void); 

//---------------------����˵�ͨ������------------------------
//#define TMenu_cbEnterMenuNotify() do{}while(0)
void TMenu_cbEnterMenuNotify(void);

//---------------------�˳��˵�ͨ������------------------------
//#define TMenu_cbExitMenuNotify() do{}while(0)
void TMenu_cbExitMenuNotify(void);

//---------------------��󻯴��ڴ�С����-----------------------
//�ɱ䴰��ʱ,����˵�ǰ�Ƚ��ɱ䴰�����
#ifdef TMENU_WIN_VARIABLE   //�ɱ䴰��ʱ���û�������
  void TMenu_MaxWin(unsigned char Type, //�˵�����
                  TWinHandle_t hWin);
#else
  #define TMenu_MaxWin(type, hWin) do{}while(0)
#endif

//---------------------���ô��ڴ�С����--------------------------
//�ɱ䴰��ʱ,����˵�����ݴ������ݴ�С�Զ��任����
#ifdef TMENU_WIN_VARIABLE   //�ɱ䴰��ʱ���û�������
  void TMenu_ReBulidWin(TListboxEx_t *pListboxEx,//�ؽ���ɵ��б���
                        unsigned char w,  //��ǰ�˵�ϵͳ�������
                        unsigned char h,//��ǰ�˵�ϵͳ����߶�
                        unsigned char HeaderW); //ͷ����
#else
  #define TMenu_ReBulidWin(hWin,w,h,HeaderW) do{}while(0)
#endif

/**********************************************************************
                         TGUI��δʵ�ֵĻص�����
**********************************************************************/
//----------------------�õ���������ṹ����-----------------------
//��ĳЩ��Ƭ����֧��code��ָ��,�����ں��ѱ�����code��ָ������,
//�ں��賣��ʱ,ʹ�����г�����ʱ����泣������>= 3;
extern char *TGUI_pGetConstBuf(void); 

//----------------------�õ����水ť��-----------------------
//��[��  ��]
const char *cbGetSaveBottom(void); 

//----------------------�õ����ذ�ť��-----------------------
//��[��  ��]
const char *cbGetReturnBottom(void); 

/**************************************************************************
                        TMenu��س�Ա��������
  ��û�ж���TMENU_USE_CONST_BUFʱ���к�����ʵ��,�����û���ʵ�����к���
  Menu_t�ṹ�е�ʹ��ָ������г�Աͨ���˺�����������Ϣ
**************************************************************************/

//--------------------�õ�����˵��ṹ--------------------------
//TMENUϵͳͨ���˽ṹʹ��ǰ�˵�ָ�򶥲�˵�
//�����ڶ�����˵�ʱ�����޸Ĵ˺�������ϵͳӦ����ת��ͬ�����˵�
const TMenu_t *TM_pGetTopMenu(void);

//---------------------�õ����˵��ṹ����----------------------------
//TMENUϵͳͨ���˽ṹʹ��ǰ�˵�ָ�򸸲˵�
const TMenu_t *TM_pGetParent(const TMenu_t *pMenu);

//-------------------------����Ӳ˵��ṹ����------------------------
//TMENUϵͳͨ���˽ṹʹ��ǰ�˵�ָ��ĳ���Ӳ˵�
const TMenu_t *TM_pGetSubMenu(const TMenu_t *pMenu,
                              unsigned char SubMenuID);

//-------------------------���ָ���˵��ṹ����------------------------
const TMenu_t *TM_pGetMenu(const TMenu_t *pMenu,   //ǿ����ת�Ĳ˵��ṹ
                           unsigned short MenuID); //���ɲ���,�����ڲ˵�ʶ��

//-------------------�Ӳ˵��ṹ��ò˵�ͷ����------------------------
const char *TM_GetHeader(const TMenu_t *pMenu);

//-------------------�Ӳ˵��ṹ������ͺ���------------------------
unsigned char TM_GetType(const TMenu_t *pMenu);

//-------------------�Ӳ˵��ṹ��ô�С����------------------------
unsigned char TM_GetSize(const TMenu_t *pMenu);

//----------------�õ�ָ���Ӳ˵���ͷ����-------------------
const char *TM_GetSubMenuHeader(const TMenu_t *pMenu,
                                unsigned char Item);

//-------------------�Ӳ˵��ṹ������ַ�������-------------------
const char *TM_GetItemString(const TMenu_t *pMenu,
                             unsigned char Item);

//-------------------ͳ�Ʋ˵��������Ⱥ���-----------------------
TItemSize_t TM_GetItemMaxLen(const TMenu_t *pMenu);



#endif
