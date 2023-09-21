#pragma once
#include "CMonster.h"

class CObj; 

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects;

	CMonster* m_Monster1;
	CMonster* m_Monster2;
public:
	void tick();
	void render(HDC _dc);

public:
	// 레벨이 소유하고 있는 모든 레이어를 순회하면서 T 타입에 해당하는 객체를 찾아서 결과(_Out) 벡터에 담아준다.
	template<typename T>
	void GetObjects(vector<T*>& _Out);

	void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

	CMonster* GetMonster1() { return m_Monster1; }
	void SetMonster1(CMonster* mon1) { m_Monster1 = mon1; }

	CMonster* GetMonster2() { return m_Monster2; }
	void SetMonster2(CMonster* mon2) { m_Monster2 = mon2; }

	CMonster* GetCurruntMonster(Vec2 playerPos);
public:
	CLevel();
	~CLevel();
};

template<typename T>
inline void CLevel::GetObjects(vector<T*>& _Out)
{
	// 마지막 레이어 까지 for문 돌기
	for (UINT j = 0; j < LAYER::END; ++j)
	{
		// 레이어의 모든 오브젝트를 T*로 dynamic_cast 
		for (size_t i = 0; i < m_Layer[j]->m_vecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_Layer[j]->m_vecObjects[i]);

			// 만약 nullptr이 아니라면(T* 라면)
			if (nullptr != pObj)
			{
				_Out.push_back(pObj); // 인자로 받아온 벡터에 넣기
			}
		}
	}
}
