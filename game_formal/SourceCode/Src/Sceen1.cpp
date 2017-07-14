#include "Sceen1.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Sceen1::Sceen1()
{
    //ctor
}

Sceen1::~Sceen1()
{
    //dtor
}


//初始化数据用在这个地方
// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中
//

void Sceen1::Load()
{
    dLoadMap("sceen1.t2d");
    g_iGameState		=	1;

    printf("场景的出现");

}


void Sceen1::MainLoop( float	fDeltaTime )
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

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void	Sceen1::GameInit()
{




}
//==============================================================================
//
// 每局游戏进行中
void	Sceen1::GameRun( float fDeltaTime )
{



    g_fScreenLeft	 = 	dGetScreenLeft();
    g_fScreenRight  = 	dGetScreenRight();
    g_fScreenTop 	 = 	dGetScreenTop();
    g_fScreenBottom = 	dGetScreenBottom();


    dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, -5, g_fScreenRight, g_fScreenBottom);
    dSetSpriteMass( "hero", 1);

    float speed =g_fSpeedLeft+g_fSpeedRight;

    if(speed==0)
    {
        dAnimateSpritePlayAnimation("hero","herodongtu2",0);


    }
//    else
//    {
//        dAnimateSpritePlayAnimation("hero","herodongtu2",0);
//
//    }

}

//==============================================================================
//
// 本局游戏结束
void	Sceen1::GameEnd()
{
}

void Sceen1::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Sceen1::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Sceen1::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{


}

void Sceen1::SpriteColSprite( const char *szSrcName, const char *szTarName )
{


}
// iColSide : 0 左边，1 右边，2 上边，3 下边

void Sceen1::SpriteColWorldLimit( const char *szName, const int iColSide )
{
    printf("pengzhuang");

    if(strcmp(szName,"hero")==0)
    {

        if(iColSide==0||iColSide==1)
        {
            dSetSpriteLinearVelocityX("hero", 0);

        }

        if(iColSide==2)
        {
            dSetSpriteLinearVelocityY("hero", 3);
        }
        else if(iColSide==3)
        {
            dSetSpriteLinearVelocityY("hero", -3);
            ctroljump=1;
        }

    }

}


void Sceen1::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    head(iKey);


    if(iKey== KEY_K&&ctroljump==1)
    {

        ctroljump=0;
        dSetSpriteImpulseForce("hero",0,-160,0);

    }

};


void Sceen1::KeyUp( const int iKey )
{
    up(iKey);


//    if(iKey==KEY_A||iKey==KEY_D){
//
//        dAnimateSpritePlayAnimation("hero","herodongtu1",0);
//
//        printf("jiuishi ");
//
//
    //  }




};
