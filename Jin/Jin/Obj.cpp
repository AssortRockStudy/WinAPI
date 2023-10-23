#include "pch.h"
#include "Obj.h"
#include "Component.h"
#include "TaskMgr.h"
#include "Engine.h"

Obj::Obj()
	: m_iLayerIdx(-1)
{
}

Obj::Obj(const Obj& _Origin)
	: Entity(_Origin)
	, m_Pos(_Origin.m_Pos)
	, m_Scale(_Origin.m_Scale)
	, m_iLayerIdx(-1)
{
	for (size_t i = 0; i < _Origin.m_vecComponent.size(); ++i)
	{
		Component* pCom = _Origin.m_vecComponent[i]->Clone();
		pCom->m_pOwner = this;
	}
}

Obj::~Obj()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
			delete m_vecComponent[i];
	}
}

void Obj::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void Obj::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}

void Obj::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, RED_PEN);

	Vec2 vRenderPos = GetRenderPos();
	MoveToEx(_dc, int(vRenderPos.x - 7.f), (int)vRenderPos.y, nullptr);
	LineTo(_dc, int(vRenderPos.x + 7.f), (int)vRenderPos.y);
	MoveToEx(_dc, int(vRenderPos.x), int(vRenderPos.y - 7.f), nullptr);
	LineTo(_dc, int(vRenderPos.x), int(vRenderPos.y + 7.f));

	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->render(_dc);
	}
}

void Obj::Destroy()
{
	FTask task;
	task.Type = TASK_TYPE::DELETE_OBJECT;
	task.Param_1 = (INT_PTR)this;

	TaskMgr::GetInst()->AddTask(task);
}

void Obj::SetDead()
{
	m_bDead = true;
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->m_bDead = true;
	}
}
