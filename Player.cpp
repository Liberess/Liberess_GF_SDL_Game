#include "Player.h"

void Player::SetPosX(float x)
{
  playerPos.x += x;
}

void Player::SetPosY(float y)
{
  playerPos.y += y;
}

float Player::GetPosX() const
{
  return playerPos.x;
}

float Player::GetPosY() const
{
  return playerPos.y;
}

void Player::SetDirc(int dirc)
{
  playerDirc = dirc;
}

int Player::GetDirc() const
{
  return playerDirc;
}

void Player::SetMove(bool move)
{
  this->isMove = move;
}

bool Player::GetMove() const
{
  return isMove;
}

int Player::GetMoveSpeed() const
{
  return moveSpeed;
}