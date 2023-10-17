#include "pch.h"
#include "MyMovement.h"

#include "MyObject.h"

MyMovement::MyMovement(MyObject* _Object)
	: MyComponent(_Object)
	, m_Mass(1.f)
	, m_InitSpeed(0.f)
	, m_MaxSpeed(0.f)
	, m_FrictionScale(0.f)
	, m_UseGravity(0.f)
	, m_Ground(false)
{

}

MyMovement::~MyMovement()
{
}

void MyMovement::finaltick(float _DT)
{
	m_Accel = m_Force / m_Mass;

	// 중력옵션 사용
	if (m_UseGravity && !m_Ground)
	{
		m_Accel += m_GravityForce;
	}

	// 정지에 가까운 상태
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

	// 최대 속도 제한
	if (fabs(m_Velocity.x) > m_MaxSpeed)
	{
		m_Velocity.x = (m_Velocity.x / fabs(m_Velocity.x)) * m_MaxSpeed;
	}

	// 물체에 적용되고있는 힘이 없다면 마찰력을 적용
	if (m_Force.IsZero() && m_Velocity.x != 0.f && m_Ground)
	{
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

	// 힘 리셋
	m_Force = Vec2(0.f, 0.f);
}
