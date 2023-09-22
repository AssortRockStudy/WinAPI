#include "pch.h"
#include "Guided.h"

#include "LevelMgr.h"
#include "CLevel.h"

#include "Monster.h"
#include "CTimeMgr.h"
#include "Collider.h"


void Guided::tick(float _dt)
{
	Super::tick(_dt);
	if (nullptr == mTarget)
	{
		FindTarget();
	}
	else
	{
		// Update_1(_dt);
		Update_2(_dt);
		//Update_3(_dt);
	}
}

void Guided::begin() {
	Super::begin();
	getCollider()->setScale(getScale());
}
void Guided::FindTarget()
{

	CLevel* pCurLevel = LevelMgr::GetInst()->getCurLevel();
	const vector<CObj*>& vecMon = pCurLevel->getObjects(LAYER::MONSTER);

	// 몬스터 목록 중, 유도탄과 더 가까운 몬스터를 타겟으로 지정한다.
	if (vecMon.size() == 1)
	{
		mTarget = dynamic_cast<Monster*>(vecMon[0]);

		// Level 의 Monster Layer 에 Monster 가 아닌 다른 클래스타입의 객체가 들어있었다.
		assert(mTarget);
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
			float fDistance = getPos().Distance(vecMon[i]->getPos());

			if (fMax > fDistance)
			{
				fMax = fDistance;
				mTarget = dynamic_cast<Monster*>(vecMon[i]);

				// Level 의 Monster Layer 에 Monster 가 아닌 다른 클래스타입의 객체가 들어있었다.
				assert(mTarget);
			}
		}
	}
}

void Guided::Update_1(float _dt)
{
	// 유도탄에서 몬스터를 향하는 방향을 구한다.
	Vec2 vPos = getPos();

	Vec2 vDir = mTarget->getPos() - getPos();
	vDir.Normalize();

	vPos.x += vDir.x * getSpeed() * _dt;
	vPos.y += vDir.y * getSpeed() * _dt;

	setPos(vPos);
}

void Guided::Update_2(float _dt)
{
	// 힘에 의한 움직임
	// 1. 타겟을 향하는 방향으로 100의 크기의 힘을 설정
	float Force = 1000.f;
	Vec2 vForce = mTarget->getPos() - getPos();
	vForce.Normalize() *= Force;

	// 가속도 구하기
	// F = M * A
	// A = F / M
	mAccel = vForce / mMass;

	// 가속도에 의해서 시간당 속도가 변화함
	mVelocity += mAccel * _dt;

	// 거리 = 속도 * 시간
	Vec2 vPos = getPos();
	vPos += mVelocity * _dt;

	setPos(vPos);
}

void Guided::Update_3(float _dt)
{
	// 방향벡터를 정규화한다.
	mDir.Normalize();

	// 목적지를 향하는 방향벡터
	Vec2 vDest = mTarget->getPos() - getPos();
	vDest.Normalize();

	// 현재 진행 방향과 목적지를 향하는 방향을 내적해서 둘 사이의 각도를 구한다.
	// m_vDir 과 vDest 를 내적, vA ● vB == |vA| * |vB| * cos(@)
	float fDot = mDir.x * vDest.x + mDir.y * vDest.y;
	float fAngle = acosf(fDot);

	// 진행 방향과 목적지를 향하는 방향이 각도 1도 이내에 들어오면 더이상 진행방향을 회전하지 않는다.
	if (fAngle > M_PI / 90.f)
	{
		// 타겟을 향해서 방향을 회전한다.
		if (GetRotateClock(mDir, vDest))
		{
			mDir = Rotate(mDir, mRotateSpeed * _dt);
		}
		else
		{
			mDir = Rotate(mDir, -mRotateSpeed * _dt);
		}
	}

	// 현재 방향을 향해서 이동한다.
	float fSpeed = getSpeed();
	mVelocity = mDir * fSpeed;

	Vec2 vPos = getPos();
	vPos += mVelocity * _dt;
	setPos(vPos);
}



Guided::Guided()
	: mTarget(nullptr)
	, mMass(1.f)
	, mRotateSpeed(M_PI)
{

}

Guided::~Guided()
{
}