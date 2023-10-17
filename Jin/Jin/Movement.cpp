#include "pch.h"
#include "Movement.h"
#include "Obj.h"

Movement::Movement(Obj* _Owner)
	: Component(_Owner)
	, m_Mass(1.f)
	, m_InitSpeed(0.f)
	, m_MaxSpeed(0.f)
	, m_FrictionScale(0.f)
	, m_UseGravity(0.f)
	, m_Ground(false)
{
}

Movement::~Movement()
{
}

void Movement::finaltick(float _DT)
{
	m_Accel = m_Force / m_Mass;

	if (m_UseGravity && !m_Ground)
	{
		m_Accel += m_GravityForce;
	}

	if (m_Velocity.Length() < 0.1f)
	{
		if (!m_Accel.IsZero())
		{
			Vec2 vAccelDir = m_Accel;
			vAccelDir.Normalize();
			m_Velocity = vAccelDir * m_InitSpeed;
		}
	}
	else
	{
		m_Velocity += m_Accel * _DT;
	}

	if (fabs(m_Velocity.x) > m_MaxSpeed)
	{
		m_Velocity.x = (m_Velocity.x / fabs(m_Velocity.x)) * m_MaxSpeed;
	}

	if (m_Force.IsZero() && m_Velocity.x != 0.f && m_Ground)
	{
		//Vec2 vFriction = -m_Velocity;
		//vFriction.Normalize();
		//vFriction *= m_FrictionScale;

		//Vec2 vFrictionAccel = (vFriction / m_Mass) * _DT;
		//if (m_Velocity.Length() < vFrictionAccel.Length())
		//{ // 슬라이딩 방지
		//	m_Velocity = Vec2(0.f, 0.f);
		//}
		//else
		//{
		//	m_Velocity += vFrictionAccel;
		//}
		float fFriction = -m_Velocity.x;
		fFriction /= fabs(fFriction);

		fFriction *= m_FrictionScale;

		float fFrictionAccel = (fFriction / m_Mass) * _DT;
		if (fabs(m_Velocity.x) < fabs(fFrictionAccel))
		{
			m_Velocity = Vec2(0.f, m_Velocity.y);
		}
		else
		{
			m_Velocity.x += fFrictionAccel;
		}
	}
	Vec2 vObjPos = GetOwner()->GetPos();
	vObjPos += m_Velocity * _DT;
	GetOwner()->SetPos(vObjPos);

	m_Force = Vec2(0.f, 0.f);

}
