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
#include "scene.h"
extern int			g_iGameState;
extern int          i,iCannon,iMonster,Guai1 ,Guai2 ,Guai3 ,Guai4 ;
extern int          WeightFlag;
extern int          SceneState;
extern int          an ,a,Guanka,Yinyue,jieshu, beijin,kaishi,Continue ,FenShu,Back,JustGuan;
extern int          vice;
extern float		g_fScreenLeft	;    // 屏幕左边界值
extern float		g_fScreenRight	;    // 右
extern float		g_fScreenTop;    // 上
extern float		g_fScreenBottom	;    // 下
extern bool		    bHeroFlipX;      	// 是否翻转图片

extern float		g_fHeroSpeedLeft;     // 水平方向速度
extern float		g_fHeroSpeedRight;
extern float		g_fHeroSpeedTop;
extern float		g_fHeroSpeedBottom;
extern void	GameMainLoop( float	fDeltaTime );
extern void	GameInit();
extern void	GameRun( float fDeltaTime );
extern void	GameEnd();
extern void Swimming();
extern void Tiao();
extern void   CloneSword(int i);
extern void  MonsterMove(int iMonster);
extern void  MonsterAppear(const char* Name ,const char*  shishi);
extern float fCurrentTime[9],CannonTime;
extern int HeroXueGeColour,BossXueGeColour;
extern Scene *b[7];
extern float	fTimeDelta;
#endif // _LESSON_X_H_
