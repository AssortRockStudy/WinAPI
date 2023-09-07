#include "pch.h"
#include "Player.h"

void Player::tick()
{
}

void Player::render(HDC _dc)
{
	Rectangle(_dc
		, getPos().x - getScale().x / 2
		, getPos().y - getScale().y / 2
		, getPos().x + getScale().x / 2
		, getPos().y + getScale().y / 2);
}

Player::Player()
{
}

Player::~Player()
{
}
