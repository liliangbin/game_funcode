#include "Sceen3.h"
#include "CommonAPI.h"
#include "LessonX.h"
Sceen3::Sceen3()
{
    //ctor
}

Sceen3::~Sceen3()
{
    //dtor
}
//��ʼ��������������ط�
// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();


void Sceen3::Load()
{
    dLoadMap("level.t2d");
    g_iGameState		=	0;
}


void Sceen3::MainLoop( float	fDeltaTime )
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

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void	Sceen3::GameInit()
{


}
//==============================================================================
//
// ÿ����Ϸ������
void	Sceen3::GameRun( float fDeltaTime )
{
}
//==============================================================================
//
// ������Ϸ����
void	Sceen3::GameEnd()
{
}

void Sceen3::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Sceen3::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Sceen3::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}

void Sceen3::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
}

void Sceen3::SpriteColWorldLimit( const char *szName, const int iColSide )
{


}


void Sceen3::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

};
void Sceen3::KeyUp( const int iKey )
{

};
