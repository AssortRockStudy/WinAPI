#include "pch.h"
#include "CMovement.h"

#include "CObj.h"

CMovement::CMovement(CObj* _Owner):
	CComponent(_Owner),
	m_Mass(1.f),
	m_InitSpeed(0.f),
	m_MaxSpeed(0.f),
	m_FrictionScale(0.f),
	m_UseGravity(0.f),
	m_Ground(false)
{
}

CMovement::~CMovement()
{
}


void CMovement::finaltick(float _DT)
{
	m_Accel = m_Force / m_Mass;

	if (m_Velocity.Length() < 0.1f) {
		if (!m_Accel.IsZero()) {
			Vec2 vAccelDir = m_Accel;
			vAccelDir.Normalize();
			m_Velocity = vAccelDir * m_InitSpeed;
		}
	}
	else {
		m_Velocity += m_Accel * _DT;
	}

	if (m_Velocity.Length() > m_MaxSpeed) {
		m_Velocity = m_Velocity.Normalize() * m_MaxSpeed;
	}

	if (m_Force.IsZero() && !m_Velocity.IsZero()) {
		Vec2 vFriction = -m_Velocity;
		vFriction.Normalize();
		vFriction *= m_FrictionScale;

		Vec2 vFrictionAccel = (vFriction / m_Mass) * _DT;
		if (m_Velocity.Length() < vFriction.Length()) {
			m_Velocity = Vec2(0.f, 0.f);
		}
		else {
			m_Velocity += vFrictionAccel;
		}
	}

	Vec2 vObjPos = GetOwner()->GetPos();

	vObjPos += m_Velocity * _DT;
	GetOwner()->SetPos(vObjPos);

	m_Force = Vec2(0.f, 0.f);

}