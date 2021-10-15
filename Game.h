#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>

class Game
{
public:
  Game()
  {
    m_bRunning = true;
  }
  
  ~Game() { }

  bool Init(const char *title, int xpos, int ypos,  int width, int height, int flags);
  void Render();
  void Update(); 
  bool Running();
  void HandleEvents();
  void Clean();
  static int GetScreenX();
  static int GetScreenY();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  static int m_screenX;
  static int m_screenY;
  std::vector<GameObject*> m_gameObjs;
};

#endif