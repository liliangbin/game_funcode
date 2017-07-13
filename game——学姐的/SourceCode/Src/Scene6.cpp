#include "Scene6.h"
#include "CommonAPI.h"
#include "LessonX.h"
Scene6::Scene6()
{
    //ctor
}

Scene6::~Scene6()
{
    //dtor
}
void Scene6::Load()
{
    dLoadMap("Win.t2d");
}
void Scene6::GameMainLoop(float fDeltaTime )
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
void Scene6::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Scene6::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene6::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene6::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    switch(iKey)
    {
    case KEY_ENTER:
        SceneState=5;
        g_iGameState=1;
        break;
    default:
        break;
    }
}
void Scene6::KeyUp( const int iKey )
{

}
void Scene6::SpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
void Scene6::SpriteColWorldLimit( const char *szName, const int iColSide )
{

}
