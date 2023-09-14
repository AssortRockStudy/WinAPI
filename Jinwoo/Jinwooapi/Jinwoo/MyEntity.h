#pragma once

class MyEntity
{
private:
	static UINT_PTR g_NextID;

private:
	const UINT_PTR	m_ID;

public:
	UINT_PTR GetID() { return m_ID; }

	virtual MyEntity* Clone() { return nullptr; }

public:
	MyEntity();
	MyEntity(const MyEntity& _Other);
	virtual ~MyEntity();
};

