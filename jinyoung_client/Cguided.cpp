#include "pch.h"
#include "CGuided.h"

#include "CLevelMgr.h"
#include "CLevel.h"

#include "CMonster.h"
#include "CTimeManager.h"

CGuided::CGuided()
	: m_Target(nullptr)
	, m_fMass(1.f)
	, m_fRotateSpeed(PI)
{
	m_vVelocity = Vec2(0, -300);

}

CGuided::~CGuided()
{
}

void CGuided::tick(float _DT)
{
	Super::tick(_DT);

	if (nullptr == m_Target)
	{
		FindTarget();
	}
	else
	{
		// 1. ����� ���ؼ� �̵��Ѵ�.
		//update1();

		// 2.
		update2();


		// 3.
		//update3();
	}
}


void CGuided::update2()
{
	// ���� ���� ������
	// 1. Ÿ���� ���ϴ� �������� 100�� ũ���� ���� ����
	float Force = 1000.f;
	Vec2 vForce = m_Target->GetPos() - GetPos();
	vForce.Normalize() *= Force;

	// ���ӵ� ���ϱ�
	// F = M * A
	// A = F / M
	m_vAccel = vForce / m_fMass;

	// ���ӵ��� ���ؼ� �ð��� �ӵ��� ��ȭ��
	m_vVelocity += m_vAccel * DT;

	// �Ÿ� = �ӵ� * �ð�
	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;

	SetPos(vPos);
}





void CGuided::update1()
{
	// ����ź���� ���͸� ���ϴ� ������ ���Ѵ�.
	Vec2 vPos = GetPos();


	Vec2 vDir = m_Target->GetPos() - GetPos();
	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);
}

void CGuided::update3()
{
	m_vDir.Normalize();

	// �������� ���ϴ� ���⺤��
	Vec2 vDest = m_Target->GetPos() - GetPos();
	vDest.Normalize();

	// ���� ���� ����� �������� ���ϴ� ������ �����ؼ� �� ������ ������ ���Ѵ�.
	// m_vDir �� vDest �� ����, vA �� vB == |vA| * |vB| * cos(@)
	float fDot = m_vDir.x * vDest.x + m_vDir.y * vDest.y;
	float fAngle = acosf(fDot);

	// ���� ����� �������� ���ϴ� ������ ���� 1�� �̳��� ������ ���̻� ��������� ȸ������ �ʴ´�.
	if (fAngle > PI / 90.f)
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

	// ���� ������ ���ؼ� �̵��Ѵ�.
	float fSpeed = GetSpeed();

	m_vVelocity = m_vDir * fSpeed;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;
	SetPos(vPos);
}



void CGuided::FindTarget()
{
	// ���� ������ �ִ� ������Ʈ�� �߿��� CMonster �κ��� �Ļ��� ��ü����� �޾ƿ´�.
	//vector<CMonster*> vecMon;
	//CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	//pCurLevel->GetObjects<CMonster>(vecMon);
	
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	const vector<CObj*>& vecMon = pCurLevel->GetObjects(LAYER::MONSTER);

	// ���� ��� ��, ����ź�� �� ����� ���͸� Ÿ������ �����Ѵ�.
	if (vecMon.size() == 1)
	{
		//m_Target = vecMon[0];
		m_Target = dynamic_cast<CMonster*>(vecMon[0]);

		// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
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
				m_Target = dynamic_cast<CMonster*>(vecMon[i]);

				// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
				assert(m_Target);
				//m_Target = vecMon[i];
			}
		}
	}
}
