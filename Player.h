#ifndef __Player_H__
#define __Player_H__

typedef struct 
{
  float x;
  float y;
} Vector2;

class Player
{
public:
  Player()
  {
    isMove = false;
    playerPos.x = 100;
    playerPos.y = 100;
    moveSpeed = 10;

    playerDirc = 3; // Down
  }

  // Get, Set Player Positions
  void SetPosX(float x);
  void SetPosY(float y);
  float GetPosX() const;
  float GetPosY() const;

  // Get, Set Player Direction
  void SetDirc(int dirc);
  int GetDirc() const;

  void SetMove(bool move);
  bool GetMove() const;
  int GetMoveSpeed() const;

private:
  bool isMove;
  Vector2 playerPos;
  int moveSpeed;
  int playerDirc;
};

#endif