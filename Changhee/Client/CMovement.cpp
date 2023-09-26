#include "pch.h"
#include "CMovement.h"

CMovement::CMovement(CObj* _Owner)
	: CComponent(_Owner)
	, m_fMass(0.f)
	, m_fInitSpeed(0.f)
	, m_fMaxSpeed(0.f)
	, m_fFrictionScale(0.f)
	, m_bUseGravity(0.f)
	, m_bGround(false)
{
}

CMovement::~CMovement()
{
}

void CMovement::finaltick(float _DT)
{
}
