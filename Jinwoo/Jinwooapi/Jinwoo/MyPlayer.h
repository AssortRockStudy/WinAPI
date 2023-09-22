#pragma once

#include "MyObject.h"

class MyCollider;
class MyTexture;
class MyAnimator;

class MyPlayer : public MyObject
{
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;

	MyCollider* m_Collider;
	MyTexture*	m_Texture;
	MyAnimator* m_Animator;
	
public:
	virtual void tick(float _DT) override;

	virtual void Overlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
	MyPlayer();
	~MyPlayer();
};

