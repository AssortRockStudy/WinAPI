#include "pch.h"
#include "Func.h"

#include "MyEntity.h"

Vec2 RotateBullet(Vec2 _Dir, float _f)
{
	return Vec2(_Dir.x * cosf(_f) - _Dir.y * sinf(_f),
				_Dir.y * cosf(_f) + _Dir.x * sinf(_f));
}

bool IsClockwise(Vec2 _Dir1, Vec2 _Dir2)
{
	float vOut = _Dir1.x * _Dir2.y - _Dir1.y * _Dir2.x;

	if (0 < vOut)
	{
		return true;
	}
	else
	{
		return false;
	}
}
