#include "pch.h"
#include "define.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "AssetMgr.h"
#include "Texture.h"
//#include "DrawMgr.h"
#include "Collider.h"
#include "Projectile.h"

#include "NormalMonIdle.h"
#include "NormalMonTrace.h"

Monster::Monster()
	: m_Info{}
	, m_Collider(nullptr)
	, m_AI(nullptr)
	, m_Texture(nullptr)
{
	m_Collider = AddComponent<Collider>(L"MonsterCollider");
	m_Info.HP = 5.f;
	m_Texture = AssetMgr::GetInst()->LoadTexture(L"StartTex", L"texture\\MagicCircle_01.png");

	m_AI = AddComponent<StateMachine>(L"AI");
	m_AI->AddState((UINT)ENORMAL_MON_STATE::NORMAL_MON_IDLE, new NormalMonIdle);
	m_AI->AddState((UINT)ENORMAL_MON_STATE::NORMAL_MON_TRACE, new NormalMonTrace);

}

Monster::Monster(const Monster& _Origin)
	: Obj(_Origin)
	, m_Info(_Origin.m_Info)
	, m_Collider(nullptr)
	, m_AI(nullptr)
	, m_Texture(_Origin.m_Texture)
{
	m_Collider = GetComponent<Collider>();
}

Monster::~Monster()
{
}


void Monster::begin()
{
	m_Collider->SetScale(GetScale() - 10.f);

	Vec2 vPos = GetPos();
	m_AI->AddDataToBlackboard(L"Initial Position", vPos);
	m_AI->AddDataToBlackboard(L"Detect Range", 500.f);
	m_AI->AddDataToBlackboard(L"Attack Range", 50.f);
	m_AI->AddDataToBlackboard(L"Speed", 100.f);


	m_AI->ChangeState((UINT)ENORMAL_MON_STATE::NORMAL_MON_IDLE);
}

void Monster::tick(float _DT)
{
	Super::tick(_DT);
}

void Monster::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();
	Vec2 vScale = GetScale();

	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - m_Texture->GetWidth() / 2.f)
		, int(vRenderPos.y - m_Texture->GetHeight() / 2.f)
		, m_Texture->GetWidth()
		, m_Texture->GetHeight()
		, m_Texture->GetDC()
		, 0, 0
		, m_Texture->GetWidth()
		, m_Texture->GetHeight()
		, blend);

	Super::render(_dc);
}

void Monster::BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	if (dynamic_cast<Projectile*>(_OtherObj))
	{
		m_Info.HP -= 1.f;
		if (m_Info.HP <= 0.f)
		{
			Destroy();
		}
	}
}


