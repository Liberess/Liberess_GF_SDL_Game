#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

class GameObject
{
public:
  void Load(int x, int y, int width, int height, std::string textureID);
  void Draw(SDL_Renderer* pRenderer);
  void Update();
  void Clean();

protected:
  std::string m_textureID;
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
};

#endif