#include <SDL.h>
#include <iostream>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow
      (
        "HelloSDL", // 실습1
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        512, // 실습1
        512, // 실습1
        SDL_WINDOW_SHOWN
      );
    
    if(g_pWindow != 0)
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
  }
  else
  {
    return 1;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255); // 실습2
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(2000);

  SDL_DestroyWindow(g_pWindow); // 윈도우 삭제
  SDL_DestroyRenderer(g_pRenderer); // 렌더러 삭제

  SDL_Delay(2000);
  
  // 새로 윈도우 생성
  g_pWindow = SDL_CreateWindow
    (
      "MySDL", 
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      720,
      480,
      SDL_WINDOW_MAXIMIZED // 창 최대화
    );
    
  if(g_pWindow != 0)
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

  // 2초 간격으로 Red->Green->Cyan 바탕색 변경
  SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255); // 개인
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(2000);

  SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255); // 개인
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(2000);

  SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 255, 255); // 개인
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(2000);

  SDL_DestroyWindow(g_pWindow); // 윈도우 창 삭제
  SDL_DestroyRenderer(g_pRenderer); // 렌더러 삭제
  
  SDL_Quit();

  return 0;
}