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
