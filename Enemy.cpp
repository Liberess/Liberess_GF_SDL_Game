#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const LoaderParams* pParams)
  : SDLGameObject(pParams)
{
  m_dircX = DirtX::LEFT;
  m_dircY = DirtY::UP;
}

void Enemy::Draw()
{
  SDLGameObject::Draw();
}

void Enemy::Update()
{
  HandleInput();

  // Set Img Frame
  m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;

  m_velocity.SetX(1);
  m_acceleration.SetX(1); 

  //SDLGameObject::Update();
}

void Enemy::HandleInput()
{
  if(TheInputHandler::Instance()->GetMouseBtnState(TheInputHandler::LEFT))
    std::cout << "shoot" << std::endl;
  
  Vector2D* vec = TheInputHandler::Instance()->GetMousePos();
  m_velocity = (*vec - m_position) / 100;
}

void Enemy::Clean()
{

}