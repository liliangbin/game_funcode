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


//���ȫ����

extern  float		g_fScreenLeft	;    // ��Ļ��߽�ֵ
extern float		g_fScreenRight;    // ��
extern float		g_fScreenTop		;    // ��
extern float		g_fScreenBottom		;    // ��


extern float		g_fSpeedLeft		;  	// �����ٶ�
extern float		g_fSpeedRight	;  	// ��
extern float		g_fSpeedTop		;  	// ��
extern float		g_fSpeedBottom	;  	// ��


extern int ctroljump;
extern int ctrolhit;


#endif // _LESSON_X_H_
