//실습 : 07주차 상속
//Branch : week07_상속

#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
  g_game = new Game();
  g_game->Init("Game Class", 100, 100, 640, 480, 0);

  while (g_game->Running())
  {
    g_game->HandleEvents();
    g_game->Update();
    g_game->Render();
    SDL_Delay(10);
  }

  g_game->Clean();
  return 0;
}