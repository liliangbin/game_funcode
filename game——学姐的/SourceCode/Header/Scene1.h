#ifndef SCENE1_H
#define SCENE1_H
#include "Scene.h"

class Scene1:public Scene
{
    public:
        Scene1();
        virtual ~Scene1();
        virtual void Load();
        virtual void GameMainLoop(float fTimeDelta );
        virtual void MouseMove( const float fMouseX, const float fMouseY );
        virtual void MouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
        virtual void MouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
        /*virtual void KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );
        virtual void KeyUp( const int iKey );*/
        virtual void SpriteColSprite( const char *szSrcName, const char *szTarName );
        virtual void SpriteColWorldLimit( const char *szName, const int iColSide );
    protected:
    private:
};

#endif // SCENE1_H
