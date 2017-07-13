//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////

float fWidth1,fWidth2,fWidth3,fWidth4;
float fHeight1,fHeight2,fHeight3,fHeight4;
int cgjwid,fgmyid,ydyjid,cfhgid;

int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)


{
    // ��ʼ����Ϸ����
    if( !dInitGameEngine( hInstance, lpCmdLine ) )
        return 0;

    fWidth1=dGetSpriteWidth("kaishiyouxi");
    fHeight1=dGetSpriteHeight("kaishiyouxi");
    fWidth2=dGetSpriteWidth("caozuojianjie");
    fHeight2=dGetSpriteHeight("caozuojianjie");
    fWidth3=dGetSpriteWidth("duqucundang");
    fHeight3=dGetSpriteHeight("duqucundang");

    dSpriteMountToSpriteLinkPoint("caozuojianjie","chushijiemian",1);
    dSpriteMountToSpriteLinkPoint("kaishiyouxi","chushijiemian",2);
    dSpriteMountToSpriteLinkPoint("duqucundang","chushijiemian",3);
    dSetSpriteMountOwned("caozuojianjie",1);
    dSetSpriteMountOwned("kaishiyouxi",1);
    dSetSpriteMountOwned("duqucundang",1);
    cgjwid=dPlaySound("chenguangjianwu.ogg",1,0.7);



    // To do : �ڴ�ʹ��API���Ĵ��ڱ���
    dSetWindowTitle("Lesson");

    // ������ѭ����������Ļͼ��ˢ�µȹ���
    while( dEngineMainLoop() )
    {
        // ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
        float	fTimeDelta	=	dGetTimeDelta();

        // ִ����Ϸ��ѭ��
        GameMainLoop( fTimeDelta );
    };

    // �ر���Ϸ����
    dShutdownGameEngine();
    return 0;
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

    dSetSpritePosition("shujian",fMouseX,fMouseY);
    dShowCursor(FALSE);
    if(dIsPointInSprite("kaishiyouxi",fMouseX,fMouseY)==1)
    {
        dSetSpriteWidth("kaishiyouxi",fWidth1+0.5);
        dSetSpriteHeight("kaishiyouxi",fHeight1+0.5);
    }
    else if(dIsPointInSprite("caozuojianjie",fMouseX,fMouseY)==1)
    {
        dSetSpriteWidth("caozuojianjie",fWidth2+0.5);
        dSetSpriteHeight("caozuojianjie",fHeight2+0.5);
    }
    else if(dIsPointInSprite("duqucundang",fMouseX,fMouseY)==1)
    {
        dSetSpriteWidth("duqucundang",fWidth3+0.5);
        dSetSpriteHeight("duqucundang",fHeight3+0.5);
    }

    else if(dIsPointInSprite("back",fMouseX,fMouseY)==1)
    {
        dSetSpriteWidth("back",fWidth4+0.5);
        dSetSpriteHeight("back",fHeight4+0.5);
    }
    else
    {
        dSetSpriteWidth("kaishiyouxi",fWidth1);
        dSetSpriteHeight("kaishiyouxi",fHeight1);
        dSetSpriteWidth("caozuojianjie",fWidth2);
        dSetSpriteHeight("caozuojianjie",fHeight2);
        dSetSpriteWidth("duqucundang",fWidth3);
        dSetSpriteHeight("duqucundang",fHeight3);
        dSetSpriteWidth("back",fWidth4);
        dSetSpriteHeight("back",fHeight4);
    }

}


//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
int iMouseType=MOUSE_LEFT;
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

    if(dIsPointInSprite("caozuojianjie",fMouseX,fMouseY)==1)
    {
        dStopAllSound();
        dLoadMap("jiaochengjiemian.t2d");

        dPlaySound("yuediyunjie.ogg",1,0.7);
        fWidth4=dGetSpriteWidth("back");
        fHeight4=dGetSpriteHeight("back");
    }
    else if(dIsPointInSprite("back",fMouseX,fMouseY)==1)
    {
        dStopAllSound();
        dLoadMap("level.t2d");

        dPlaySound("chenguangjianwu.ogg",1,0.7);
    }
    else if(dIsPointInSprite("kaishiyouxi",fMouseX,fMouseY)==1)
    {
        dStopAllSound();
        dLoadMap("xuanguanjiemian.t2d");

        fgmyid=dPlaySound("fenggemengyuan.ogg",1,0.7);
        fWidth4=dGetSpriteWidth("back");
        fHeight4=dGetSpriteHeight("back");
    }

}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// iAltPress iShiftPress iCtrlPress �ֱ�Ϊ�ж�Shift��Alt��Ctrl��ǰ�Ƿ�Ҳ���ڰ���״̬����������ж�Ctrl+E��ϼ�
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void dOnKeyUp( const int iKey )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{

    dShowCursor(TRUE);
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}

