#include "Game.h"
#include "GameObject.h"
 
void GameObject::Load(int x, int y, int width, int height, int frame, std::string textureID)
{
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  m_dircX = DirtX::RIGHT;
  m_dircY = DirtY::UP;
  m_textureID = textureID;
  m_imgframe = frame;
  m_currentRow = 0;
  m_currentFrame = 0;
  flip = SDL_FLIP_NONE;
}
  
void GameObject::Draw(SDL_Renderer* pRenderer)
{
  TheTextureManager::Instance()
    ->DrawFrame
        (
          m_textureID,
          m_x, m_y,
          m_width, m_height,
          m_currentRow,
          m_currentFrame,
          pRenderer,
          flip
        );
}

void GameObject::Update()
{
  if(m_x + m_width > Game::GetScreenX() || m_x < 0)
    m_dircX *= -1;

  m_x += 1 * m_dircX;

  (m_dircX == DirtX::RIGHT) ? flip = SDL_FLIP_NONE : flip = SDL_FLIP_HORIZONTAL; 

  m_currentFrame = (SDL_GetTicks() / 100) % m_imgframe;
}

void GameObject::Clean()
{

}