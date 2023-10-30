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

#include "Movement.h"
#include "LogMgr.h"
#include "Platform.h"

#include "components.h"


Player::Player()
	: m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{
	SetName(L"Player");
	Texture* pAtlas = AssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link_alpha.bmp");

	//m_Animator = AddComponent<Animator>(L"Animator");
	//m_Animator->CreateAnimation(L"WalkDown", pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkLeft", pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkUp", pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkRight", pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), Vec2(0.f, -60.f), 2.f, 10);

	//m_Animator->CreateAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_Animator->CreateAnimation(L"IdleLeft", pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_Animator->CreateAnimation(L"IdleUp", pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 1);
	//m_Animator->CreateAnimation(L"IdleRight", pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);

	//m_Animator->SaveAnimations(L"animdata");

	m_Animator->LoadAnimation(L"animdata\\WalkDown.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleDown.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleRight.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleUp.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkRight.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkUp.txt");

	m_Animator->Play(L"WalkDown", true);

	m_Collider = AddComponent<Collider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));
	m_Collider->SetOffsetPos(Vec2(0.f, -40.f));

	//m_pTexture = AssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");
	m_Movement = AddComponent<Movement>(L"PlayerMovement");
	m_Movement->SetMass(1.f);
	m_Movement->SetInitSpeed(200.f);
	m_Movement->SetMaxSpeed(400.f);
	m_Movement->SetFrictionScale(1000.f);

	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(true);
}

Player::Player(const Player& _Origin)
	: Obj(_Origin)
	 ,m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{
	m_Collider = GetComponent<Collider>();
	m_Animator = GetComponent<Animator>();
	m_Movement = GetComponent<Movement>();
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
		m_Movement->AddForce(Vec2(-300.f, 0.f));
		m_Animator->Play(L"WalkLeft", true);
	}

	if (KEY_RELEASED(A))
	{
		m_Animator->Play(L"IdleLeft", true);
	}

	if (KEY_PRESSED(D))
	{
		m_Movement->AddForce(Vec2(300.f, 0.f));
		m_Animator->Play(L"WalkRight", true);
	}
	if (KEY_RELEASED(D))
	{
		m_Animator->Play(L"IdleRight", true);
	}

	if (KEY_PRESSED(W))
	{
		m_Movement->AddForce(Vec2(0.f, -300.f));
		m_Animator->Play(L"WalkUp", true);
	}

	if (KEY_RELEASED(W))
	{
		m_Animator->Play(L"IdleUp", true);
	}
	if (KEY_PRESSED(S))
	{
		m_Movement->AddForce(Vec2(0.f, 300.f));
		m_Animator->Play(L"WalkDown", true);
	}
	if (KEY_RELEASED(S))
	{
		m_Animator->Play(L"IdleDown", true);
	}

 	if (KEY_TAP(SPACE))
	{
		m_Movement->SetGround(false);
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, -500.f));

		//Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
		//Guided* pProjectile = new Guided;

		/*Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;
		pProjectile->SetSpeed(500.f);
		pProjectile->SetAngle(PI/2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));
		pProjectile->SetDir(Vec2(0.f, -1.f));
		TaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
	
		LOG(WARNING, L"warning.......");*/
	}

	SetPos(vPos);
}

void Player::BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
 {
	if (dynamic_cast<Platform*>(_OtherObj))
	{
		m_Movement->SetGround(true);
	}
}

void Player::EndOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	if (dynamic_cast<Platform*>(_OtherObj))
	{
		m_Movement->SetGround(false);
	}
}
