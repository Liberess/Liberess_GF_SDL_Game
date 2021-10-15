#include "Game.h"

int Game::m_screenX = 0;
int Game::m_screenY = 0;

bool Game::Init(const char *title, int xpos, int ypos,  int width, int height, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0)
    {
      m_screenX = width;
      m_screenY = height;
      
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      else
        return false; // 랜더러 생성 실패

      std::string filePath = "Assets/animate-alpha.png";

      if(!TheTextureManager::Instance()->Load(filePath, "animate", m_pRenderer))
	      return false;

      GameObject* m_go = new GameObject();
      GameObject* m_player = new Player();

      m_go->Load(100, 100, 128, 82, 6, "animate");
      m_player->Load(300, 300, 128, 82, 6, "animate");

      m_gameObjs.push_back(m_go);
      m_gameObjs.push_back(m_player);
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
  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Update();
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Draw(m_pRenderer);

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

    }
  }
}

int Game::GetScreenX() { return m_screenX; }

int Game::GetScreenY() { return m_screenY; }

void Game::Clean() 
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}