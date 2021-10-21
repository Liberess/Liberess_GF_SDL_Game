//실습 : 08주차 Vector2D
//Branch : Week08_Vector2D

#include "GameManager.h"

int main(int argc, char* argv[])
{
  TheGameManager::Instance()->Init("Game Class", 100, 100, 640, 480, 0);

  while (TheGameManager::Instance()->Running())
  {
    TheGameManager::Instance()->HandleEvents();
    TheGameManager::Instance()->Update();
    TheGameManager::Instance()->Render();
    SDL_Delay(10);
  }

  TheGameManager::Instance()->Clean();
  return 0;
}