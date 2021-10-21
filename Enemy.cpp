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
  // Set Move Direction
  if(m_position.GetX() + m_width >= TheGameManager::Instance()->GetScreenX() || m_position.GetX() <= 0)
    m_dircX *= -1;

    // Set Move Direction
  if(m_position.GetY() + m_height >= TheGameManager::Instance()->GetScreenY() || m_position.GetY() <= 0)
    m_dircY *= -1;

  // Set Movement
  m_position.SetX(m_position.GetX() + 1 * m_dircX);
  m_position.SetY(m_position.GetY() + 1 * m_dircY);

  // Set FlipX
  (m_dircX == DirtX::RIGHT) ? m_flipX = SDL_FLIP_NONE : m_flipX = SDL_FLIP_HORIZONTAL; 

  // Set Img Frame
  m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;
}

void Enemy::Clean()
{

}