#include "pch.h"
#include "CObj.h"
#include "CComponent.h"

#include "CEngine.h"



CObj::CObj()
	: m_iLayerIdx(-1)
{
}

CObj::~CObj()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
			delete m_vecComponent[i];
	}
}
void CObj::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void CObj::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}
void CObj::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->render(_dc);
	}

	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, RED_PEN);

	Vec2 vRenderPos = GetRenderPos();
	MoveToEx(_dc, int(vRenderPos.x - 7.f), (int)vRenderPos.y, nullptr);
	LineTo(_dc, int(vRenderPos.x + 7.f), (int)vRenderPos.y);

	MoveToEx(_dc, int(vRenderPos.x), int(vRenderPos.y - 7.f), nullptr);
	LineTo(_dc, int(vRenderPos.x), int(vRenderPos.y + 7.f));
	//Vec2 vRenderPos = GetRenderPos();

	//Rectangle(_dc
	//	, int(vRenderPos.x - m_Scale.x / 2)
	//	, int(vRenderPos.y - m_Scale.y / 2)
	//	, int(vRenderPos.x + m_Scale.x / 2)
	//	, int(vRenderPos.y + m_Scale.y / 2));
}

void CObj::Destroy()
{
	FTask task;
	task.Type = TASK_TYPE::DELETE_OBJECT;
	task.Param_1 = (INT_PTR)this;

	CTaskMgr::GetInst()->AddTask(task);
}

void CObj::SetDead()
{
	m_bDead = true;

	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->m_bDead = true;
	}
}