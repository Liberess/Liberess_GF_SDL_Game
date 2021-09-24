#include "Game.h"

bool Game::Init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    mBorderlineX = width;
    mBorderlineY = height;

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      else
        return false; // 랜더러 생성 실패
      
      SDL_Surface* pTempSurface = IMG_Load("Assets/Run (32x32).png");

      if(pTempSurface != 0)
      {
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);

        m_sourceRectangle.w = 32;
        m_sourceRectangle.h = 32;
        m_destinationRectangle.w = 64;
        m_destinationRectangle.h = 64;

        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255); //붉은색 배경
      }
      else
        return false;
    }
    else
    {
      return false; // 윈도우 생성 실패 l
    }
  }
  else
  {
    return false; // SDL 초기화 실패
  }

  m_bRunning = true;
  return true;
}

//지금은 flip X 하고 있습니다.

/* void Game::StretchTextureEx(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Texture* texture, float angle, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
  SDL_Point center;

  m_sourceRectangle.x = m_sourceRectangle.y = 0;
  SDL_QueryTexture(texture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

  m_destinationRectangle.x = x;
  m_destinationRectangle.y = y;
  m_destinationRectangle.w = w;
  m_destinationRectangle.h = h;
} */

void Game::Update()
{
  if(m_destinationRectangle.x != previousPosX ||
      m_destinationRectangle.y != previousPosY)
    m_sourceRectangle.x = 32 * ((SDL_GetTicks() / 100) % 12);
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  if(direction == RIGHT)
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  else
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    
  SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{ 
  return m_bRunning; 
}

void Game::HandleEvents() 
{
  SDL_Event event;

  previousPosX = m_destinationRectangle.x;
  previousPosY = m_destinationRectangle.y;

  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
      case SDLK_UP:
        m_destinationRectangle.y -= moveSpeed;
        break;
      case SDLK_LEFT:
        direction = LEFT;
        m_destinationRectangle.x -= moveSpeed;
        break;
      case SDLK_DOWN:
        m_destinationRectangle.y += moveSpeed;
        break;
      case SDLK_RIGHT:
        direction = RIGHT;
        m_destinationRectangle.x += moveSpeed;
        break;
      }
      break;
    case SDL_QUIT:
      m_bRunning = false;
      break;
    default:
      break;
    }
  }
}

void Game::Clean() 
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();

  cout << "게임 종료" << endl;
}