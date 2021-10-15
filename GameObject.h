#ifndef __GameObject_H__
#define __GameObject_H__

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

enum DirtX
{
  LEFT = -1,
  RIGHT = 1
};

enum DirtY
{
  DOWN = -1,
  UP = 1
};

class GameObject
{
public:
  GameObject() {}
  virtual ~GameObject() {}
  virtual void Load(int x, int y, int width, int height, int frame, std::string textureID);
  virtual void Draw(SDL_Renderer* pRenderer);
  virtual void Update();
  virtual void Clean();

protected:
  std::string m_textureID;
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_dircX;
  int m_dircY;
  int m_imgframe;
  int m_currentRow;
  int m_currentFrame;
  SDL_RendererFlip flip;
};

#endif