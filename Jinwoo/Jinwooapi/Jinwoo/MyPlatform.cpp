#include "pch.h"
#include "MyPlatform.h"

#include "components.h"

MyPlatform::MyPlatform()
{
	m_Collider = AddComponent<MyCollider>(L"Collider");
	m_Collider->SetOffsetScale(Vec2(800.f, 100.f));
}

MyPlatform::~MyPlatform()
{

}

void MyPlatform::tick(float _DT)
{
}

void MyPlatform::Overlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol)
{
	float up = (_OwnCol->GetOffsetScale().y / 2.f + _OtherCol->GetOffsetScale().y / 2.f - fabs(_OwnCol->GetFinalPos().y - _OtherCol->GetFinalPos().y)) / 2.f;

	_OtherObject->SetPos(Vec2(_OtherObject->GetPos().x, _OtherObject->GetPos().y - up));
}