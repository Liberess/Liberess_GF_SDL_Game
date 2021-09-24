#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class Game
{
public:
  Game()
  {
    mDirectionX = 1;
    mDirectionY = 1;
  }
  
  ~Game() {}

  bool Init(const char *title, int xpos, int ypos,  int width, int height, int flags);
  void CreateTexture(SDL_Texture* _pTexture, SDL_Surface* _pTempSurface, SDL_Rect& _sourceRect, SDL_Rect& _destinationRect);
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
  int mDirectionX;
  int mDirectionY;
  int inputX;
  int inputY;
};

#endif