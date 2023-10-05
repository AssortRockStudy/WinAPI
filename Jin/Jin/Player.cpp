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

	Texture* pAtlas = AssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link.bmp");

	m_Animator = AddComponent<Animator>(L"Animator");
	m_Animator->CreateAnimation(L"WalkDown", pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), 0.05f, 10);
	m_Animator->CreateAnimation(L"WalkLeft", pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), 0.05f, 10);
	m_Animator->CreateAnimation(L"WalkUp", pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), 0.05f, 10);
	m_Animator->CreateAnimation(L"WalkRight", pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), 0.05f, 10);

	m_Animator->CreateAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), 0.05f, 3);
	m_Animator->CreateAnimation(L"IdleLeft", pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), 0.05f, 3);
	m_Animator->CreateAnimation(L"IdleUp", pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), 0.05f, 1);
	m_Animator->CreateAnimation(L"IdleRight", pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), 0.05f, 3);


	m_Animator->Play(L"WalkDown", true);



	m_Collider = AddComponent<Collider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));

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
		m_Animator->Play(L"WalkLeft", true);
	}

	if (KEY_RELEASED(A))
	{
		m_Animator->Play(L"IdleLeft", true);
	}

	if (KeyMgr::GetInst()->GetKeyState(D) == PRESSED)
	{
		vPos.x += m_Speed * _DT;
		m_Animator->Play(L"WalkRight", true);
	}
	if (KEY_RELEASED(D))
	{
		m_Animator->Play(L"IdleRight", true);
	}

	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
		m_Animator->Play(L"WalkUp", true);
	}

	if (KEY_RELEASED(W))
	{
		m_Animator->Play(L"IdleUp", true);
	}
	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
		m_Animator->Play(L"WalkDown", true);
	}
	if (KEY_RELEASED(S))
	{
		m_Animator->Play(L"IdleDown", true);
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

void Player::Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	_OwnCol->GetName();
}
