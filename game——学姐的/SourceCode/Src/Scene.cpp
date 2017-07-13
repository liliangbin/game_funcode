#include "Scene.h"
#include "CommonAPI.h"
#include "stdio.h"
#include "LessonX.h"
Scene::Scene()
{
    //ctor
}

Scene::~Scene()
{
    //dtor
}
void Scene::Load()
{
}
void Scene::GameMainLoop(float fDeltaTime )
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

void Scene::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Scene::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    switch(iKey)
    {
    case KEY_W:
        dAnimateSpritePlayAnimation("hero","peopleAnimation",1);
        g_fHeroSpeedTop = -50.f;
        break;
    case KEY_A:
        dAnimateSpritePlayAnimation("hero","peopleAnimation",1);
        g_fHeroSpeedLeft = -50.f;
        a = 1;
        break;
    case KEY_S:
        dAnimateSpritePlayAnimation("hero","peopleAnimation",1);
        g_fHeroSpeedBottom = 50.f;
        break;
    case KEY_D:
        dAnimateSpritePlayAnimation("hero","peopleAnimation",1);
        g_fHeroSpeedRight = 50.f;
        an = 1;
        break;
    case KEY_SPACE:
        i=i+1;
        CloneSword(i);
        break;
    case KEY_J:
        WeightFlag=1;
        Tiao();
        break;
    default:
        break;
    }
    Swimming();
}

void Scene::KeyUp( const int iKey )
{
    switch(iKey)
    {
    case KEY_W:
        g_fHeroSpeedTop = 0.f;
        break;
    case KEY_A:
        g_fHeroSpeedLeft = 0.f;
        a = 0;
        break;
    case KEY_S:
        g_fHeroSpeedBottom = 0.f;
        break;
    case KEY_D:
        g_fHeroSpeedRight = 0.f;
        an = 0;
        break;
    case KEY_J:
        WeightFlag=2;
        Tiao();
        break;
    default:
        break;
    }
    Swimming();
}


void Scene::SpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
void Scene::SpriteColWorldLimit( const char *szName, const int iColSide )
{

}
