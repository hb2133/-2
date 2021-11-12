#include "Tile.h"

Tile::Tile(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Tile::draw()
{
  SDLGameObject::draw();
}

void Tile::update()
{

  m_currentFrame = (SDL_GetTicks() / 100)%1;
  //SDLGameObject::update();
}



void Tile::clean() {}