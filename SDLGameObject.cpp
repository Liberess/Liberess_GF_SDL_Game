#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
  : GameObject(pParams), m_position(pParams->GetX(), pParams->GetY()), m_velocity(0, 0), m_acceleration(0, 0)
{
  m_width = pParams->GetWidth();
  m_height = pParams->GetHeight();
  m_imgframe = pParams->GetImgFrame();
  m_textureID = pParams->GetTextureID();
  m_currentRow = 0;
  m_currentFrame = 0;
  m_flipX = pParams->GetFlipX();
}

void SDLGameObject::Draw()
{
  TheTextureManager::Instance()
    ->DrawFrame
        (
          m_textureID,
          (int)m_position.GetX(), (int)m_position.GetY(),
          m_width, m_height,
          m_currentRow, m_currentFrame,
          TheGameManager::Instance()->GetRenderer(),
          m_flipX
        );
}

void SDLGameObject::Update()
{
  m_velocity += m_acceleration;
  m_position += m_velocity;
}