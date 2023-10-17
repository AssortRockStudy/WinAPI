#pragma once
class Entity
{
private:
	static UINT_PTR g_NextID;
	const UINT_PTR m_ID;
	wstring					  m_strName;
	bool						  m_bDead;

public:
	UINT_PTR GetID()
	{
		return m_ID;
	}
	void SetName(const wstring& _StrName)
	{
		m_strName = _StrName;
	}
	const wstring& GetName()
	{
		return m_strName;
	}
	bool IsDead()
	{
		return m_bDead;
	}

public:
	virtual Entity* Clone()
	{
		return nullptr;
	}


public:
	Entity();
	Entity(const Entity& _other);
	virtual ~Entity();

	friend class TaskMgr;
	friend class Obj;
};

