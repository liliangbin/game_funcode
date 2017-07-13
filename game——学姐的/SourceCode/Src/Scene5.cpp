#include "Scene5.h"
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
Scene5::Scene5()
{
    //ctor
}

Scene5::~Scene5()
{
    //dtor
}
void Scene5::Load()
{
    dLoadMap("Start.t2d");
}
void Scene5::GameMainLoop(float fDeltaTime )
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
void Scene5::MouseMove( float fMouseX, float fMouseY)
{
    jieshu = dIsPointInSprite( "Jieshu",fMouseX, fMouseY );
    beijin = dIsPointInSprite( "Beijing",fMouseX, fMouseY );
    kaishi = dIsPointInSprite( "Kaishi",fMouseX, fMouseY );
    if(jieshu == 1 )
    {
        dSetSpriteScale( "Jieshu", 1.2 );
    }
    if(jieshu == 0) dSetSpriteScale( "Jieshu", 1 );
    if(beijin == 1)
    {
        dSetSpriteScale( "Beijing", 1.2 );
    }
    if(beijin == 0) dSetSpriteScale( "Beijing", 1 );
    if(kaishi == 1)
    {
        dSetSpriteScale( "Kaishi", 1.2 );
    }
    if(kaishi == 0) dSetSpriteScale( "Kaishi", 1 );
}
void Scene5::MouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    if( kaishi== 1 &&iMouseType==0)
    {
        SceneState=1;
        FenShu = 0;
        HeroXueGeColour = 4;
        g_iGameState = 1;
        dStopSound( vice );
        FILE *fp;
        if((fp=fopen("score.txt","w"))!=NULL)
        {
            fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
            printf("222");
        }
        fclose(fp);
    }
    if( beijin== 1 &&iMouseType==0)
    {
       dSetSpriteVisible("caozuo",1);
    }
}
void Scene5::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
void Scene5::KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{

}
void Scene5::KeyUp( const int iKey )
{

}
void Scene5::SpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
void Scene5::SpriteColWorldLimit( const char *szName, const int iColSide )
{

}
