#pragma once

Vec2 RotateBullet(Vec2 _Dir, float _f);
bool IsClockwise(Vec2 _Dir1, Vec2 _Dir2);

template <typename T>
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

void SaveWString(const wstring& _str, FILE* _File);
void LodeWString(wstring& _str, FILE* _File);

void ChangeLevel(LEVEL_TYPE _type);