#include "Scene3.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Scene3::Scene3()
{
    //ctor
}

Scene3::~Scene3()
{
    //dtor
}
void Scene3::Load()
{
    dLoadMap("Disanguan.t2d");
}
void Scene3::GameMainLoop(float fDeltaTime )
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
void Scene3::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Scene3::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene3::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene3::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(strcmp(szTarName,"boss")==0&&strcmp(szSrcName,"hero")==0)
    {
        SceneState=4;
        g_iGameState=1;
        JustGuan=3;
        dStopSound( vice );

    }
    if(strstr(szTarName,"Cannon")!=NULL&&strcmp(szSrcName,"hero")==0)
    {
        dDeleteSprite(szTarName);
        HeroXueGeColour=HeroXueGeColour-1;
        if(HeroXueGeColour==3)
        {
            dAnimateSpritePlayAnimation("XueGe","_8Animation",0);
        }
        if(HeroXueGeColour==2)
        {
            dAnimateSpritePlayAnimation("XueGe","_7Animation",0);
        }
        if(HeroXueGeColour==1)
        {
            dAnimateSpritePlayAnimation("XueGe","_6Animation",0);
        }
        if(HeroXueGeColour==0)
        {
            dAnimateSpritePlayAnimation("XueGe","_5Animation",0);
            JustGuan=3;
            SceneState=4;
            g_iGameState=1;
            HeroXueGeColour=4;
            dStopSound( vice );

        }
    }
    if(strcmp(szTarName,"boss")==0&&strstr(szSrcName,"Sword")!=NULL)
    {
        dDeleteSprite(szSrcName);
        BossXueGeColour--;
        if(BossXueGeColour==30)
        {
            dAnimateSpritePlayAnimation("XueGeYou","_8_youAnimation",0);
        }
        if(BossXueGeColour==20)
        {
            dAnimateSpritePlayAnimation("XueGeYou","_7_youAnimation",0);
        }
        if(BossXueGeColour==10)
        {
            dAnimateSpritePlayAnimation("XueGeYou","_6_youAnimation",0);
        }
        if(BossXueGeColour==0)
        {
            dAnimateSpritePlayAnimation("XueGeYou","_5_youAnimation",0);
        }
        FenShu ++;
        dSetTextValue( "FenShu", FenShu );
    }
}
void Scene3::SpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(strstr(szName,"Cannon") != NULL) dDeleteSprite(szName);
    if(iColSide == 1||iColSide==0)
        {
            if(iColSide == 1)
            {
                dSetSpriteLinearVelocityX("hero", 0);
                dSetSpritePosition("hero",dGetSpritePositionX("hero")-1,dGetSpritePositionY("hero"));
            }
            if(iColSide == 0 )
            {
                dSetSpriteLinearVelocityX("hero", 0);
                dSetSpritePosition("hero",dGetSpritePositionX("hero")+1,dGetSpritePositionY("hero"));
            }

        }
        if(iColSide == 2 || iColSide == 3 )
        {
            dSetSpriteLinearVelocityY("hero", 0);
        }
    }
