#include "pch.h"
#include "Guided.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"

Guided::Guided()
	: m_Target(nullptr)
	, m_fMass(1.f)
	, m_fRotateSpeed(PI)
{
}

Guided::~Guided()
{
}


Guided::Guided(const Guided& _Origin)
	: m_Target(nullptr)
	, m_fMass(_Origin.m_fMass)
	, m_vAccel(_Origin.m_vAccel)
	, m_vVelocity(_Origin.m_vVelocity)
	, m_vForce(_Origin.m_vForce)
	, m_vDir(_Origin.m_vDir)
	, m_fRotateSpeed(_Origin.m_fRotateSpeed)
{
}

void Guided::begin()
{
	Super::begin();
	GetCollider()->SetScale(GetScale());
}


void Guided::tick(float _DT)
{
	Super::tick(_DT);

	if (!IsValid(m_Target))
	{
		FindTarget();
	}

	if (!IsValid(m_Target)) 
	{
		Vec2 vPos = GetPos();
		vPos.x += m_vDir.x * GetSpeed() * DT;
		vPos.y += m_vDir.y * GetSpeed() * DT;

		SetPos(vPos);
	}
	else
	{
		Update_3();
	}
}

void Guided::FindTarget()
{
	Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
	const vector<Obj*>& vecMon = pCurLevel->GetObjects(LAYER::MONSTER);

	if (vecMon.size() == 1)
	{
		m_Target = dynamic_cast<Monster*>(vecMon[0]);
		assert(m_Target);
	}
	else if (vecMon.empty())
	{
		return;
	}
	else
	{
		float fMax = 2000.f;

		for (size_t i = 0; i < vecMon.size(); ++i)
		{
			float fDistance = GetPos().Distance(vecMon[i]->GetPos());

			if (fMax > fDistance)
			{
				fMax = fDistance;

				m_Target = dynamic_cast<Monster*>(vecMon[i]);
				assert(m_Target);
			}
		}
	}
}

void Guided::Update_1()
{
	Vec2 vPos = GetPos();
	// 1
	Vec2 vDir = m_Target->GetPos() - GetPos();
	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);

}

void Guided::Update_2()
{
	float Force = 1000.f;
	Vec2 vForce = m_Target->GetPos() - GetPos();
	vForce.Normalize() *= Force;

	m_vAccel = vForce / m_fMass;
	m_vVelocity += m_vAccel * DT;
	
	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;

	SetPos(vPos);

}

void Guided::Update_3()
{
	m_vDir.Normalize();
	Vec2 vDest = m_Target->GetPos() - GetPos();
	vDest.Normalize();

	float fDot = m_vDir.x * vDest.x + m_vDir.y * vDest.y;
	float fAngle = acosf(fDot);

	if (fAngle > PI / 90.f)
	{
		if (GetRotateClock(m_vDir, vDest))
		{
			m_vDir = Rotate(m_vDir, m_fRotateSpeed * DT);
		}
		else
		{
			m_vDir = Rotate(m_vDir, -m_fRotateSpeed * DT);
		}
	}

	float fSpeed = GetSpeed();
	m_vVelocity = m_vDir * fSpeed;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;
	SetPos(vPos);
}

void Guided::BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	if (dynamic_cast<Monster*>(_OtherObj))
	{
		Destroy();
	}
}