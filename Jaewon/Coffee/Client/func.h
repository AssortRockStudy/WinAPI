#pragma once

Vec2 Rotate(Vec2 _vDir, float _angle);
bool GetRotateClock(Vec2 _vDir1, Vec2 _vDir2);

template<typename T>
bool isValid(T*& _ent){
	if (nullptr == _ent)	{
		return false;
	}

	if (_ent->isDead())	{
		_ent = nullptr;
		return false;
	}

	return true;
}

void changeLevel(LEVEL_TYPE _type);