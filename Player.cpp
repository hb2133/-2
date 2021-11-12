#include "Player.h"
#include "SDLGameObject.h"
#include "SDL_rect.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  jumping(); //점프 함수
  handleInput();
  m_currentFrame = ((SDL_GetTicks()/100)%6);
  SDLGameObject::update();
}
void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
    SDLGameObject::m_flip = SDL_FLIP_NONE;
    m_velocity.setX(2);
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) == false)
  {
    m_velocity.setX(0);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
    SDLGameObject::m_flip = SDL_FLIP_HORIZONTAL;
    m_velocity.setX(-2);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
  {
    if(grounded){//땅에 있을 시 점프
       m_velocity.setY(-3);
    }
  }
}

void Player::jumping() //보충 필요!!
{
  if(m_position.getY() < 320) //바닥 높이
  {
    m_velocity.setY(3);
    if(m_position.getY() < 250) //최대 높이 
    {
      grounded = false; //더이상 못올라가서 false
    }
  }
  else if(m_position.getY() > 320){ //바닥에 닿으면 높이 정지 후 땅으로 인식
    m_velocity.setY(0);
    grounded = true;
  }
}


void Player::clean(){}