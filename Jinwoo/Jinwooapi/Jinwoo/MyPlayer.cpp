#include "pch.h"
#include "MyPlayer.h"

#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"
#include "MyLevelMgr.h"
#include "MyPathMgr.h"

#include "MyLevel.h"
#include "MyProjectile.h"
#include "HomingBullet.h"
#include "MyMonster.h"

MyPlayer::MyPlayer() : m_Speed(300.f), m_PlayerImage(nullptr)
{
	// 이미지가 존재하는 경로 탐색
	wstring strPath = MyPathMgr::GetContentPath();
	strPath += L"Fighter.bmp";

	// 플레이어가 사용할 이미지 로드
	m_PlayerImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_PlayerDC = CreateCompatibleDC(MyEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_PlayerDC, m_PlayerImage));
	GetObject(m_PlayerImage, sizeof(BITMAP), &m_BitmapInfo);
}

MyPlayer::~MyPlayer()
{
	DeleteObject(m_PlayerImage);
	DeleteDC(m_PlayerDC);
}

void MyPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();

	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(D))
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
	}

	if (KEY_TAP(SPACE))
	{
		MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();

		HomingBullet* HBullet = new HomingBullet;

		Vec2 HbulletPos = GetPos();
		HbulletPos.y -= GetScale().y / 2.f;

		HBullet->SetSpeed(300.f);
		HBullet->SetAngle(PI / 2.f);
		HBullet->SetPos(HbulletPos);
		HBullet->SetScale(Vec2(20.f, 20.f));
		HBullet->SetDir(Vec2(0.f, -1.f));
		pCurLevel->AddObject(HBullet);
	}

	SetPos(vPos);
}

void MyPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	// 새로운 펜 객체를 생성
	//						선의 스타일 / 두께 / 색상
	HPEN hCurPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	// 그리기에 사용할 개체를 현재 DC(device context)에 적용
	//								현재 dc / 사용할 개체
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hCurPen);

	// 새로운 브러쉬 생성
	// 펜으로 그린 것의 내부를 채운다
	HBRUSH hCurBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_dc, hCurBrush);

	BitBlt(_dc,
		(int)(vPos.x -= m_BitmapInfo.bmWidth / 2),
		(int)(vPos.y -= m_BitmapInfo.bmHeight / 2),
		m_BitmapInfo.bmWidth,
		m_BitmapInfo.bmHeight,
		m_PlayerDC,
		0, 0, SRCCOPY);

	// 되돌리고 사용했던 펜과 브러쉬를 삭제한다
	SelectObject(_dc, hPrevPen);
	DeleteObject(hCurPen);

	SelectObject(_dc, hPrevBrush);
	DeleteObject(hCurBrush);
}
