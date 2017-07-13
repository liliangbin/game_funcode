//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
#include "scene.h"
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"
#include "scene5.h"
#include "scene6.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
    // ��ʼ����Ϸ����
    if( !dInitGameEngine( hInstance, lpCmdLine ) )
        return 0;

    // To do : �ڴ�ʹ��API���Ĵ��ڱ���
    dSetWindowTitle("Lesson");
    g_fScreenLeft	 = 	dGetScreenLeft();
    g_fScreenRight   = 	dGetScreenRight();
    g_fScreenTop 	 = 	dGetScreenTop();
    g_fScreenBottom  = 	dGetScreenBottom();

    // ������ѭ����������Ļͼ��ˢ�µȹ���
    while( dEngineMainLoop() )
    {
        // ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
         fTimeDelta	=	dGetTimeDelta();
        // ִ����Ϸ��ѭ��
        if(SceneState==1&&FenShu>=10)
        {
            SceneState=2;
            g_iGameState=1;
            dStopSound( vice );
            FILE *fp;
            if((fp=fopen("score.txt","w"))!=NULL)
            {
                fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
                printf("0000");
            }
            fclose(fp);
        }
        b[SceneState]->GameMainLoop( fTimeDelta );
    };

    // �ر���Ϸ����
    dShutdownGameEngine();
    return 0;
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
    b[SceneState]->MouseMove( fMouseX, fMouseY);
    // �����ڴ������Ϸ��Ҫ����Ӧ����
    //��괥��ѡ�
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    b[SceneState]->MouseClick( iMouseType, fMouseX,  fMouseY );
    // �����ڴ������Ϸ��Ҫ����Ӧ����
}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    b[SceneState]->MouseUp( iMouseType,  fMouseX,  fMouseY );
    // �����ڴ������Ϸ��Ҫ����Ӧ����
}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// iAltPress iShiftPress iCtrlPress �ֱ�Ϊ�ж�Shift��Alt��Ctrl��ǰ�Ƿ�Ҳ���ڰ���״̬����������ж�Ctrl+E��ϼ�
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    b[SceneState]->KeyDown(  iKey,  iAltPress,  iShiftPress,  iCtrlPress );
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void dOnKeyUp( const int iKey )
{
    b[SceneState]->KeyUp( iKey );
}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    b[SceneState]->SpriteColSprite( szSrcName,  szTarName );
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    b[SceneState]->SpriteColWorldLimit(szName,iColSide);
}
