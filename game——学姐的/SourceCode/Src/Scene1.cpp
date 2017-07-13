#include "Scene1.h"
#include "stdio.h"
#include "CommonAPI.h"
#include "LessonX.h"
Scene1::Scene1()
{
    //ctor
}

Scene1::~Scene1()
{
    //dtor
}
void Scene1::Load()
{
    dLoadMap("Diyiguan.t2d");
}
void Scene1::GameMainLoop(float fDeltaTime )
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
void Scene1::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Scene1::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene1::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}

void Scene1::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(strstr(szTarName,"Monster")!=NULL&& strstr(szSrcName,"Sword")!=NULL )
    {
        dDeleteSprite(szSrcName);
        if(strstr(szTarName,"MonsterC"))
        {
            Guai1--;
        }
        if(strstr(szTarName,"MonsterBird"))
        {
            Guai2 = Guai2 - 1;
        }
        if(strstr(szTarName,"MonsterA"))
        {
            Guai3 = Guai3 - 1;
        }
        if(strstr(szTarName,"MonsterB"))
        {
            Guai4 = Guai4 - 1;
        }
        if(Guai1 == 0)
        {
            dDeleteSprite(szTarName);
            Guai1 = 1;
            FenShu++;
        }
        if(Guai2 == 0)
        {
            dDeleteSprite(szTarName);
            Guai2 = 2;
            FenShu++;
        }
        if(Guai3 == 0)
        {
            dDeleteSprite(szTarName);
            Guai3 = 3;
            FenShu++;
        }
        if(Guai4 == 0)
        {
            dDeleteSprite(szTarName);
            Guai4 = 4;
            FenShu++;
        }
        dSetTextValue( "FenShu", FenShu );
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
            JustGuan=1;
            SceneState=4;
            g_iGameState=1;
            HeroXueGeColour=4;
            dStopSound( vice );
        }
    }
}


void Scene1::SpriteColWorldLimit( const char *szName, const int iColSide )
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
            dSetSpritePosition("hero",dGetSpritePositionX("hero"),dGetSpritePositionY("hero")+1);
        }
        if(iColSide == 3 )
        {
            dSetSpriteLinearVelocityY("hero", 0);
            dSetSpritePosition("hero",dGetSpritePositionX("hero"),dGetSpritePositionY("hero")-1);
        }
    }
}
