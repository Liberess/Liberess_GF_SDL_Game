#include <SDL.h>
#include <iostream>

using namespace std;

enum Color
{
  White = 0,
  Red,
  Green,
  Cyan,
  Black
};

namespace MyColor
{
  const int size = 5;

  const int white[3] = { 255, 255, 255 };
  const int red[3] = { 255, 0, 0 };
  const int green[3] = { 0, 255, 0 };
  const int cyan[3] = { 0, 255, 255 };
  const int black[3] = { 0, 0, 0 };
}

// 네임스페이스 MyColor에 선언된 color 배열로 새로운 배열 생성
const int* colors[MyColor::size] = { MyColor::white, MyColor::red, MyColor::green, MyColor::cyan, MyColor::black };

// 윈도우 정보 저장
SDL_Window* g_pWindow = 0;

// 렌더링 정보 저장
SDL_Renderer* g_pRenderer = 0;

// 플레이 중인지
bool g_bRunning = false;

// Input 선택
int answer;

bool Init(const char* title, int xPos, int yPos, int height, int width, int flags);
void SetRenderColor(const int* color, int a = 255);
void Input();
void Update();
void Render();

int main(int argc, char* args[])
{
  if(Init("Breaking Up HelloSDL",
          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
          640, 480,
          SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }
  else
  {
    return 1;
  }

  while(g_bRunning)
  {
    Input();
    Update();
    Render();
  }

  SDL_DestroyWindow(g_pWindow);
  SDL_DestroyRenderer(g_pRenderer);

  SDL_Quit();

  return 0;
}

bool Init(const char* title, int xPos, int yPos, int height, int width, int flags)
{
  // SDL 초기화
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow
      (
        title,
        xPos,
        yPos,
        height,
        width,
        flags
      );
    
    // 윈도우가 생성되어 있다면, 렌더러 생성
    if(g_pWindow != 0)
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
  }
  else
  {
    return false;
  }

  SetRenderColor(colors[Black]);

  return true;
}

void SetRenderColor(const int* color, int a)
{
  SDL_SetRenderDrawColor(g_pRenderer, color[0], color[1], color[2], 255);

  Render();
}

void Input()
{
  cout << "===================" << endl;
  cout << "0 = white, 1 = red, 2 = green, 3 = cyan, 4 = black, Other = Quit" << endl;
  cout << "배경색 선택 : ";
  cin >> answer;

  if(answer < 0 || answer > 4)
    g_bRunning = false;
}

void Render()
{
  // 지정 색으로 렌더러 지우기
  SDL_RenderClear(g_pRenderer);

  // 백버퍼 화면 표시
  SDL_RenderPresent(g_pRenderer);
}

void Update()
{
  SetRenderColor(colors[answer]);
}

/*
  // 그리기 동작에 사용할 색 지정
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255); // 실습2

  // 2초 지연 시간
  SDL_Delay(2000);

  // 윈도우 삭제
  SDL_DestroyWindow(g_pWindow); 

  // 렌더러 삭제
  SDL_DestroyRenderer(g_pRenderer); 

  SDL_Delay(2000);

  // 새로 윈도우 생성
  Init("MySDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        720, 480,
        SDL_WINDOW_MAXIMIZED);

  for(int i = 0; i < MyColor::size; i++)
  {
    // 2초 간격으로 Red->Green->Cyan 바탕색 변경
    SetRenderColor(colors[i]);
    SDL_Delay(2000);
  }
*/