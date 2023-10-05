#pragma once
class Entity
{
private:
	static UINT_PTR g_NextID;
	const UINT_PTR m_ID;

public:
	UINT_PTR GetID()
	{
		return m_ID;
	}

	virtual Entity* Clone()
	{
		return nullptr;
	}

public:
	Entity();
	Entity(const Entity& _other);
	virtual ~Entity();
};

