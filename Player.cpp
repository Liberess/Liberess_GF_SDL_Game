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
  HandleInput();

  if(m_velocity.GetX() != 0 || m_velocity.GetY() != 0)
    m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;
  else
    m_currentFrame = 0;

  SDLGameObject::Update();
}

void Player::HandleInput()
{
  if(TheInputHandler::Instance()->IsKeyDown(SDL_SCANCODE_RIGHT))
  {
    m_velocity.SetX(2);
    m_flipX = SDL_FLIP_NONE;
  }
  else if(TheInputHandler::Instance()->IsKeyDown(SDL_SCANCODE_LEFT))
  {
    m_velocity.SetX(-2);
    m_flipX = SDL_FLIP_HORIZONTAL;
  }
  else
  {
    m_velocity.SetX(0);
  }
    
  if(TheInputHandler::Instance()->IsKeyDown(SDL_SCANCODE_UP))
    m_velocity.SetY(-2);
  else if(TheInputHandler::Instance()->IsKeyDown(SDL_SCANCODE_DOWN))
    m_velocity.SetY(2);
  else
    m_velocity.SetY(0);
}

void Player::Clean()
{

}