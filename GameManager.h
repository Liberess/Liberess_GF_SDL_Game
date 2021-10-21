#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>

class GameManager
{
public:
  static GameManager* Instance()
  {
	  if(s_pInstance == NULL)
	    s_pInstance = new GameManager();

	  return s_pInstance;
  }
  
  bool Init(const char *title, int xpos, int ypos,  int width, int height, int flags);
  void Render();
  void Update(); 
  bool Running() const { return m_bRunning; }
  void HandleEvents();
  void Clean();
  static int GetScreenX() { return m_screenX; }
  static int GetScreenY() { return m_screenY; }
  SDL_Renderer* GetRenderer() const { return m_pRenderer;}

private:
  GameManager() { m_bRunning = true; }
  ~GameManager() { }
  static GameManager* s_pInstance; 
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  static int m_screenX, m_screenY;
  std::vector<GameObject*> m_gameObjs;
};

typedef GameManager TheGameManager;

#endif