#ifndef __TextureManager_H__
#define __TextureManager_H__

#include "SDL.h"
#include "SDL_image.h"
#include <map>

class TextureManager
{
private:   // Key          Value
	std::map<std::string, SDL_Texture*> mTextureMap;
  static TextureManager* s_pInstance; 

  TextureManager() { }
  ~TextureManager() { }

public:
  static TextureManager* Instance()
  {
	  if(s_pInstance == NULL)
	    s_pInstance = new TextureManager();

	  return s_pInstance;
  }
	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

typedef TextureManager TheTextureManager;

#endif