#include "pch.h"
#include "Func.h"

#include "MyEntity.h"
#include "MyTaskMgr.h"

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

void SaveWString(const wstring& _str, FILE* _File)
{
	size_t iLen = _str.length();
	fwrite(&iLen, sizeof(size_t), 1, _File);
	fwrite(_str.c_str(), sizeof(wchar_t), _str.length(), _File);
}

void LodeWString(wstring& _str, FILE* _File)
{
	size_t iLen = 0;
	wchar_t szBuff[255] = {};

	fread(&iLen, sizeof(size_t), 1, _File);
	fread(szBuff, sizeof(wchar_t), iLen, _File);

	_str = szBuff;
}

void ChangeLevel(LEVEL_TYPE _type)
{
	FTask task = {};
	task.Type = TASK_TYPE::LEVEL_CHANGE;
	task.Param1 = (UINT_PTR)_type;
	MyTaskMgr::GetInst()->AddTask(task);
}
