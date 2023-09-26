#include "pch.h"
#include "MyObject.h"

#include "MyEngine.h"

#include "MyComponent.h"

MyObject::MyObject() : m_LayerIdx(-1)
{

}

MyObject::~MyObject()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
		{
			delete m_vecComponent[i];
		}
	}
}


void MyObject::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void MyObject::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}

void MyObject::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->render(_dc);
	}

	if (!DEBUG_RENDER)
	{
		return;
	}

	SELECT_PEN(_dc, PEN_TYPE::RED_PEN);

	Vec2 vRenderPos = GetRenderPos();
	// 현재 위치를 지정된 점으로 이동시키는 함수
	MoveToEx(_dc, int(vRenderPos.x - 7.f), int(vRenderPos.y), nullptr);
	// 현재 위치부터 지정된 점까지 선을 그리는 함수
	LineTo(_dc, int(vRenderPos.x + 7.f), int(vRenderPos.y));

	MoveToEx(_dc, int(vRenderPos.x), int(vRenderPos.y - 7.f), nullptr);
	LineTo(_dc, int(vRenderPos.x), int(vRenderPos.y + 7.f));
}

void MyObject::Destroy()
{
	FTask task;

	task.Type = TASK_TYPE::DELETE_OBJECT;
	task.Param1 = (INT_PTR)this;

	MyTaskMgr::GetInst()->AddTask(task);
}


void MyObject::SetDead()
{
	m_Dead = true;

	// 오브젝트만 Dead 상태가 되면 오브젝트는 사라져도 여전히 충돌 중이라는 결과가 나온다
	// 이를 해결하기 위해 컴포넌트 또한 Dead 상태로 바꿔준다
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->m_Dead = true;
	}

}