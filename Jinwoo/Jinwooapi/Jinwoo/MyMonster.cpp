#include "pch.h"
#include "MyMonster.h"

#include "MyKeyMgr.h"
#include "MyTimeMgr.h"

#include "MyCollider.h"
#include "MyProjectile.h"

MyMonster::MyMonster() : m_Speed(300.f), monsterTime(0.f), m_Collider(nullptr), m_Info{}
{
	m_Collider = AddComponent<MyCollider>(L"MonsterCollider");
	m_Info.HP = 5.f;
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

	MonsterPos = GetPos();

	//monsterTime += _DT;

	//if (0.f <= monsterTime && monsterTime < 1.f)
	//{
	//	MonsterPos.x += m_Speed * _DT;
	//}
	//else if (1.f <= monsterTime && monsterTime < 2.f)
	//{
	//	MonsterPos.x -= m_Speed * _DT;
	//}
	//else
	//{
	//	monsterTime = 0.f;
	//}

	SetPos(MonsterPos);
}

void MyMonster::render(HDC _dc)
{
	MonsterPos = GetRenderPos();
	MonsterScale = GetScale();

	Ellipse(_dc
		, int(MonsterPos.x - MonsterScale.x / 2)
		, int(MonsterPos.y - MonsterScale.y / 2)
		, int(MonsterPos.x + MonsterScale.x / 2)
		, int(MonsterPos.y + MonsterScale.y / 2));

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
