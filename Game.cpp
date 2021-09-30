#include "Game.h"

bool Game::Init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      else
        return false; // 랜더러 생성 실패
      
      mTextureManager.Load("Assets/animate-alpha.png", "animate", m_pRenderer);
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

void Game::Update()
{
  mCurrentFrame = (SDL_GetTicks() / 100) % 6;
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  mTextureManager.Draw("animate", 0, 0, 128, 82, m_pRenderer);
  mTextureManager.DrawFrame("animate", 100, 100, 128, 82, 0, mCurrentFrame, m_pRenderer);
    
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
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
      case SDLK_UP:
        //m_destinationRectangle.y -= moveSpeed;
        break;
      case SDLK_LEFT:
        direction = LEFT;
        //m_destinationRectangle.x -= moveSpeed;
        break;
      case SDLK_DOWN:
        //m_destinationRectangle.y += moveSpeed;
        break;
      case SDLK_RIGHT:
        direction = RIGHT;
        //m_destinationRectangle.x += moveSpeed;
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