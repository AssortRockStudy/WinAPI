#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CTaskMgr.h"

#include "Component.h"

#include "CProjectile.h"



CPlayer::CPlayer()
	: m_fSpeed(200.f)
{
	
	// animator
	m_pAnimator = AddComponent<CAnimator>(L"Animator");

	// Create
	//m_pAnimator->CreateAnimation(L"WalkDown", m_pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), Vec2(0.f,-60.f), 0.05f, 10);
	//m_pAnimator->CreateAnimation(L"WalkLeft", m_pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_pAnimator->CreateAnimation(L"WalkUp", m_pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_pAnimator->CreateAnimation(L"WalkRight", m_pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);

	//m_pAnimator->CreateAnimation(L"IdleDown", m_pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_pAnimator->CreateAnimation(L"IdleLeft", m_pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_pAnimator->CreateAnimation(L"IdleUp", m_pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 1);
	//m_pAnimator->CreateAnimation(L"IdleRight", m_pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	// Save
	//m_pAnimator->SaveAnimations(L"animdata");


	m_pAnimator->LoadAnimation(L"animdata\\IdleDown.txt");
	m_pAnimator->LoadAnimation(L"animdata\\IdleLeft.txt");
	m_pAnimator->LoadAnimation(L"animdata\\IdleRight.txt");
	m_pAnimator->LoadAnimation(L"animdata\\IdleUp.txt");
	m_pAnimator->LoadAnimation(L"animdata\\WalkDown.txt");
	m_pAnimator->LoadAnimation(L"animdata\\WalkLeft.txt");
	m_pAnimator->LoadAnimation(L"animdata\\WalkRight.txt");
	m_pAnimator->LoadAnimation(L"animdata\\WalkUp.txt");



	m_pAnimator->Play(L"WalkDown", true);

	// collider
	m_pCollider = AddComponent<CCollider>(L"PlayerCollider");
	m_pCollider->SetOffsetPos(Vec2(0.f, -40.f));
	m_pCollider->SetScale(Vec2(40.f, 80.f));

}

CPlayer::~CPlayer()
{

}



void CPlayer::tick(float _DT)
{
	Super::tick(_DT);

	Vec2 vPos = GetPos();
	
	if (KEY_PRESSED(KEY::W))
	{
		vPos.y -= m_fSpeed * _DT;
		m_pAnimator->Play(L"WalkUp", true);
	}
	if (KEY_RELEASED(KEY::W))
	{
		m_pAnimator->Play(L"IdleUp", true);
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y += m_fSpeed * _DT;
		m_pAnimator->Play(L"WalkDown", true);
	}
	if (KEY_RELEASED(KEY::S))
	{
		m_pAnimator->Play(L"IdleDown", true);
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		vPos.x -= m_fSpeed * _DT;
		m_pAnimator->Play(L"WalkLeft", true);
	}
	if (KEY_RELEASED(KEY::A))
	{
		m_pAnimator->Play(L"IdleLeft", true);
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		vPos.x += m_fSpeed * _DT;
		m_pAnimator->Play(L"WalkRight", true);
	}
	if (KEY_RELEASED(KEY::D))
	{
		m_pAnimator->Play(L"IdleRight", true);
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		CTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT)LAYER::PLAYER_PJ, (UINT_PTR)pProjectile });

		LOG(LOG_LEVEL::WARNING, L"°æ°í");
	}

	SetPos(vPos);
}


void CPlayer::Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol)
{
	wstring test = _pOwnCol->GetName();

}