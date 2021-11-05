#include "InputHandler.h"
#include "GameManager.h"
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::Update()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        TheGameManager::Instance()->Quit();
      case SDL_KEYUP:
        m_keyStates = SDL_GetKeyboardState(0);
      case SDL_KEYDOWN:
        m_keyStates = SDL_GetKeyboardState(0);
    }
  }
}

bool InputHandler::IsKeyDown(SDL_Scancode key)
{
  if(m_keyStates != 0)
  {
    if(m_keyStates[key] == 1)
      return true;
    else
      return false;
  }

  return false;
}