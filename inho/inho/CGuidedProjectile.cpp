#include "pch.h"

#include "CGuidedProjectile.h"
#include "CLevelMgr.h"
#include "CLevel.h"
#include "CMonster.h"
#include "CTimeMgr.h"


CGuidedProjectile::CGuidedProjectile() :
	target(nullptr), 
	m_fMass(1.f), 
	m_fRotateSpeed(PI) 
{}

CGuidedProjectile::~CGuidedProjectile() {}

void CGuidedProjectile::tick(float _dt)
{

	if (nullptr == target) {
		FindTarget();
	}

	else {
		//Update_1();
		 //Update_2();
		 Update_3();		
	}
}


void CGuidedProjectile::FindTarget() {
	
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	const vector<CObj*>& vecMon = pCurLevel->GetObjects(LAYER::MONSTER);

	if (vecMon.empty()) {
		return;
	}
	else if (vecMon.size() == 1) {
		target = dynamic_cast<CMonster*>(vecMon.front());

		assert(target);
	}
	else {
		float fMax = 2000.f;
		
		for (size_t i = 0; i < vecMon.size(); ++i) {
			float fDistance = GetPos().Distance(vecMon[i]->GetPos());
			if (fMax > fDistance) {
				fMax = fDistance;

				target = dynamic_cast<CMonster*>(vecMon[i]);
				assert(target);
			}
		}
	}
}

void CGuidedProjectile::Update_1() {
	Vec2 vPos = GetPos();
	Vec2 vDir = target->GetPos() - vPos;
	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);
}

void CGuidedProjectile::Update_2() {
	float Force = 1000.f;
	Vec2 vForce = target->GetPos() - GetPos();
	vForce.Normalize() *= Force;

	m_vAccel = vForce / m_fMass;

	m_vVelocity += m_vAccel * DT;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;

	SetPos(vPos);
}

void CGuidedProjectile::Update_3() {
	
	m_vDir.Normalize();

	// �������� ���ϴ� ���⺤��
	Vec2 vDest = target->GetPos() - GetPos();
	vDest.Normalize();

	// ���� ���� ����� �������� ���ϴ� ������ �����ؼ� �� ������ ������ ���Ѵ�.
	// m_vDir �� vDest �� ����, vA �� vB == |vA| * |vB| * cos(@)
	float fDot = m_vDir.x * vDest.x + m_vDir.y * vDest.y;
	float fAngle = acosf(fDot);
	float pi = PI;
	float diff =PI / 90.f;
	// ���� ����� �������� ���ϴ� ������ ���� 1�� �̳��� ������ ���̻� ��������� ȸ������ �ʴ´�.
	if (fAngle > (PI / 90.f))
	{
		// Ÿ���� ���ؼ� ������ ȸ���Ѵ�.
		if (GetRotateClock(m_vDir, vDest))
		{
			m_vDir = Rotate(m_vDir, m_fRotateSpeed * DT);
		}
		else
		{
			m_vDir = Rotate(m_vDir, -m_fRotateSpeed * DT);
		}
	}
	else {

	}

	// ���� ������ ���ؼ� �̵��Ѵ�.
	float fSpeed = GetSpeed();
	m_vVelocity = m_vDir * fSpeed;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;
	SetPos(vPos);
}