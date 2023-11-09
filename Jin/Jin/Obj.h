#pragma once
#include "Entity.h"
#include "TaskMgr.h"
#include "Camera.h"
#include "components.h"

class Component;
class Collider;

class Obj : public Entity
{
private:
	Vec2			m_Pos;
	Vec2			m_Scale;
	vector<Component*> m_vecComponent;
	int			m_iLayerIdx;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	Vec2 GetRenderPos()
	{
		return Camera::GetInst()->GetRenderPos(m_Pos);
	}

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	int GetLayerIdx()
	{
		return m_iLayerIdx;
	}

public:
	virtual void begin() {};
	virtual void tick(float _DT);
	virtual void finaltick(float _DT) final; // 여기서 막아버리기
	virtual void render(HDC _dc);
	void Destroy();

	virtual void BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol) {}
	virtual void Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol) {}
	virtual void EndOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol) {}


private:
	void SetDead();

protected:
	template<typename T>
	T* AddComponent(const wstring& _strName = L"")
	{
		T* pNewComponent = new T(this);
		m_vecComponent.push_back(pNewComponent);
		pNewComponent->SetName(_strName);
		return pNewComponent;
	}
public:
	template<typename T>
	T* GetComponent()
	{
		for (size_t i = 0; i < m_vecComponent.size(); ++i)
		{
			if (dynamic_cast<T*>(m_vecComponent[i]))
			{
				return (T*)m_vecComponent[i];
			}
		}
		return nullptr;
	}


	template<typename T>
	void GetComponents(vector<T*>& _Out)
	{
		for (size_t i = 0; i < m_vecComponent.size(); ++i)
		{
			if (dynamic_cast<T>(m_vecComponent[i]))
			{
				_Out.push_back((T*)m_vecComponent[i]);
			}
		}
	}

public:
	virtual Obj* Clone() = 0;
	Obj();
	Obj(const Obj& _Origin);
	virtual ~Obj();

	friend class Level;
	friend class TaskMgr;
};

