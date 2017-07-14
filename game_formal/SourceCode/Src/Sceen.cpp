#include "Sceen.h"
#include "CommonAPI.h"
#include "stdio.h"
#include "LessonX.h"
Sceen::Sceen()
{
    //ctor
}
Sceen::~Sceen()
{
    //dtor
}
//初始化数据用在这个地方
// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();



void Sceen::Load()
{
    dLoadMap("level1.t2d");
    g_iGameState		=	1;

    printf("场景的出现");
}



void Sceen::MainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // 初始化游戏，清空上一局相关数据
    case 1:
    {
        GameInit();
        printf("game kaishi");
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

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void	Sceen::GameInit()
{


}
//==============================================================================
//
// 每局游戏进行中
void	Sceen::GameRun( float fDeltaTime )
{


}
//==============================================================================
//
// 本局游戏结束
void	Sceen::GameEnd()
{
}

void Sceen::MouseMove( const float fMouseX, const float fMouseY )
{



}
void Sceen::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{


state =1 ;
// b[state]->Load();

}
void Sceen::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{



}

void Sceen::SpriteColSprite( const char *szSrcName, const char *szTarName )
{


}

void Sceen::SpriteColWorldLimit( const char *szName, const int iColSide )
{


}


void Sceen::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

};
void Sceen::KeyUp( const int iKey )
{

};
