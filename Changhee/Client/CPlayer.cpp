#include "pch.h"
#include "CPlayer.h"

#include "CEngine.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"

#include "CLevel.h"

#include "CProjectile.h"

#include "CProjectile1.h"
#include "CProjectile2.h"
#include "CProjectile3.h"

CPlayer::CPlayer()
	: m_fSpeed(200.f)
{
	// 이미지가 존재하는 상대경로(content 폴더로부터)
	wstring strPath = CPathMgr::GetContentDirectory();
	strPath += L"texture\\Fighter.bmp";

	m_hImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_hImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject((HBITMAP)SelectObject(m_hImageDC, m_hImage));

	GetObject(m_hImage, sizeof(BITMAP), &m_BitmapInfo);
}

CPlayer::~CPlayer()
{
	DeleteObject(m_hImage);
	DeleteDC(m_hImageDC);

}



void CPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();
	
	if (KEY_PRESSED(KEY::W))
	{
		vPos.y -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y += m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		vPos.x -= m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		vPos.x += m_fSpeed * _DT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
	}

	// 1단계
	if (KEY_TAP(KEY::_1))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile1* pProjectile = new CProjectile1;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
	}
	
	// 2단계
	if (KEY_TAP(KEY::_2))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile2* pProjectile = new CProjectile2;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
	}

	// 3단계
	if (KEY_TAP(KEY::_3))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile3* pProjectile = new CProjectile3;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
	}


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	CPalette BlackBrush(_dc, BRUSH_TYPE::BLACK);
	CPalette BluePen(_dc, PEN_TYPE::BLUE);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	BitBlt(_dc
		, int(vPos.x - m_BitmapInfo.bmWidth / 2)
		, int(vPos.y - m_BitmapInfo.bmHeight / 2)
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_hImageDC, 0, 0, SRCCOPY);

}