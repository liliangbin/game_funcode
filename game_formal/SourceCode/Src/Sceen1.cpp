#include "Sceen1.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
#include "math.h"
Sceen1::Sceen1()
{
    //dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft+5, -5, g_fScreenRight-5, g_fScreenBottom);


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
    //printf("�����ĳ���");

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

    dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft+5, -5, g_fScreenRight-5, g_fScreenBottom);
    dSetSpriteMass( "hero", 1);

    float speed =g_fSpeedLeft+g_fSpeedRight;

    if(speed==0&&ctrolhit==0)
    {

        dAnimateSpritePlayAnimation("hero","herodongtu2",0);

    }
    else if(ctrolhit==1&&strcmp("herodongtu3",dGetAnimateSpriteAnimationName( "hero" )))
    {
        ctrolhit=0;
        // printf("daji ");

    }


    for( int i=1; i<4; i++)
    {
        char monstername[128];
        char monsterdongtu[128];
        sprintf(monstername,"monster%d",i);
        sprintf(monsterdongtu,"monsterdongtu%d",i);

        MonsterMove(monstername,0);
//    MonsterMove("monster2",0);


        float fEndX,fEndY,mEndX,mEndY;
        fEndX=dGetSpritePositionX("hero");
        fEndY =dGetSpritePositionY("hero");
        mEndX=dGetSpritePositionX(monstername);
        mEndY=dGetSpritePositionY(monstername);
        double juli=fEndX-mEndX;

        ctroltimespace[i]=ctroltimespace[i]-fDeltaTime;

        if(fabs(juli)<3&&ctrolhit2[i]==0&&ctroltimespace[i]<1e-3)
        {


            dAnimateSpritePlayAnimation(monstername,monsterdongtu,1);
            printf("���õ�ʱ�䣺%f ���Ƶ�ʱ�䣺 %f\n",fDeltaTime,ctroltimespace);
            ctrolhit2[i]=1;
            ctroltimespace[i]=4;

            if(fabs(fEndY -mEndY)<5)
            {
                ctrolhit4++;
                dSetSpritePosition( "hero8", 0,15 );
                printf("������%d", ctrolhit4);
                blood --;//�����ʱ��ͻ��СѪ��
            }
        }

        else if(ctrolhit2[i]==1&&strcmp(monsterdongtu,dGetAnimateSpriteAnimationName(monstername )))
        {
            ctrolhit2[i]=0;


        }

    }
    int x,fangxiang;
    if( dGetSpriteLinearVelocityX( "hero" )>0)
    {

        fangxiang=1;

    }
    else if(dGetSpriteLinearVelocityX( "hero" )<0)
    {

        fangxiang=0;
    }

    x = (int)dGetSpritePositionX( "hero");
    if(20 < x && fangxiang == 1)
    {
        dSetSpriteLinearVelocityX( "background", -15.f );
        if((int)dGetSpritePositionX( "background" ) > 58|| (int)dGetSpritePositionX( "background") <= -58)
            dSetSpriteLinearVelocityX( "background", 0.f );
    }
    if(20 < x && fangxiang  == 0)
        dSetSpriteLinearVelocityX( "background", 0.f );

    if(x < -20 && fangxiang  == 0)
    {
        dSetSpriteLinearVelocityX( "background", +15.f );
        if((int)dGetSpritePositionX( "background") >= 58|| (int)dGetSpritePositionX( "background") < -58 )
        {
            dSetSpriteLinearVelocityX( "background", 0.f );
        }
    }
    if(x < -20 && fangxiang   == 1)
    {
        dSetSpriteLinearVelocityX( "background", 0.f );
    }
    if(-20 <= x && x <= 20)
    {
        dSetSpriteLinearVelocityX( "background", 0.f );
    }



    if(blood>=0)
        dSetStaticSpriteFrame( "xuege",10-blood);
    else
    {

        GameEnd();

    }



    //}

}

//==============================================================================
//
// ������Ϸ����
void	Sceen1::GameEnd()
{
    if(blood==0)
    {
        state =2;
        printf("Ѫ������");

    }
    else if (blood <0)
    {

        state =3;
        printf("��ϲ����%d",blood);

    }


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
    // printf("pengzhuang");

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
            dSetSpriteLinearVelocityY("hero", -3.5);
            ctroljump=1;
        }

    }

}


void Sceen1::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    head(iKey);


    if(iKey == KEY_K&&ctroljump==1)
    {

        ctroljump=0;
        dSetSpriteImpulseForce("hero",0,-160,0);
        //  printf("jfdfhjskd");
        ctrolhitted++;

    }

    if (iKey==KEY_J&&ctrolhit==0)
    {
        dAnimateSpritePlayAnimation("hero","herodongtu3",1);
        ctrolhit=1;
        for(int j=1; j<4; j++)
        {
            char monstername[128];
            sprintf(monstername,"monster%d",j);

            float fEndX,fEndY,mEndX,mEndY;
            fEndX=dGetSpritePositionX("hero");
            fEndY =dGetSpritePositionY("hero");
            mEndX=dGetSpritePositionX(monstername);
            mEndY = dGetSpritePositionY(monstername);
            double julix=fabs(fEndX)-fabs(mEndX);
            double juliy=fabs(fEndY)-fabs(mEndY);

            printf("y��ľ���%f  x�����%f   Ӣ�۵�λ�� %f Ӣ�۵�y�� %f, mendx %f  mendy %f\n",juliy,juliy,fEndX,fEndY,mEndX,mEndY);

            if(fabs(julix)<5&&fabs(juliy)<10)
            {

                ctrolhit3[j]++;
                if(ctrolhit3[j]==3)
                {

                    dSetSpriteColorAlpha(monstername, 140 );
                    dSetSpriteLifeTime(monstername, 2);
                    score +=10;
                    dSetTextValue("score", score );


                }



            };
        };
    };




};


void Sceen1::KeyUp( const int iKey )
{
    up(iKey);




    if(iKey==KEY_D&&dGetSpritePositionX( "hero" )>25)
    {

        dSetSpriteLinearVelocityX( "background", 0 );
    }

    if(iKey==KEY_A&&dGetSpritePositionX( "hero" )<25)
    {

        dSetSpriteLinearVelocityX( "background", 0 );
    }
};
