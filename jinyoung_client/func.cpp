#include "pch.h"
#include "func.h"
#include "CEntity.h"

Vec2 Rotate(Vec2 _vDir, float _angle)
{
	_vDir.Normalize();

	Vec2 vRotateDir = Vec2(cosf(_angle) * _vDir.x - sinf(_angle) * _vDir.y
		, sinf(_angle) * _vDir.x + cosf(_angle) * _vDir.y);

	return vRotateDir;
}

bool GetRotateClock(Vec2 _vDir1, Vec2 _vDir2)
{
	//_vDir1.x; _vDir1.y; 0.f, _vDir1.x; _vDir1.y;
	//_vDir2.x; _vDir2.y; 0.f, _vDir2.x; _vDir2.y;

	if (_vDir1.x * _vDir2.y - _vDir1.y * _vDir2.x > 0.f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SaveWString(const wstring& _str, FILE* _File)
{
	size_t iLen = _str.length();
	fwrite(&iLen, sizeof(size_t), 1, _File);
	fwrite(_str.c_str(), sizeof(wchar_t), _str.length(), _File);
}

void LoadWString(wstring& _str, FILE* _File)
{
	size_t iLen = 0;
	wchar_t szBuff[255] = {};

	fread(&iLen, sizeof(size_t), 1, _File);
	fread(szBuff, sizeof(wchar_t), iLen, _File);

	_str = szBuff;
}