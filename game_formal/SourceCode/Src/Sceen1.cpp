#include "Sceen1.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
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
    dLoadMap("sceen1.t2d");
    g_iGameState		=	1;

    printf("�����ĳ���");

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



    g_fScreenLeft	 = 	dGetScreenLeft();
    g_fScreenRight  = 	dGetScreenRight();
    g_fScreenTop 	 = 	dGetScreenTop();
    g_fScreenBottom = 	dGetScreenBottom();


    dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, -5, g_fScreenRight, g_fScreenBottom);
    dSetSpriteMass( "hero", 1);

    float speed =g_fSpeedLeft+g_fSpeedRight;

    if(speed==0)
    {
        dAnimateSpritePlayAnimation("hero","herodongtu2",0);


    }
//    else
//    {
//        dAnimateSpritePlayAnimation("hero","herodongtu2",0);
//
//    }

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
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�

void Sceen1::SpriteColWorldLimit( const char *szName, const int iColSide )
{
    printf("pengzhuang");

    if(strcmp(szName,"hero")==0)
    {

        if(iColSide==0||iColSide==1)
        {
            dSetSpriteLinearVelocityX("hero", 0);

        }

        if(iColSide==2)
        {
            dSetSpriteLinearVelocityY("hero", 3);
        }
        else if(iColSide==3)
        {
            dSetSpriteLinearVelocityY("hero", -3);
            ctroljump=1;
        }

    }

}


void Sceen1::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    head(iKey);


    if(iKey== KEY_K&&ctroljump==1)
    {

        ctroljump=0;
        dSetSpriteImpulseForce("hero",0,-160,0);

    }

};


void Sceen1::KeyUp( const int iKey )
{
    up(iKey);


//    if(iKey==KEY_A||iKey==KEY_D){
//
//        dAnimateSpritePlayAnimation("hero","herodongtu1",0);
//
//        printf("jiuishi ");
//
//
    //  }




};
