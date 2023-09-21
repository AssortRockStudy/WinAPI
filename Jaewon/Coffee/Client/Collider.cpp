#include "pch.h"
#include "Collider.h"
#include "CObj.h"

void Collider::finalTick(float _dt)
{
	Vec2 ownerPos = getOwner()->getPos();
	finalPos = ownerPos + offsetPos;
}

Collider::Collider(CObj* _owner):Component(_owner){}
Collider::~Collider(){}
