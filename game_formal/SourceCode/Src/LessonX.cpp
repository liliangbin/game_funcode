/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
#include "Sceen.h"
#include "Sceen1.h"
#include "Sceen2.h"
#include "Sceen3.h"
////////////////////////////////////////////////////////////////////////////////
//
//全部变量定义的位置
int state = 0;
Sceen  *b[4] = {new Sceen,new Sceen1,new Sceen2,new Sceen3};
int g_iGameState = 0;

float transposition = 0.f;

float		g_fScreenLeft		=	0.f;    // 屏幕左边界值
float		g_fScreenRight	=	0.f;    // 右
float		g_fScreenTop		=	0.f;    // 上
float		g_fScreenBottom	=	0.f;    // 下


float		g_fSpeedLeft		=	0.f;  	// 左方向速度
float		g_fSpeedRight		=	0.f;  	// 右
float		g_fSpeedTop		=	0.f;  	// 上
float		g_fSpeedBottom	=	0.f;  	// 下

int  ctroljump=0;


int ctrolhit=0,ctrolhit4=0,ctrolhitted=0;

int ctrolhit3[5]={0},ctrolhit2[5]={0};
int blood=10;
double   ctroltimespace[5]={4,4,4,4,4},monsterdie=0;

char *Name;


int monstergo = 0,score=0 ;

float monsterappeartime = 0.f;

void up(const int iKey)
{

    if(dGetSpritePositionX("hero")>-28.f||dGetSpritePositionY("hero")<28.f)
    {

        switch(iKey)
        {

        case KEY_A:
            g_fSpeedLeft = 0.f;
            break;

        case KEY_D:
            g_fSpeedRight = 0.f;
            break;
        }
    }


    else
    {

        g_fSpeedLeft = 0.f;
        g_fSpeedRight = 0.f;

    }
    dSetSpriteLinearVelocity("hero", g_fSpeedLeft + g_fSpeedRight,0);
    if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
        dSetSpriteFlipX("hero", false);
    else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
        dSetSpriteFlipX("hero", true);
}

void  head(const int iKey)
{

    switch(iKey)
    {

    case KEY_A:
        g_fSpeedLeft = -15.f;
        break;

    case KEY_D:
        g_fSpeedRight = 15.f;
        break;
    }


    if(dGetSpritePositionX("hero")>28.f)
    {
        //   printf("%f     ",dGetSpritePositionX("renwu") );

        if (iKey==KEY_A)
        {
            g_fSpeedLeft=-15.f;
        }

        if(iKey==KEY_D)
        {

            g_fSpeedRight =0.f;

        }
    }

    if(dGetSpritePositionX("hero")<-28.f)
    {
        // printf("%f     ",dGetSpritePositionX("renwu") );

        if (iKey==KEY_A)
        {
            g_fSpeedLeft=0.f;
        }

        if(iKey==KEY_D)
        {

            g_fSpeedRight =15.f;

        }
    }
    dSetSpriteLinearVelocity("hero", g_fSpeedLeft + g_fSpeedRight, 0);
    if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
        dSetSpriteFlipX("hero", false);
    else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
        dSetSpriteFlipX("hero", true);

}

void swim( const char * monstername)
{

//    dSetSpriteLinearVelocity("hero", g_fSpeedLeft + g_fSpeedRight, 0);
    if(dGetSpriteLinearVelocityX( monstername )> 0.f)
        dSetSpriteFlipX(monstername,false );
    else if(dGetSpriteLinearVelocityX( monstername ) < 0.f)
        dSetSpriteFlipX(monstername, true);


}

void MonsterMove(const char* Name,float  i)
{
    //dCalLineRotation：计算两点连线的直线的旋转角度
// 返回值：角度，范围0 - 360
    float fEndX,fEndY,monsterweiyi;
    fEndX=dGetSpritePositionX("hero");
    fEndY=dGetSpritePositionY("hero");
      if(dGetSpriteLinearVelocityX( Name )> 0.f){


        monsterweiyi=0;

      }
      else {

         monsterweiyi=0;
      }
    dSpriteMoveTo(Name,fEndX-i*5+monsterweiyi,26,8,false);

    swim(Name);


//    if(dGetSpriteLinearVelocityX(Name )> 0.f){
//
//        dSetSpriteFlipX(Name, true);
//    }
//
//    else if(dGetSpriteLinearVelocityX(Name ) < 0.f)
//        dSetSpriteFlipX(Name, false);


}



//
//void MonsterAppear( const char* Name ,const char*  shishi ,float X, float Y)
//{
//    char  szName[128];
//    sprintf(szName,shishi,iMonster);
//    iMonster++;
//    dCloneSprite(Name, szName);
//    dSetSpritePosition(szName, X, Y);
//    dSetSpriteCollisionReceive(szName, 1);
//    dSetSpriteWorldLimit(szName,  WORLD_LIMIT_NULL,  g_fScreenLeft - 200, g_fScreenTop, g_fScreenRight + 200,   g_fScreenBottom + 70);
//    MonsterMove(szName);
//}
//
