#include "pch.h"
#include "Platform.h"
#include "Collider.h"

void Platform::tick(float _DT)
{
}

void Platform::overLap(Collider* mycol, CObj* _othObj, Collider* _othCol)
{
	float up = (mycol->getScale().y / 2.f + _othCol->getScale().y / 2.f - fabs(mycol->getPos().y - _othCol->getPos().y)) / 2.f;
	_othObj->setPos(Vec2(_othObj->getPos().x, _othObj->getPos().y - up));
}

Platform::Platform()
{
	mCollider = addComponent<Collider>(L"Collider");
	mCollider->setScale(Vec2(800.f, 100.f));
}

Platform::~Platform()
{
}
