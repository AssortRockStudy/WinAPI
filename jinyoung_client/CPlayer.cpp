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
	// Ű�Է��� �߻��ϸ� �̵��Ѵ�.
	int a = 0;
}


void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vPos = GetScale();


	HPEN hRedPen CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hRedPen);


	SelectObject(_dc, hPrevPen);
	//Ŀ�ο�����Ʈ�̱⶧���� ����������� ����.
	//ID�����˷���
	DeleteObject(hRedPen);

}