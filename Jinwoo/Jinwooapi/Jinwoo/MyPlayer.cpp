#include "pch.h"
#include "MyPlayer.h"

#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"
#include "MyLevelMgr.h"
#include "MyPathMgr.h"
#include "MyAssetMgr.h"

#include "MyLevel.h"
#include "MyProjectile.h"

#include "MyCollider.h"
#include "MyAnimator.h"

#include "HomingBullet.h"
#include "MyMonster.h"
#include "MyTexture.h"

MyPlayer::MyPlayer() : m_Speed(300.f), m_Collider(nullptr)
{
	// Player가 사용하는 Component 추가
	m_Collider = AddComponent<MyCollider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetOffsetScale(Vec2(40.f, 80.f));

	m_Animator = AddComponent<MyAnimator>(L"PlayerAnimator");

	// Player가 사용하는 텍스처 불러오기
	m_Texture = MyAssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\Fighter.bmp");
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
		
		MyTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT_PTR)LAYER::PLAYERBULLET, (UINT_PTR)HBullet });
	}

	SetPos(vPos);
}

void MyPlayer::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	UINT width = m_Texture->GetWidth();
	UINT height = m_Texture->GetHeight();

	TransparentBlt(_dc,
		(int)(vPos.x -= width / 2.f),
		(int)(vPos.y -= height / 2.f),
		width,
		height,
		m_Texture->GetDC(),
		0, 0,
		width,
		height,
		RGB(255, 0, 255));

	Super::render(_dc);
}

void MyPlayer::Overlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol)
{
	_OwnCol->GetName();
}
