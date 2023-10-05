#include "pch.h"
#include "define.h"
#include "Engine.h"
#include "Player.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"
#include "LevelMgr.h"
#include "PathMgr.h"
#include "Level.h"
#include "Projectile.h"
#include "Guided.h"


Player::Player()
	: m_Speed(500.f)
	, m_Image(nullptr)
{
	wstring strPath = PathMgr::GetContentPath();
	strPath += L"texture\\fighter.bmp";

	// �÷��̾ ����� �̹��� ��Ʈ�� �ε�
	m_Image = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_ImageDC = CreateCompatibleDC(Engine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_ImageDC, m_Image));
	GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo);
}

Player::~Player()
{
	DeleteObject(m_Image);
	DeleteDC(m_ImageDC);
}

void Player::tick(float _DT)
{
	Vec2 vPos = GetPos();

	// Ű�Է��� �߻��ϸ� �����δ�.
	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KeyMgr::GetInst()->GetKeyState(D) == PRESSED)
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
		Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; ++i)
		{
			Guided* pProjectile = new Guided;

			Vec2 ProjectilePos = GetPos();
			ProjectilePos.y -= GetScale().y / 2.f;

			pProjectile->SetSpeed(500.f);
			pProjectile->SetAngle(PI/2.f);
			pProjectile->SetPos(ProjectilePos);
			pProjectile->SetScale(Vec2(25.f, 25.f));
			pProjectile->SetDir(Vec2(1.f, -1.f));

			pCurLevel->AddObject(pProjectile);
		}
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[BLACK]));
	HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[BLACK]));

	BitBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
		, (int)vPos.y - m_BitmapInfo.bmHeight / 2
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_ImageDC
		, 0, 0, SRCCOPY);

}
