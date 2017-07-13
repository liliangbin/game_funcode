#ifndef SCENE2_H
#define SCENE2_H
#include "Scene.h"

class Scene2:public Scene
{
    public:
        Scene2();
        virtual ~Scene2();
        virtual void Load();
        virtual void GameMainLoop(float fTimeDelta );
        virtual void MouseMove( const float fMouseX, const float fMouseY );
        virtual void MouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
        virtual void MouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
       // virtual void KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );
        //virtual void KeyUp( const int iKey );
        virtual void SpriteColSprite( const char *szSrcName, const char *szTarName );
        virtual void SpriteColWorldLimit( const char *szName, const int iColSide );
    protected:
    private:
};

#endif // SCENE2_H
