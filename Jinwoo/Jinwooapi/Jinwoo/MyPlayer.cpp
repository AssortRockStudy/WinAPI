#include "pch.h"
#include "MyPlayer.h"

#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"
#include "MyLevelMgr.h"
#include "MyPathMgr.h"
#include "MyAssetMgr.h"
#include "MyLogMgr.h"

#include "MyLevel.h"
#include "MyProjectile.h"

#include "components.h"

#include "HomingBullet.h"
#include "MyMonster.h"
#include "MyPlatform.h"
#include "MyTexture.h"


MyPlayer::MyPlayer() : m_Speed(300.f), m_Collider(nullptr)
{
	// Player가 사용하는 텍스처 불러오기
	m_Texture = MyAssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link.bmp");

	m_Animator = AddComponent<MyAnimator>(L"PlayerAnimator");
	
	//m_Animator->CreateAnimation(L"IdleDown", m_Texture, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.5f, 3);
	//m_Animator->CreateAnimation(L"IdleLeft", m_Texture, Vec2(0.f, 130.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.5f, 3);
	//m_Animator->CreateAnimation(L"IdleUp", m_Texture, Vec2(0.f, 260.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.5f, 1);
	//m_Animator->CreateAnimation(L"IdleRight", m_Texture, Vec2(0.f, 390.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.5f, 3);

	//m_Animator->CreateAnimation(L"WalkDown", m_Texture, Vec2(0.f, 520.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkLeft", m_Texture, Vec2(0.f, 650.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkUp", m_Texture, Vec2(0.f, 780.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkRight", m_Texture, Vec2(0.f, 910.f), Vec2(120, 130), Vec2(0.f, -65.f), 0.05f, 10);
	//m_Animator->SaveAnimation(L"animdata");

	m_Animator->LoadAnimation(L"animdata\\IdleDown.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleUp.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleRight.txt");

	m_Animator->LoadAnimation(L"animdata\\WalkDown.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkUp.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkRight.txt");

	m_Animator->Play(L"IdleDown", true);

	// Player가 사용하는 Component 추가
	m_Collider = AddComponent<MyCollider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, -45.f));
	m_Collider->SetOffsetScale(Vec2(80.f, 100.f));

	// Movement 컴포넌트 추가
	m_Movement = AddComponent<MyMovement>(L"PlayerMovement");
	m_Movement->SetMass(1.f);
	m_Movement->SetInitSpeed(100.f);
	m_Movement->SetMaxSpeed(400.f);
	m_Movement->SetFrictionScale(1000.f);
	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
}

MyPlayer::~MyPlayer()
{
	
}

void MyPlayer::tick(float _DT)
{
	Super::tick(_DT);

	Vec2 vPos = GetPos();

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

		//MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();

		//HomingBullet* HBullet = new HomingBullet;

		//Vec2 HbulletPos = GetPos();
		//HbulletPos.y -= GetScale().y / 2.f;

		//HBullet->SetSpeed(300.f);
		//HBullet->SetAngle(PI / 2.f);
		//HBullet->SetPos(HbulletPos);
		//HBullet->SetScale(Vec2(20.f, 20.f));
		//HBullet->SetDir(Vec2(0.f, -1.f));
		//
		//MyTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT_PTR)LAYER::PLAYERBULLET, (UINT_PTR)HBullet });

		//LOG(LOG, L"Shoot");
	}

	SetPos(vPos);
}

void MyPlayer::BeginOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol)
{
	if (dynamic_cast<MyPlatform*>(_OtherObject))
	{
		m_Movement->SetGround(true);
	}
}

void MyPlayer::EndOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol)
{
	if (dynamic_cast<MyPlatform*>(_OtherObject))
	{
		m_Movement->SetGround(false);
	}
}
