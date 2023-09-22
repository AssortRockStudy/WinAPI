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

	// ���� ��� ��, ����ź�� �� ����� ���͸� Ÿ������ �����Ѵ�.
	if (vecMon.size() == 1)
	{
		mTarget = dynamic_cast<Monster*>(vecMon[0]);

		// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
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

				// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
				assert(mTarget);
			}
		}
	}
}

void Guided::Update_1(float _dt)
{
	// ����ź���� ���͸� ���ϴ� ������ ���Ѵ�.
	Vec2 vPos = getPos();

	Vec2 vDir = mTarget->getPos() - getPos();
	vDir.Normalize();

	vPos.x += vDir.x * getSpeed() * _dt;
	vPos.y += vDir.y * getSpeed() * _dt;

	setPos(vPos);
}

void Guided::Update_2(float _dt)
{
	// ���� ���� ������
	// 1. Ÿ���� ���ϴ� �������� 100�� ũ���� ���� ����
	float Force = 1000.f;
	Vec2 vForce = mTarget->getPos() - getPos();
	vForce.Normalize() *= Force;

	// ���ӵ� ���ϱ�
	// F = M * A
	// A = F / M
	mAccel = vForce / mMass;

	// ���ӵ��� ���ؼ� �ð��� �ӵ��� ��ȭ��
	mVelocity += mAccel * _dt;

	// �Ÿ� = �ӵ� * �ð�
	Vec2 vPos = getPos();
	vPos += mVelocity * _dt;

	setPos(vPos);
}

void Guided::Update_3(float _dt)
{
	// ���⺤�͸� ����ȭ�Ѵ�.
	mDir.Normalize();

	// �������� ���ϴ� ���⺤��
	Vec2 vDest = mTarget->getPos() - getPos();
	vDest.Normalize();

	// ���� ���� ����� �������� ���ϴ� ������ �����ؼ� �� ������ ������ ���Ѵ�.
	// m_vDir �� vDest �� ����, vA �� vB == |vA| * |vB| * cos(@)
	float fDot = mDir.x * vDest.x + mDir.y * vDest.y;
	float fAngle = acosf(fDot);

	// ���� ����� �������� ���ϴ� ������ ���� 1�� �̳��� ������ ���̻� ��������� ȸ������ �ʴ´�.
	if (fAngle > M_PI / 90.f)
	{
		// Ÿ���� ���ؼ� ������ ȸ���Ѵ�.
		if (GetRotateClock(mDir, vDest))
		{
			mDir = Rotate(mDir, mRotateSpeed * _dt);
		}
		else
		{
			mDir = Rotate(mDir, -mRotateSpeed * _dt);
		}
	}

	// ���� ������ ���ؼ� �̵��Ѵ�.
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