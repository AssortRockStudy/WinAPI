#include "pch.h"
#include "CMovement.h"

CMovement::CMovement(CObj* _Owner)
	: CComponent(_Owner)
	, m_Mass(0.f)
	, m_InitSpeed(0.f)
	, m_MaxSpeed(0.f)
	, m_FrictionScale(0.f)
	, m_UseGravity(0.f)
	, m_Ground(false)
{
}

CMovement::~CMovement()
{

}

void CMovement::finaltick(float _DT)
{

}