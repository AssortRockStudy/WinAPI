#pragma once


Vec2 Rotate(Vec2 _vDir, float _angle);
bool GetRotateClock(Vec2 _vDir1, Vec2 _vDir2);


template<typename T>
bool IsValid(T*& _Entity)
{
	if (nullptr == _Entity)
	{
		return false;
	}

	if (_Entity->IsDead())
	{
		_Entity = nullptr;
		return false;
	}

	return true;
}
