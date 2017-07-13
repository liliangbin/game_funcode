//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// 主函数入口
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
    // 初始化游戏引擎
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



    // To do : 在此使用API更改窗口标题
    dSetWindowTitle("Lesson");

    // 引擎主循环，处理屏幕图像刷新等工作
    while( dEngineMainLoop() )
    {
        // 获取两次调用之间的时间差，传递给游戏逻辑处理
        float	fTimeDelta	=	dGetTimeDelta();

        // 执行游戏主循环
        GameMainLoop( fTimeDelta );
    };

    // 关闭游戏引擎
    dShutdownGameEngine();
    return 0;
}

//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
    // 可以在此添加游戏需要的响应函数

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
// 引擎捕捉鼠标点击消息后，将调用到本函数
int iMouseType=MOUSE_LEFT;
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // 可以在此添加游戏需要的响应函数

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
// 引擎捕捉鼠标弹起消息后，将调用到本函数
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // 可以在此添加游戏需要的响应函数

}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// iAltPress iShiftPress iCtrlPress 分别为判断Shift，Alt，Ctrl当前是否也处于按下状态。比如可以判断Ctrl+E组合键
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    // 可以在此添加游戏需要的响应函数

}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
void dOnKeyUp( const int iKey )
{
    // 可以在此添加游戏需要的响应函数

}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{

    dShowCursor(TRUE);
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}

