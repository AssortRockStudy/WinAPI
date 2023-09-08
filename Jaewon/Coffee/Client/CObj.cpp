#include "pch.h"
#include "CObj.h"

void CObj::render(HDC _dc)
{
	Rectangle(_dc
		, int(mPos.x - mScale.x / 2)
		, int(mPos.y - mScale.y / 2)
		, int(mPos.x + mScale.x / 2)
		, int(mPos.y + mScale.y / 2));
}

CObj::CObj()
{
}

CObj::~CObj()
{
}
