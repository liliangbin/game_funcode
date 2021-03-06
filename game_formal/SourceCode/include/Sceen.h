#ifndef SCEEN_H
#define SCEEN_H
#include "Sceen.h"

class Sceen
{
public:
    Sceen();
    virtual ~Sceen();
    virtual void Load();
    virtual void MainLoop(float fDeltaTime );
    virtual void MouseMove( const float fMouseX, const float fMouseY );
    virtual  void MouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual  void MouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual  void SpriteColSprite( const char *szSrcName, const char *szTarName );
    virtual  void SpriteColWorldLimit( const char *szName, const int iColSide );
    virtual void	GameRun( float fDeltaTime );
    virtual void	GameEnd();
    virtual void	GameInit();
    virtual  void KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );
    virtual  void KeyUp( const int iKey );
protected:

private:
};

#endif // SCEEN_H
