#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "SDL.h"

class Player : public SDLGameObject
{
  public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

    bool grounded;//그라운드 충돌 bool형
    void jumping();

};