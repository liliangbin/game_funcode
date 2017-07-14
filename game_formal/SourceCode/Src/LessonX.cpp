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


int ctrolhit=0;

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

