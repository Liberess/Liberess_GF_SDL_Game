#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "SDL_image.h"
#include "Player.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

enum Dirc
{
  LEFT = 0,
  RIGHT,
  UP,
  DOWN,
};

class Game
{
public:
  Game() : FRAME_TIME_LENGTH(60)
  {
    player = new Player();
    m_bRunning = true;

    ticksLastFrame = 0;
  }
  
  ~Game()
  {
    delete player;
  }

  bool Init(const char *title, int xpos, int ypos,  int width, int height, int flags);
  void Render();
  void Update(); 
  bool Running();
  void HandleEvents();
  void MoveInput();
  void Clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  float ticksLastFrame;
  const int FRAME_TIME_LENGTH;
  int mCurrentFrame; // 스프라이트 애니메이션 구현을 위해 선언
  const Uint8* mKeyStates = SDL_GetKeyboardState(NULL);
  Player* player;
};

#endif