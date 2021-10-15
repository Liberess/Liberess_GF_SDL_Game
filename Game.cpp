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

      std::string filePath = "Assets/animate-alpha.png";

      if(!TheTextureManager::Instance()->Load(filePath, "animate", m_pRenderer))
	      return false;

      m_go.Load(100, 100, 128, 82, "animate");
      m_player.Load(300, 300, 128, 82, "animate");
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

void Game::MoveInput()
{
  /* if(mKeyStates[SDL_SCANCODE_LEFT])
  {
    player->SetDirc(LEFT);
    player->SetPosX(player->GetMoveSpeed() * -1);
  }
  else if(mKeyStates[SDL_SCANCODE_RIGHT])
  {
    player->SetDirc(RIGHT);
    player->SetPosX(player->GetMoveSpeed());
  }
  else if(mKeyStates[SDL_SCANCODE_UP])
  {
    player->SetDirc(UP);
    player->SetPosY(player->GetMoveSpeed() * -1);
  }
  else if(mKeyStates[SDL_SCANCODE_DOWN])
  {
    player->SetDirc(DOWN);
    player->SetPosY(player->GetMoveSpeed());
  }
  else
    player->SetMove(false);
  
  if(player->GetMove() == false)
  {
    mCurrentFrame = 0;
    return;
  } */

  mCurrentFrame = (SDL_GetTicks() / 100) % 6;
}

void Game::Update()
{
  // ticksLastFrame을 이용하여 deltaTime 계산
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

  // 실제 프레임만큼 대기하도록 시간 계산
  float timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticksLastFrame);

  // 매개 변수만큼 지연
  // void SDL_Delay(Unit32 ms)
  // https://wiki.libsdl.org/SDL_Delay
  if(timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
    SDL_Delay(timeToWait);

  //MoveInput();

  m_go.Update();
  m_player.Update();
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  m_go.Draw(m_pRenderer);
  m_player.Draw(m_pRenderer);
  
  SDL_RenderPresent(m_pRenderer);

  ticksLastFrame = SDL_GetTicks();
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
      m_player.SetMove(true);
      break;
    case SDL_KEYUP:
      m_player.SetMove(false);
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