#include "pch.h"
#include "Movement.h"

Movement::Movement(Obj* _Owner)
	: Component(_Owner)
	, m_Mass(0.f)
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
}
