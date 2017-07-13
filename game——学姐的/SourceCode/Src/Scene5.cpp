#include "Scene5.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Scene5::Scene5()
{
    //ctor
}

Scene5::~Scene5()
{
    //dtor
}
void Scene5::Load()
{
    dLoadMap("Start.t2d");
}
void Scene5::GameMainLoop(float fDeltaTime )
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
void Scene5::MouseMove( float fMouseX, float fMouseY)
{
    jieshu = dIsPointInSprite( "Jieshu",fMouseX, fMouseY );
    beijin = dIsPointInSprite( "Beijing",fMouseX, fMouseY );
    kaishi = dIsPointInSprite( "Kaishi",fMouseX, fMouseY );
    if(jieshu == 1 )
    {
        dSetSpriteScale( "Jieshu", 1.2 );
    }
    if(jieshu == 0) dSetSpriteScale( "Jieshu", 1 );
    if(beijin == 1)
    {
        dSetSpriteScale( "Beijing", 1.2 );
    }
    if(beijin == 0) dSetSpriteScale( "Beijing", 1 );
    if(kaishi == 1)
    {
        dSetSpriteScale( "Kaishi", 1.2 );
    }
    if(kaishi == 0) dSetSpriteScale( "Kaishi", 1 );
}
void Scene5::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    if( kaishi== 1 &&iMouseType==0)
    {
        SceneState=1;
        FenShu = 0;
        HeroXueGeColour = 4;
        g_iGameState = 1;
        dStopSound( vice );
        FILE *fp;
        if((fp=fopen("score.txt","w"))!=NULL)
        {
            fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
            printf("222");
        }
        fclose(fp);
    }
    if( beijin== 1 &&iMouseType==0)
    {
       dSetSpriteVisible("caozuo",1);
    }
}
void Scene5::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene5::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

}
void Scene5::KeyUp( const int iKey )
{

}
void Scene5::SpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
void Scene5::SpriteColWorldLimit( const char *szName, const int iColSide )
{

}
