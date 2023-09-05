#include "pch.h"
#include "CPlayer.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick()
{
	// 키입력이 발생하면 이동한다.
	int a = 0;
}


void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vPos = GetScale();


	HPEN hRedPen CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hRedPen);


	SelectObject(_dc, hPrevPen);
	//커널오브젝트이기때문에 직접지울수는 없다.
	//ID값만알려줌
	DeleteObject(hRedPen);

}