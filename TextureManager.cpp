#include "TextureManager.h"

// 정적 멤버변수 초기화
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if(pTempSurface == 0)
		return false;

  // 비트맵이 투명 배경을 지원하지 않기 때문에,
  // SDL의 SetColorKey()를 이용하여 이미지 배경을 투명으로 처리했다.
  // int SDL_SetColorKey(SDL_Surface* surface, int flag, Uint32 key);
  // https://wiki.libsdl.org/SDL_SetColorKey
  SDL_SetColorKey(pTempSurface, SDL_TRUE, SDL_MapRGB(pTempSurface->format, 255, 0, 255));

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if(pTexture != 0)
	{
		mTextureMap[id] = pTexture;
		return true;
	}
	
	return false;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
	SDL_Rect destRect;
	
  srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}