#include "Player.h"

Player::Player(const LoaderParams* pParams)
  : SDLGameObject(pParams)
{
  m_dircX = DirtX::RIGHT;
  m_dircY = DirtY::UP;
}

void Player::Draw()
{
  SDLGameObject::Draw();
}

void Player::Update()
{
  // Set Move Direction
  if(m_position.GetX() + m_width >= TheGameManager::Instance()->GetScreenX() || m_position.GetX() <= 0)
    m_dircX *= -1;

  // Set Movement
  m_position.SetX(m_position.GetX() + 1 * m_dircX);

  // Set FlipX
  (m_dircX == DirtX::RIGHT) ? m_flipX = SDL_FLIP_NONE : m_flipX = SDL_FLIP_HORIZONTAL; 

  // Set Img Frame
  m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;
}

void Player::Clean()
{

}