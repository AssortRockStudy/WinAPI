#include "pch.h"
#include "MyMonster.h"

#include "MyKeyMgr.h"
#include "MyTimeMgr.h"
#include "MyPathMgr.h"
#include "MyAssetMgr.h"

#include "MyCollider.h"
#include "MyProjectile.h"
#include "MyTexture.h"

MyMonster::MyMonster() : m_Speed(300.f), monsterTime(0.f), m_Collider(nullptr), m_Info{}
{
	m_Collider = AddComponent<MyCollider>(L"MonsterCollider");

	m_Info.HP = 5.f;

	m_Texture = MyAssetMgr::GetInst()->LoadTexture(L"MonsterTexture", L"texture\\gaper.bmp");
}

MyMonster::~MyMonster()
{
}

void MyMonster::begin()
{
	m_Collider->SetOffsetScale(GetScale() - 10.f);
}

void MyMonster::tick(float _DT)
{
	Super::tick(_DT);

	Vec2 MonsterPos = GetPos();

	monsterTime += _DT;

	if (0.f <= monsterTime && monsterTime < 1.f)
	{
		MonsterPos.x += m_Speed * _DT;
	}
	else if (1.f <= monsterTime && monsterTime < 2.f)
	{
		MonsterPos.x -= m_Speed * _DT;
	}
	else
	{
		monsterTime = 0.f;
	}

	SetPos(MonsterPos);
}

void MyMonster::render(HDC _dc)
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

void MyMonster::BeginOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol)
{
	if (dynamic_cast<MyProjectile*>(_OtherObject))
	{
		m_Info.HP -= 1.f;

		if (m_Info.HP <= 0)
		{
			Destroy();
		}
	}
}
