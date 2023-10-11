#include "pch.h"
#include "Platform.h"
#include "components.h"

Platform::Platform()
{
	m_Collider = AddComponent<Collider>(L"Collider");
	m_Collider->SetScale(Vec2(800.f, 100.f));
}

Platform::~Platform()
{

}

void Platform::tick(float _DT)
{

}

void Platform::Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	float up = (_OwnCol->GetScale().y / 2.f + _OtherCol->GetScale().y / 2.f - fabs(_OwnCol->GetPos().y - _OtherCol->GetPos().y)) / 2.f;
	_OtherObj->SetPos(Vec2(_OtherObj->GetPos().x, _OtherObj->GetPos().y - up));
}
