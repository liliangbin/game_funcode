#include "Scene2.h"
#include "stdio.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Scene2::Scene2()
{
    //ctor
}

Scene2::~Scene2()
{
    //dtor
}
void Scene2::Load()
{
    dLoadMap("Dierguan.t2d");
}
void Scene2::GameMainLoop(float fDeltaTime )
{
    switch( g_iGameState )
    {
    // ��ʼ����Ϸ�������һ���������
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
    }
    break;
    // ��Ϸ�����У����������Ϸ�߼�
    case 2:
    {
        // TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
        if( true )
        {
            GameRun( fDeltaTime );
        }
        else
        {
            // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
            g_iGameState	=	0;
            GameEnd();
        }
    }
    break;

    // ��Ϸ����/�ȴ����ո����ʼ
    case 0:
    default:
        break;
    };
}
void Scene2::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Scene2::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene2::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}

void Scene2::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(strcmp(szTarName,"Door")==0 && strcmp(szSrcName,"hero")==0)
    {
        dDeleteSprite("Door");
        SceneState=3;
        g_iGameState=1;
        dStopSound( vice );
        FILE *fp;
        if((fp=fopen("score.txt","w"))!=NULL)
        {
            fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
            printf("222");
        }
        fclose(fp);
    }

    if(strstr(szTarName,"Baoxiang")!=NULL && strcmp(szSrcName,"hero")==0)
    {
        dDeleteSprite(szTarName);
        HeroXueGeColour = 4;
        dAnimateSpritePlayAnimation("XueGe","_9Animation",0);
    }
    if(strstr(szTarName,"Fire")!=NULL&&strcmp(szSrcName,"hero")==0)
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
            JustGuan=2;
            SceneState=4;
            g_iGameState=1;
            HeroXueGeColour=4;
            dStopSound( vice );

        }
    }
    if(strstr(szTarName,"Monster")!=NULL&&strcmp(szSrcName,"hero")==0)
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
            //HeroXueGeColour--;
            JustGuan=2;
            SceneState=4;
            g_iGameState=1;
            HeroXueGeColour=4;
            dStopSound( vice );

        }
    }
    if(strstr(szTarName,"MonsterBird")!=NULL&& strstr(szSrcName,"Sword")!=NULL )
    {
        dDeleteSprite(szSrcName);
        if(strstr(szTarName,"MonsterBird"))
        {
            Guai2 = Guai2 - 1;
        }

        if(Guai2 == 0)
        {
            dDeleteSprite(szTarName);
            Guai2 = 2;
            FenShu++;
        }
        dSetTextValue( "FenShu", FenShu );
    }
}

void Scene2::SpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(strstr(szName, "Monster") !=NULL)
    {
        dDeleteSprite(szName);
    }
    if(strcmp(szName, "hero")==0)
    {
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
        if(iColSide == 2 )
        {
            dSetSpriteLinearVelocityY("hero", 0);
            dSetSpritePosition("hero",dGetSpritePositionX("hero")+1,dGetSpritePositionY("hero"));
        }
        if(iColSide == 3 )
        {
            dSetSpriteLinearVelocityY("hero", 0);
            dSetSpritePosition("hero",dGetSpritePositionX("hero")-1,dGetSpritePositionY("hero"));
        }
    }
}
