#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
  : GameObject(pParams)
{
  m_x = pParams->GetX();
  m_y = pParams->GetY();
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
          m_x, m_y,
          m_width, m_height,
          m_currentRow, m_currentFrame,
          TheGameManager::Instance()->GetRenderer(),
          m_flipX
        );
}