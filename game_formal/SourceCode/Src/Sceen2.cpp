#include "Sceen2.h"
#include "CommonAPI.h"
#include "LessonX.h"
Sceen2::Sceen2()
{
    //ctor
}

Sceen2::~Sceen2()
{
    //dtor
}


//��ʼ��������������ط�
// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();


void Sceen2::Load()
{
    dLoadMap("leve3.t2d");
    g_iGameState		=	0;
}


void Sceen2::MainLoop( float	fDeltaTime )
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
void	Sceen2::GameInit()
{


}
//==============================================================================
//
// ÿ����Ϸ������
void	Sceen2::GameRun( float fDeltaTime )
{
}
//==============================================================================
//
// ������Ϸ����
void	Sceen2::GameEnd()
{
}

void Sceen2::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Sceen2::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Sceen2::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}

void Sceen2::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
}

void Sceen2::SpriteColWorldLimit( const char *szName, const int iColSide )
{


}


void Sceen2::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

};
void Sceen2::KeyUp( const int iKey )
{

};
