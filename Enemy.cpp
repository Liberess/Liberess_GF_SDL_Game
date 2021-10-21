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
  if(m_x + m_width >= TheGameManager::Instance()->GetScreenX() || m_x <= 0)
    m_dircX *= -1;

    // Set Move Direction
  if(m_y + m_height >= TheGameManager::Instance()->GetScreenY() || m_y <= 0)
    m_dircY *= -1;

  // Set Movement
  m_x += 1 * m_dircX;
  m_y += 1 * m_dircY;

  // Set FlipX
  (m_dircX == DirtX::RIGHT) ? m_flipX = SDL_FLIP_NONE : m_flipX = SDL_FLIP_HORIZONTAL; 

  // Set Img Frame
  m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;
}

void Enemy::Clean()
{

}