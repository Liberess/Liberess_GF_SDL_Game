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
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      else
        return false; // 랜더러 생성 실패
      
      SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");

      if(pTempSurface != 0)
      {
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);

        m_destinationRectangle.w = m_sourceRectangle.w = 128;
        m_destinationRectangle.h = m_sourceRectangle.h = 82;

        //CreateTexture(m_pTexture, pTempSurface, m_sourceRectangle, m_destinationRectangle);
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

void Game::CreateTexture(SDL_Texture* _pTexture, SDL_Surface* _pTempSurface, SDL_Rect& _sourceRect, SDL_Rect& _destinationRect)
{
  _pTexture = SDL_CreateTextureFromSurface(m_pRenderer, _pTempSurface);
  SDL_FreeSurface(_pTempSurface);
  SDL_QueryTexture(_pTexture, NULL, NULL, &_sourceRect.w, &_sourceRect.h);
                      
  _destinationRect.w = _sourceRect.w;
  _destinationRect.h = _sourceRect.h;
  _destinationRect.x = _sourceRect.x = 0;
  _destinationRect.y = _sourceRect.y = 0;
}

void Game::Update()
{
  m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);  
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{ 
  return m_bRunning; 
}

void Game::HandleEvents() 
{
  SDL_Event event;

  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
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