#include "pch.h"
#include "Obj.h"
#include "Component.h"
#include "TaskMgr.h"


Obj::Obj()
	: m_iLayerIdx(-1)
	, m_bDead(false)
{
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
