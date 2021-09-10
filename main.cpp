#include <SDL.h>
#include <iostream>

namespace MyColor
{
  const int red[3] = { 255, 0, 0 };
  const int green[3] = { 0, 255, 0 };
  const int cyan[3] = { 0, 255, 255 };
}

// 윈도우 정보 저장
SDL_Window* g_pWindow = 0;

// 렌더링 정보 저장
SDL_Renderer* g_pRenderer = 0;

void SetRenderColor(const int* color, int a = 255)
{
  SDL_SetRenderDrawColor(g_pRenderer, color[0], color[1], color[2], 255);
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
  // SDL 초기화
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
    
    // 윈도우가 생성되어 있다면, 렌더러 생성
    if(g_pWindow != 0)
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
  }
  else
  {
    return 1;
  }

  // 그리기 동작에 사용할 색 지정
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255); // 실습2
  
  // 지정 색으로 렌더러 지우기
  SDL_RenderClear(g_pRenderer);

  // 백버퍼 화면 표시
  SDL_RenderPresent(g_pRenderer);

  // 2초 지연 시간
  SDL_Delay(2000);

  // 윈도우 삭제
  SDL_DestroyWindow(g_pWindow); 

  // 렌더러 삭제
  SDL_DestroyRenderer(g_pRenderer); 

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
  
  // 윈도우가 생성되어 있다면, 렌더러 생성
  if(g_pWindow != 0)
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

  // 네임스페이스 MyColor에 선언된 color 배열로 새로운 배열 생성
  const int* colors[3] = { MyColor::red, MyColor::green, MyColor::cyan };

  for(int i = 0; i < 3; i++)
  {
    // 2초 간격으로 Red->Green->Cyan 바탕색 변경
    SetRenderColor(colors[i]);
    SDL_Delay(2000);
  }

  SDL_DestroyWindow(g_pWindow);
  SDL_DestroyRenderer(g_pRenderer);

  SDL_Quit();

  return 0;
}