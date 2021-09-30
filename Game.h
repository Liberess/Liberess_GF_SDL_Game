#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"
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
  //void StretchTextureEx(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Texture* texture, float angle, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void Render();
  void Update(); 
  bool Running();
  void HandleEvents();
  void Clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  SDL_Texture* m_pTexture; // 이미지 리소스
  SDL_Rect m_sourceRectangle; // 원본 사각형
  SDL_Rect m_destinationRectangle; // 대상 사각형
  int mBorderlineX;
  int mBorderlineY;
  int moveSpeed;
  int previousPosX;
  int previousPosY;
  int direction;
};

#endif