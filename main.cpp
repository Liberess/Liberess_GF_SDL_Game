//실습 : 10주차 물리
//Branch : Week10_물리

#include "GameManager.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  if(TheGameManager::Instance()->Init("Game Class", 100, 100, 640, 480, false))
  {
    Uint32 frameStart, frameTime;

    while(TheGameManager::Instance()->Running())
    {
      frameStart = SDL_GetTicks();

      TheGameManager::Instance()->HandleEvents();
      TheGameManager::Instance()->Update();
      TheGameManager::Instance()->Render();

      frameTime = SDL_GetTicks() - frameStart;
      if(frameTime < DELAY_TIME)
        SDL_Delay((int)(DELAY_TIME - frameTime));
    }
  }
  else
  {
    std::cout << "Game Init Failure " << SDL_GetError() << "\n";
    return -1;
  }

  TheGameManager::Instance()->Clean();
  return 0;
}