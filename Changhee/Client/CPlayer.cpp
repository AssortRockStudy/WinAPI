#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CTaskMgr.h"
#include "CAssetMgr.h"

#include "CTexture.h"

#include "CCollider.h"
#include "CAnimator.h"

#include "CProjectile.h"



CPlayer::CPlayer()
	: m_fSpeed(200.f)
	, m_pTexture(nullptr)
{
	// Asset
	m_pTexture = CAssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");

	// Component
	m_pCollider = AddComponent<CCollider>(L"PlayerCollider");
	m_pCollider->SetOffsetPos(Vec2(0.f, 10.f));
	m_pCollider->SetScale(Vec2(40.f, 80.f));

	m_pAnimator = AddComponent<CAnimator>(L"PlayerAnimator");
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
		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		CTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT)LAYER::PLAYER_PJ, (UINT_PTR)pProjectile });
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	UINT width = m_pTexture->GetWidth();
	UINT height = m_pTexture->GetHeight();

	TransparentBlt(_dc
		, int(vPos.x - width / 2)
		, int(vPos.y - height / 2)
		, width
		, height
		, m_pTexture->GetDC()
		, 0, 0
		, width
		, height
		, RGB(255, 0, 255));

	Super::render(_dc);
}


void CPlayer::Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol)
{
	wstring test = _pOwnCol->GetName();

}