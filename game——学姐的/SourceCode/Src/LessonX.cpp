/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
#include "Stdio.h"
#include "scene.h"
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"
#include "scene5.h"
#include "scene6.h"
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState=1;		// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中
int         an=0,a=0,i=0,iCannon,iMonster=1,Guai1 = 1,Guai2 = 2,Guai3 = 3,Guai4 = 4;
int         WeightFlag=0;
int         SceneState=5;
int         Guanka=0,Yinyue=0,jieshu=0, beijin=0,kaishi=0,Continue=0 ,FenShu=0,Back=0,JustGuan=0;
int         vice;
void		GameInit();     //方法
void		GameRun( float fDeltaTime );        //方法
void		GameEnd();      //方法
void        Swimming();     //方法
void        Tiao(int WeightFlag);//方法
float		g_fScreenLeft		=	0.f;    // 屏幕左边界值
float		g_fScreenRight	=	0.f;    // 右
float		g_fScreenTop		=	0.f;    // 上
float		g_fScreenBottom	=	0.f;    // 下
bool		bHeroFlipX=true;      	// 是否翻转图片
float		g_fHeroSpeedLeft=0.f;     // 水平方向速度
float		g_fHeroSpeedRight=0.f;
float		g_fHeroSpeedTop=0.f;
float		g_fHeroSpeedBottom=0.f;
void        CloneSword(int i);       //方法
void        MonsterMove(const char* Name);//方法
void        MonsterAppear(const char* Name ,const char*  shishi);//方法
float       fCurrentTime[9]= {2,2,2,2,2,2,2,2,2};
int       HeroXueGeColour=4,BossXueGeColour=8;
Scene       *b[7]= {new Scene(),new Scene1(),new Scene2(),new Scene3(),new Scene4(),new Scene5(),new Scene6()};
float	    fTimeDelta,CannonTime;
float       fPosX,fPosY;
//=========================,=====================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。


//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void Swimming()
{
    if((g_fHeroSpeedLeft + g_fHeroSpeedRight) > 0)
        dSetSpriteFlipX("hero", true);
    else if((g_fHeroSpeedLeft + g_fHeroSpeedRight) < 0)
        dSetSpriteFlipX("hero", false);
    dSetSpriteLinearVelocity("hero", g_fHeroSpeedLeft + g_fHeroSpeedRight, g_fHeroSpeedTop +g_fHeroSpeedBottom);
}

void Tiao()
{
    if(WeightFlag==0)
    {
        g_fHeroSpeedBottom = 0;
        dSetSpriteLinearVelocityY("hero", 0);
        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop+30, g_fScreenRight, g_fScreenBottom);

    }
    if(WeightFlag==1)
    {
        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop+15, g_fScreenRight, g_fScreenBottom);
        dAnimateSpritePlayAnimation("hero","tiaoAnimation",0);
        g_fHeroSpeedTop=-30.f;
    }
    if(WeightFlag==2)
    {
        g_fHeroSpeedTop = 0.f;
        g_fHeroSpeedBottom = 60.f;
        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom-10);
    }
}


void MonsterMove(const char* Name)
{
    //dCalLineRotation：计算两点连线的直线的旋转角度
// 返回值：角度，范围0 - 360
    float fEndX,fEndY;
    fEndX=dGetSpritePositionX("hero");
    fEndY=dGetSpritePositionY("hero");
    dSpriteMoveTo(Name,fEndX,fEndY,10,false);
}

void CloneSword(int i)
{
    char  szName[128];
    float fPosX, fPosY;
    sprintf(szName, "Sword%d", i);
    dCloneSprite("Sword", szName);
    dSetSpriteCollisionSend(szName, 1);
    fPosX=dGetSpriteLinkPointPosX("hero",1);
    fPosY=dGetSpriteLinkPointPosY("hero",1);
    dSetSpritePosition(szName, fPosX, fPosY);
    if(dGetSpriteFlipX("hero"))
    {
        dSetSpriteLinearVelocity(szName, 50, 0);
    }
    else
    {
        dSetSpriteLinearVelocity(szName, -50, 0);
    }
}

void MonsterAppear( const char* Name ,const char*  shishi ,float X, float Y)
{
    char  szName[128];
    sprintf(szName,shishi,iMonster);
    iMonster++;
    dCloneSprite(Name, szName);
    dSetSpritePosition(szName, X, Y);
    dSetSpriteCollisionReceive(szName, 1);
    dSetSpriteWorldLimit(szName,  WORLD_LIMIT_NULL,  g_fScreenLeft - 200, g_fScreenTop, g_fScreenRight + 200,   g_fScreenBottom + 70);
    MonsterMove(szName);
}

void CannonAppear(int iCannon)
{
    char  szName[128];
    float fPosX, fPosY;
    sprintf(szName, "Cannon%d", iCannon);
    dCloneSprite("Cannon", szName);
    dSetSpriteCollisionReceive(szName, 1);
    dSetSpriteWorldLimit(szName,  WORLD_LIMIT_NULL,  g_fScreenLeft , g_fScreenTop, g_fScreenRight ,   g_fScreenBottom );
    fPosX=dGetSpriteLinkPointPosX("boss",1);
    fPosY=dGetSpriteLinkPointPosY("boss",1);
    dSetSpritePosition(szName, fPosX, fPosY);
    float fEndX,fEndY;
    fEndX=dGetSpritePositionX("hero");
    fEndY=dGetSpritePositionY("hero");
    dSpriteMoveTo(szName,fEndX,fEndY,20,false);
}

void	GameInit()
{
    if(SceneState==1)
    {
        vice = dPlaySound("G1.wav", 1, 1 );
        b[SceneState]->Load();
        FILE *fp;
        if((fp=fopen("score.txt","r"))!=NULL)
        {
            fscanf(fp,"%d %d",&HeroXueGeColour,&FenShu);
        }
        fclose(fp);
        dSetTextValue( "FenShu", FenShu );
        if(HeroXueGeColour==3)
        {
            dAnimateSpritePlayAnimation("XueGe","_8Animation",0);
        }
        if(HeroXueGeColour==2)
        {
            dAnimateSpritePlayAnimation("XueGe","_7Animation",0);
        }
        if(HeroXueGeColour==1)
        {
            dAnimateSpritePlayAnimation("XueGe","_6Animation",0);
        }

        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft + 20 , g_fScreenTop+30, g_fScreenRight -20, g_fScreenBottom);
        HeroXueGeColour=4;
        FenShu=0;
        dSetSpriteCollisionSend("hero", 1);
    }
    if(SceneState==2)
    {
        vice = dPlaySound("G2.wav", 1, 1 );
        b[SceneState]->Load();
        FILE *fp;
        if((fp=fopen("score.txt","r"))!=NULL)
        {
            fscanf(fp,"%d %d",&HeroXueGeColour,&FenShu);
            printf("dddddd");
        }
        fclose(fp);
        dSetTextValue( "FenShu", FenShu );
        if(HeroXueGeColour==3)
        {
            dAnimateSpritePlayAnimation("XueGe","_8Animation",0);
        }
        if(HeroXueGeColour==2)
        {
            dAnimateSpritePlayAnimation("XueGe","_7Animation",0);
        }
        if(HeroXueGeColour==1)
        {
            dAnimateSpritePlayAnimation("XueGe","_6Animation",0);
        }

        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft + 20, g_fScreenTop+30, g_fScreenRight - 20 , g_fScreenBottom);
        dSetSpriteCollisionReceive("Door", 1);
        dSetSpriteCollisionSend("hero", 1);

    }
    if(SceneState==3)
    {

        vice = dPlaySound("G3.wav", 1, 1 );
        b[SceneState]->Load();
        FILE *fp;
        if((fp=fopen("score.txt","r"))!=NULL)
        {
            fscanf(fp,"%d %d",&HeroXueGeColour,&FenShu);
        }
        fclose(fp);
        dSetTextValue( "FenShu", FenShu );
        if(HeroXueGeColour==3)
        {
            dAnimateSpritePlayAnimation("XueGe","_8Animation",0);
        }
        if(HeroXueGeColour==2)
        {
            dAnimateSpritePlayAnimation("XueGe","_7Animation",0);
        }
        if(HeroXueGeColour==1)
        {
            dAnimateSpritePlayAnimation("XueGe","_6Animation",0);
        }

        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop + 20, g_fScreenRight, g_fScreenBottom);
        dSetSpriteWorldLimit("boss", WORLD_LIMIT_NULL, g_fScreenLeft - 70, g_fScreenTop - 70, g_fScreenRight + 70, g_fScreenBottom + 70);
        CannonTime=1;
        printf("23");
        iCannon=0;
        BossXueGeColour=40;
        dSetSpriteCollisionReceive("boss", 1);
        dSetSpriteCollisionSend("hero", 1);
    }
    if(SceneState==4)
    {
        vice = dPlaySound("G4.wav", 1, 1 );
        b[SceneState]->Load();
        /*if(HeroXueGeColour==3)
        {
            dAnimateSpritePlayAnimation("XueGe","_8Animation",0);
        }
        if(HeroXueGeColour==2)
        {
            dAnimateSpritePlayAnimation("XueGe","_7Animation",0);
        }
        if(HeroXueGeColour==1)
        {
            dAnimateSpritePlayAnimation("XueGe","_6Animation",0);
        }*/

        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop+30, g_fScreenRight, g_fScreenBottom);
    }
    if(SceneState==5)
    {
        vice = dPlaySound("G5.wav", 1, 1 );
        b[SceneState]->Load();
        dSetSpriteVisible("caozuo",0);
        dSetSpriteWorldLimit("hero", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop+30, g_fScreenRight, g_fScreenBottom);
        dAnimateSpritePlayAnimation("hero","peopleAnimation",1);
        dAnimateSpritePlayAnimation("boss","Wang1Animation",1);
        dSetSpriteCollisionSend("hero", 1);
    }
    if(SceneState==6)
    {
        vice = dPlaySound("G6.wav", 1, 1 );
        b[SceneState]->Load();
        dSetSpriteVisible("justsoso",0);
        dSetSpriteVisible("congratulation",0);
        dSetSpriteVisible("good",0);

        FILE *fp;
        if((fp=fopen("score.txt","r"))!=NULL)
        {
            fscanf(fp,"%d %d",&HeroXueGeColour,&FenShu);
        }
        fclose(fp);
        dSetTextValue( "FenShu", FenShu );
    }
}
//==============================================================================
//
// 每局游戏进行中
void	GameRun( float fDeltaTime )
{
    if(SceneState==1)
    {
        int x;
        x = (int)dGetSpritePositionX( "hero");
        if(20 < x && an == 1)
        {
            dSetSpriteLinearVelocityX( "Beijin2", -40.f );
            if((int)dGetSpritePositionX( "Beijin2" ) > 70|| (int)dGetSpritePositionX( "Beijin2") <= -69 )  dSetSpriteLinearVelocityX( "Beijin2", 0.f );
        }
        if(20 < x && an == 0) dSetSpriteLinearVelocityX( "Beijin2", 0.f );
        if(x < -20 && a == 1)
        {
            dSetSpriteLinearVelocityX( "Beijin2", +40.f );
            if((int)dGetSpritePositionX( "Beijin2" ) >= 70|| (int)dGetSpritePositionX( "Beijin2") < -69 )  dSetSpriteLinearVelocityX( "Beijin2", 0.f );
        }
        if(x < -20 && a  == 0) dSetSpriteLinearVelocityX( "Beijin2", 0.f );
        if(-20 <= x && x <= 20) dSetSpriteLinearVelocityX( "Beijin2", 0.f );

        fCurrentTime[0] = fCurrentTime[0] - fDeltaTime;
        if(fCurrentTime[0] < 1e-7)
        {
            fPosX = dGetSpriteLinkPointPosX( "Beijin2", 1);
            fPosY =  dGetSpriteLinkPointPosY( "Beijin2", 1);
            MonsterAppear("MonsterC","MonsterC%d",fPosX,fPosY);
            fCurrentTime[0] = 1.7f;
        }
        fCurrentTime[1] = fCurrentTime[1] - fDeltaTime;
        if(fCurrentTime[1] < 1e-7)
        {
            fPosX = dGetSpriteLinkPointPosX( "Beijin2",2);
            fPosY =  dGetSpriteLinkPointPosY( "Beijin2", 2);
            MonsterAppear("MonsterBird","MonsterBird%d",fPosX,fPosY);
            fCurrentTime[1] = 1.7f;

        }
        fCurrentTime[2] = fCurrentTime[2] - fDeltaTime;
        if(fCurrentTime[2] < 1e-7)
        {
            fPosX = dGetSpriteLinkPointPosX( "Beijin2",3);
            fPosY =  dGetSpriteLinkPointPosY( "Beijin2", 3);
            MonsterAppear("MonsterA","MonsterA%d",fPosX,fPosY);
            fCurrentTime[2] = 1.7f;
        }
        fCurrentTime[3] = fCurrentTime[3] - fDeltaTime;
        if(fCurrentTime[3] < 1e-7)
        {
            fPosX = dGetSpriteLinkPointPosX( "Beijin2",4);
            fPosY =  dGetSpriteLinkPointPosY( "Beijin2", 4);
            MonsterAppear("MonsterB","MonsterB%d",fPosX,fPosY);
            fCurrentTime[3] = 1.7f;
        }
    }
    if(SceneState == 2 )
    {
        int x;
        x = (int)dGetSpritePositionX( "hero");
        if(20 < x && an == 1)
        {
            dSetSpriteLinearVelocityX( "Beijin3", -40.f );
            if((int)dGetSpritePositionX( "Beijin3" ) > 70|| (int)dGetSpritePositionX( "Beijin3") <= -69 )  dSetSpriteLinearVelocityX( "Beijin3", 0.f );
        }
        if(20 < x && an == 0) dSetSpriteLinearVelocityX( "Beijin3", 0.f );
        if(x < -20 && a == 1)
        {
            dSetSpriteLinearVelocityX( "Beijin3", +40.f );
            if((int)dGetSpritePositionX( "Beijin3" ) >= 70|| (int)dGetSpritePositionX( "Beijin3") < -69 )  dSetSpriteLinearVelocityX( "Beijin3", 0.f );

        }
        if(x < -20 && a  == 0) dSetSpriteLinearVelocityX( "Beijin3", 0.f );
        if(-20<= x && x <= 20) dSetSpriteLinearVelocityX( "Beijin3", 0.f );

        dSpriteMountToSpriteLinkPoint( "Fire1", "Beijin3", 1 );
        dSpriteMountToSpriteLinkPoint( "Fire2", "Beijin3", 2 );
        dSpriteMountToSpriteLinkPoint( "Fire3", "Beijin3", 3 );
        dSpriteMountToSpriteLinkPoint( "Fire4", "Beijin3", 4 );
        dSpriteMountToSpriteLinkPoint( "Fire5", "Beijin3", 5 );
        dSpriteMountToSpriteLinkPoint( "Fire6", "Beijin3", 6 );
        dSpriteMountToSpriteLinkPoint( "Fire7", "Beijin3", 7 );
        dSpriteMountToSpriteLinkPoint( "Fire8", "Beijin3", 8 );
        dSpriteMountToSpriteLinkPoint( "Fire9", "Beijin3", 9 );
        dSpriteMountToSpriteLinkPoint( "Fire10", "Beijin3", 10 );
        dSpriteMountToSpriteLinkPoint( "Fire11", "Beijin3", 11 );
        dSpriteMountToSpriteLinkPoint( "Fire12", "Beijin3", 12 );
        dSpriteMountToSpriteLinkPoint( "Fire13", "Beijin3", 13 );
        dSpriteMountToSpriteLinkPoint( "Fire14", "Beijin3", 14 );
        dSpriteMountToSpriteLinkPoint( "Fire15", "Beijin3", 15 );
        dSpriteMountToSpriteLinkPoint( "Baoxiang1", "Beijin3", 16);
        dSpriteMountToSpriteLinkPoint( "Baoxiang2", "Beijin3", 17);
        dSpriteMountToSpriteLinkPoint( "Door", "Beijin3",18 );
        dSetSpriteCollisionReceive("Fire1", 1);
        dSetSpriteCollisionReceive("Fire2", 1);
        dSetSpriteCollisionReceive("Fire3", 1);
        dSetSpriteCollisionReceive("Fire4", 1);
        dSetSpriteCollisionReceive("Fire5", 1);
        dSetSpriteCollisionReceive("Fire6", 1);
        dSetSpriteCollisionReceive("Fire7", 1);
        dSetSpriteCollisionReceive("Fire8", 1);
        dSetSpriteCollisionReceive("Fire9", 1);
        dSetSpriteCollisionReceive("Fire10", 1);
        dSetSpriteCollisionReceive("Fire11", 1);
        dSetSpriteCollisionReceive("Fire12", 1);
        dSetSpriteCollisionReceive("Fire13", 1);
        dSetSpriteCollisionReceive("Fire14", 1);
        dSetSpriteCollisionReceive("Fire15", 1);
        dSetSpriteCollisionReceive("Baoxiang1", 1);
        dSetSpriteCollisionReceive("Baoxiang2", 1);
        dSetSpriteCollisionReceive("Door", 1);
        fCurrentTime[4] = fCurrentTime[4] - fDeltaTime;
        if(fCurrentTime[4] < 1e-7)
        {
            fPosX = dGetSpriteLinkPointPosX( "Beijin3",19);
            fPosY =  dGetSpriteLinkPointPosY( "Beijin3", 19);
            MonsterAppear("MonsterBird","MonsterBird%d",fPosX,fPosY);
            fCurrentTime[4] = 1.7f;
        }
    }
    if(SceneState==3)
    {
        float fEndX,fEndY,fStartX;
        fEndX=dGetSpritePositionX("hero");
        fEndY=dGetSpritePositionY("hero");
        fStartX=dGetSpritePositionX("boss");
        if(fEndX>fStartX)
        {
            dSetSpriteFlipX("boss",0);
        }
        else
        {
            dSetSpriteFlipX("boss",1);
        }
        dSpriteMoveTo("boss",fEndX,fEndY,10,false);
        CannonTime=CannonTime-fDeltaTime;
        if(CannonTime< 1e-7)
        {
            CannonAppear(iCannon);
            iCannon++;
            CannonTime=1;
        }
        if(BossXueGeColour >= 0 && HeroXueGeColour <0 )
        {
            SceneState=4;
            g_iGameState=1;
            JustGuan=3;
            dStopSound( vice );
        }
        if(BossXueGeColour < 0 && HeroXueGeColour >= 0)
        {
            SceneState=6;
            g_iGameState=1;
            dStopSound( vice );
            FILE *fp;
            if((fp=fopen("score.txt","w"))!=NULL)
            {
                fprintf(fp,"%d %d",HeroXueGeColour,FenShu);
                printf("222");
            }
            fclose(fp);
        }
        if(BossXueGeColour < 0 && HeroXueGeColour < 0)
        {
            SceneState=4;
            g_iGameState=1;
            JustGuan=3;
            dStopSound( vice );

        }
    }
    if(SceneState==6)
    {
        if(FenShu<40)
        {
             dSetSpriteVisible("caozuo",1);
        }
        if(FenShu>=40&&FenShu<=60)
        {
            dSetSpriteVisible("justsoso",1);
        }
        if(FenShu>60&&FenShu<=70)
        {
            dSetSpriteVisible("good",1);
        }
        if(FenShu>70)
        {
            dSetSpriteVisible("congratulation",1);
        }
    }

}


//==============================================================================
//
// 本局游戏结束
void	GameEnd()
{

}
