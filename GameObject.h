#ifndef __GameObject_H__
#define __GameObject_H__

#include "SDL.h"
#include "TextureManager.h"
#include "LoaderParams.h"
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
  virtual void Draw() = 0;
  virtual void Update() = 0;
  virtual void Clean() = 0;
  // Load 함수를 제외한 이유
  // 불필요한 객체(변수) 생성과, 함수 호출을 피하기 위함
  
protected:
  GameObject(const LoaderParams* pParams) {}
};

#endif