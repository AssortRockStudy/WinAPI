#include "pch.h"
#include "Movement.h"
#include "CObj.h"

void Movement::finalTick(float _DT)
{
	accel = force / mass;

	if (gravityOn && !onGround){
		accel += gravity;
	}

	if (velocity.Length() < 0.1f)
	{
		if (!accel.isZero()){
			Vec2 vAccelDir = accel;
			vAccelDir.Normalize();
			velocity = vAccelDir * initSpeed;
		}
	}
	else
		velocity += accel * _DT;


	if (fabs(velocity.x) > maxSpeed)
		velocity.x = (velocity.x / fabs(velocity.x)) * maxSpeed;


	if (force.isZero() && velocity.x != 0.f && onGround){
		float fFriction = - velocity.x;
		fFriction /= fabs(fFriction);

		fFriction *= friction;

		float fFrictionAccel = (fFriction / mass) * _DT;
		if (fabs(velocity.x) < fabs(fFrictionAccel))
			velocity = Vec2(0.f, velocity.y);
		else
			velocity.x += fFrictionAccel;
	}

	Vec2 vObjPos = getOwner()->getPos();
	vObjPos += velocity * _DT;
	getOwner()->setPos(vObjPos);

	force = Vec2(0.f, 0.f);
}

Movement::Movement(CObj* _Owner):Component(_Owner), mass(1.f), initSpeed(0.f), maxSpeed(0.f), friction(0.f), gravityOn(false), onGround(false){}

Movement::~Movement(){}
