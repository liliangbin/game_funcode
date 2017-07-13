#include "Scene4.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Scene4::Scene4()
{
    //ctor
}

Scene4::~Scene4()
{
    //dtor
}
void Scene4::Load()
{
    dLoadMap("Gameover.t2d");
}
void Scene4::GameMainLoop(float fDeltaTime)
{

    switch( g_iGameState )
    {
    // 初始化游戏，清空上一局相关数据
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // 初始化之后，将游戏状态设置为进行中
    }
    break;
    // 游戏进行中，处理各种游戏逻辑
    case 2:
    {
        // TODO 修改此处游戏循环条件，完成正确游戏逻辑
        if( true )
        {
            GameRun( fDeltaTime );
        }
        else
        {
            // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
            g_iGameState	=	0;
            GameEnd();
        }
    }
    break;

    // 游戏结束/等待按空格键开始
    case 0:
    default:
        break;
    };
}
void Scene4::MouseMove( const float fMouseX, const float fMouseY )
{
    Continue = dIsPointInSprite( "Continue",fMouseX, fMouseY );
    if( Continue == 1 )
    {
        dSetSpriteScale( "Continue", 1.2 );
    }
    if(Continue == 0) dSetSpriteScale( "Continue", 1 );
    Back = dIsPointInSprite( "Back",fMouseX, fMouseY );
    if( Back == 1 )
    {
        dSetSpriteScale( "Back", 1.2 );
    }
    if(Back == 0) dSetSpriteScale( "Back", 1 );
}
void Scene4::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    if( Continue == 1&& iMouseType== 0  )
    {
        SceneState=JustGuan;
        g_iGameState  =	1;
        dStopSound( vice );

    }
    if( Back == 1&& iMouseType== 0  )
    {
        SceneState=5;
        g_iGameState=1;
        dStopSound( vice );

    }
}
void Scene4::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene4::SpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
void Scene4::SpriteColWorldLimit( const char *szName, const int iColSide )
{

}
