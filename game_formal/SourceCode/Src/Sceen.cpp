#include "Sceen.h"
#include "CommonAPI.h"
#include "stdio.h"
#include "LessonX.h"
Sceen::Sceen()
{
    //ctor
}
Sceen::~Sceen()
{
    //dtor
}
//��ʼ��������������ط�
// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();



void Sceen::Load()
{
    dLoadMap("level1.t2d");
    g_iGameState		=	1;

    printf("�����ĳ���");
}



void Sceen::MainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // ��ʼ����Ϸ�������һ���������
    case 1:
    {
        GameInit();
        printf("game kaishi");
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
void	Sceen::GameInit()
{


}
//==============================================================================
//
// ÿ����Ϸ������
void	Sceen::GameRun( float fDeltaTime )
{


}
//==============================================================================
//
// ������Ϸ����
void	Sceen::GameEnd()
{
}

void Sceen::MouseMove( const float fMouseX, const float fMouseY )
{



}
void Sceen::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{


state =1 ;
// b[state]->Load();

}
void Sceen::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{



}

void Sceen::SpriteColSprite( const char *szSrcName, const char *szTarName )
{


}

void Sceen::SpriteColWorldLimit( const char *szName, const int iColSide )
{


}


void Sceen::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

};
void Sceen::KeyUp( const int iKey )
{

};
