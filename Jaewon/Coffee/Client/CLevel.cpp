#include "pch.h"
#include "CLevel.h"
#include "CObj.h"
#include "CTimeMgr.h"
#include "Monster.h"

// 레벨에 들어있는 오브젝트들의 tick을 다 실행
void CLevel::tick()
{
	for (UINT i = 0; i < LAYER::END; ++i){
		m_Layer[i]->tick();
	}
}

// 레벨에 들어있는 오브젝트들의 render을 다 실행
void CLevel::render(HDC _dc)
{
	for (UINT i = 0; i < LAYER::END; ++i){
		m_Layer[i]->render(_dc);
	}
}

void CLevel::addObject(LAYER _type, CObj* _obj)
{
	m_Layer[_type]->AddObj(_obj);

	_obj->mLayerIdx = _type;
}

CLevel::CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

// vector에 들어 있는 오브젝트들을 다 delete해주어야 됨
CLevel::~CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}
