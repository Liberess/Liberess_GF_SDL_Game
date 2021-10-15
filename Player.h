#ifndef __Player_H__
#define __Player_H__

#include "GameObject.h"

class Player : public GameObject
{
public:
  void Load(int x, int y, int width, int height, int frame, std::string textureID);
  void Draw(SDL_Renderer* pRenderer);
  //void Update();
  void Clean();
};

#endif