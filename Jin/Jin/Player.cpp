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
#include "Collider.h"



Player::Player()
	: m_Speed(500.f)
	, m_Image(nullptr)
{
	wstring strPath = PathMgr::GetContentPath();
	strPath += L"texture\\fighter.bmp";

	m_Collider = AddComponent<Collider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));

	// 플레이어가 사용할 이미지 비트맵 로딩
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
	Super::tick(_DT);

	Vec2 vPos = GetPos();

	// 키입력이 발생하면 움직인다.
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
			pProjectile->SetDir(Vec2(0.f, -1.f));
			TaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT,PLAYER_PJ, (UINT_PTR)pProjectile });
			//pCurLevel->AddObject(PLAYER_PJ, pProjectile);
		}
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[BLACK]));
	HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[BLACK]));


	TransparentBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
		, (int)vPos.y - m_BitmapInfo.bmHeight / 2
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_ImageDC
		, 0, 0
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, RGB(255, 0, 255));

	Super::render(_dc);
}

void Player::Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	_OwnCol->GetName();
}
