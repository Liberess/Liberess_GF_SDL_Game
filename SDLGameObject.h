#ifndef __SDLGameObject_H__
#define __SDLGameObject_H__

#include "Vector2D.h"
#include "GameObject.h"
#include "GameManager.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual ~SDLGameObject() {}
  virtual void Draw();
  virtual void Update(); // 실습
  virtual void Clean() {}

protected:
  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
  int m_width, m_height;
  int m_imgframe;
  std::string m_textureID;
  int m_currentRow, m_currentFrame;
  SDL_RendererFlip m_flipX;
  int m_dircX, m_dircY;
};

#endif