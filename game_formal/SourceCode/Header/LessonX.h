/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "Sceen.h"

extern int state;
extern Sceen  *b[4];
extern int  g_iGameState ;

extern void up(const int iKey);
extern  void  head(const int iKey);


//添加全变量

extern  float		g_fScreenLeft	;    // 屏幕左边界值
extern float		g_fScreenRight;    // 右
extern float		g_fScreenTop		;    // 上
extern float		g_fScreenBottom		;    // 下


extern float		g_fSpeedLeft		;  	// 左方向速度
extern float		g_fSpeedRight	;  	// 右
extern float		g_fSpeedTop		;  	// 上
extern float		g_fSpeedBottom	;  	// 下


extern int ctroljump;
extern int ctrolhit,ctrolhit2[5],ctrolhit3[5],ctrolhit4,ctrolhitted;
extern  double  ctroltimespace[5],monsterdie;
extern  char * Name;
extern void   MonsterMove(const char* Namer,float i);

extern int   monstergo,score;

extern  float  monsterappeartime;
extern  int blood;

extern void swim(const char * monstername);
#endif // _LESSON_X_H_
