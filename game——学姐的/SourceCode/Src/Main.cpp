//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
#include "scene.h"
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"
#include "scene5.h"
#include "scene6.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// 主函数入口
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
    // 初始化游戏引擎
    if( !dInitGameEngine( hInstance, lpCmdLine ) )
        return 0;

    // To do : 在此使用API更改窗口标题
    dSetWindowTitle("Lesson");
    g_fScreenLeft	 = 	dGetScreenLeft();
    g_fScreenRight   = 	dGetScreenRight();
    g_fScreenTop 	 = 	dGetScreenTop();
    g_fScreenBottom  = 	dGetScreenBottom();

    // 引擎主循环，处理屏幕图像刷新等工作
    while( dEngineMainLoop() )
    {
        // 获取两次调用之间的时间差，传递给游戏逻辑处理
         fTimeDelta	=	dGetTimeDelta();
        // 执行游戏主循环
        if(SceneState==1&&FenShu>=10)
        {
            SceneState=2;
            g_iGameState=1;
            dStopSound( vice );
            FILE *fp;
            if((fp=fopen("score.txt","w"))!=NULL)
            {
                fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
                printf("0000");
            }
            fclose(fp);
        }
        b[SceneState]->GameMainLoop( fTimeDelta );
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
    b[SceneState]->MouseMove( fMouseX, fMouseY);
    // 可以在此添加游戏需要的响应函数
    //鼠标触碰选项；
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    b[SceneState]->MouseClick( iMouseType, fMouseX,  fMouseY );
    // 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉鼠标弹起消息后，将调用到本函数
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    b[SceneState]->MouseUp( iMouseType,  fMouseX,  fMouseY );
    // 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// iAltPress iShiftPress iCtrlPress 分别为判断Shift，Alt，Ctrl当前是否也处于按下状态。比如可以判断Ctrl+E组合键
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    b[SceneState]->KeyDown(  iKey,  iAltPress,  iShiftPress,  iCtrlPress );
}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
void dOnKeyUp( const int iKey )
{
    b[SceneState]->KeyUp( iKey );
}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    b[SceneState]->SpriteColSprite( szSrcName,  szTarName );
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    b[SceneState]->SpriteColWorldLimit(szName,iColSide);
}
