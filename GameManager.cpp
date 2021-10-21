#include "GameManager.h"
#include "Enemy.h"
#include "Player.h"

// 정적 멤버변수 초기화
GameManager* GameManager::s_pInstance = 0;

int GameManager::m_screenX = 0;
int GameManager::m_screenY = 0;

bool GameManager::Init(const char *title, int xpos, int ypos, int width, int height, int flags)
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

      m_gameObjs.push_back(new Player(new LoaderParams(100, 100, 128, 82, 6, "animate")));
      m_gameObjs.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, 6, "animate")));
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

void GameManager::Update()
{
  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Update();
}

void GameManager::Render()
{
  SDL_RenderClear(m_pRenderer);

  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Draw();

  SDL_RenderPresent(m_pRenderer);
}

void GameManager::HandleEvents() 
{
  SDL_Event event;

  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {

    }
  }
}

void GameManager::Clean() 
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}