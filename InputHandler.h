#ifndef __InputHandler_H__
#define __InputHandler_H__

#include "SDL.h"

class InputHandler
{
public:
  ~InputHandler() {}
  static InputHandler* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new InputHandler();

    return s_pInstance;
  }
  bool IsKeyDown(SDL_Scancode key);
  void Update();
  void Clean() {}

private:
  InputHandler() {}
  static InputHandler* s_pInstance;
  const Uint8* m_keyStates;
};

typedef InputHandler TheInputHandler;

#endif