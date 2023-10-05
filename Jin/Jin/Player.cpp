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

#include "AssetMgr.h"
#include "Texture.h"

#include "Collider.h"
#include "Animator.h"



Player::Player()
	: m_Speed(500.f)
{

	m_Collider = AddComponent<Collider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));
	
	m_Animator = AddComponent<Animator>(L"Animator");

	m_pTexture = AssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");

}

Player::~Player()
{
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

		Guided* pProjectile = new Guided;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(500.f);
		pProjectile->SetAngle(PI/2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));
		pProjectile->SetDir(Vec2(0.f, -1.f));
		TaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	//HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[BLACK]));
	//HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[BLACK]));

	UINT width = m_pTexture->GetWidth();
	UINT height = m_pTexture->GetHeight();


	TransparentBlt(_dc
		, (int)vPos.x - width / 2
		, (int)vPos.y - height / 2
		, width
		, height
		, m_pTexture->GetDC()
		, 0, 0
		, width
		, height
		, RGB(255, 0, 255));


	Super::render(_dc);
}

void Player::Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	_OwnCol->GetName();
}
