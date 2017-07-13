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
