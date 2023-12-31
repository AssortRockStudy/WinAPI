#include "pch.h"
#include "CPlatform.h"

#include "components.h"


CPlatform::CPlatform()
{
	m_pCollider = AddComponent<CCollider>(L"Collider");

	//m_Collider->SetOffsetPos();
	m_pCollider->SetScale(Vec2(800.f, 100.f));
}

CPlatform::~CPlatform()
{

}

void CPlatform::tick(float _DT)
{

}

void CPlatform::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	float up = (_OwnCol->GetScale().y / 2.f + _OtherCol->GetScale().y / 2.f - abs(_OwnCol->GetPos().y - _OtherCol->GetPos().y)) / 2.f;
	_OtherObj->SetPos(Vec2(_OtherObj->GetPos().x, _OtherObj->GetPos().y - up));
}