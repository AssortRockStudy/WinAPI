#pragma once

#include "MyObject.h"

class MyCollider;
class MyTexture;
class MyAnimator;
class MyMovement;

class MyPlayer : public MyObject
{
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;

	MyCollider* m_Collider;
	MyTexture*	m_Texture;
	MyAnimator* m_Animator;
	MyMovement* m_Movement;
	
public:
	virtual void tick(float _DT) override;

	virtual void BeginOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;
	virtual void EndOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
	MyPlayer();
	~MyPlayer();
};

