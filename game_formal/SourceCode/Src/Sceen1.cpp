#include "Sceen1.h"
#include "CommonAPI.h"
#include "LessonX.h"
Sceen1::Sceen1()
{
    //ctor
}

Sceen1::~Sceen1()
{
    //dtor
}


//��ʼ��������������ط�
   		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//

void Sceen1::Load()
{
    dLoadMap("leve2.t2d");
     g_iGameState		=	0;
}


void Sceen1::MainLoop( float	fDeltaTime )
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
void	Sceen1::GameInit()
{


}
//==============================================================================
//
// ÿ����Ϸ������
void	Sceen1::GameRun( float fDeltaTime )
{
}
//==============================================================================
//
// ������Ϸ����
void	Sceen1::GameEnd()
{
}

void Sceen1::MouseMove( const float fMouseX, const float fMouseY )
{

}
void Sceen1::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Sceen1::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}

void Sceen1::SpriteColSprite( const char *szSrcName, const char *szTarName )
{
}

void Sceen1::SpriteColWorldLimit( const char *szName, const int iColSide )
{


}


void Sceen1::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

};
void Sceen1::KeyUp( const int iKey )
{

};
