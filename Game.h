#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>

#define LEFT 0
#define RIGHT 1

using namespace std;

class Game
{
public:
  Game()
  {
    direction = RIGHT;
    moveSpeed = 7;
  }
  
  ~Game() {}

  bool Init(const char *title, int xpos, int ypos,  int width, int height, int flags);
  void Render();
  void Update(); 
  bool Running();
  void HandleEvents();
  void Clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int moveSpeed;
  int direction;
  // TextureManager의 인스턴스
  TextureManager mTextureManager;
  // 스프라이트 애니메이션 구현을 위해 선언
  int mCurrentFrame;
};

#endif