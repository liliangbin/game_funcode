//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include "Sceen.h"
#include "Sceen1.h"
#include "stdio.h"


//int state = 0;
//Sceen  *b[4] = {new Sceen,new Sceen,new Sceen,new Sceen};
//
//int  g_iGameState = 0;
int name=0;
int test=-1;


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

    // ������ѭ����������Ļͼ��ˢ�µȹ���
    while( dEngineMainLoop() )
    {
        // ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
        float	fTimeDelta	=	dGetTimeDelta();

        // ִ����Ϸ��ѭ��
if(test!=state){

     b[state]->Load();

     test =state;

}

        b[state]->MainLoop( fTimeDelta );


        if(state==0&&name==0){

            printf("changjing");
            name=1;
        }

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
    // �����ڴ������Ϸ��Ҫ����Ӧ����
    b[state]->MouseMove( fMouseX,  fMouseY );
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����

    b[state]->MouseClick( iMouseType,  fMouseX, fMouseY );

}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����
    b[state]->MouseUp(  iMouseType,  fMouseX,  fMouseY );
}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// iAltPress iShiftPress iCtrlPress �ֱ�Ϊ�ж�Shift��Alt��Ctrl��ǰ�Ƿ�Ҳ���ڰ���״̬����������ж�Ctrl+E��ϼ�
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����
    b[state]->KeyDown(  iKey,  iAltPress,  iShiftPress,  iCtrlPress );
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void dOnKeyUp( const int iKey )
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����
    b[state]->KeyUp( iKey );




}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{


b[state]->SpriteColSprite( szSrcName,  szTarName );
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�


void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{


    b[state]->SpriteColWorldLimit(  szName,  iColSide );
    printf("name");



}






