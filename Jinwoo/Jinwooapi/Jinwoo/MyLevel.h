#pragma once

#include "MyEntity.h"
#include "MyLayer.h"

class MyObject;

// 오브젝트를 관리해주는 게임 스테이지의 역할을 하는 클래스
class MyLevel : public MyEntity
{
private:
	// 모든 오브젝트는 MyObject를 상속받기 때문에 MyObject의 포인터를 받으면
	// 하위 클래스들을 모두 관리할 수 있다
	// vector<MyObject*> m_vecObject;

	MyLayer*	m_Layer[(UINT_PTR)LAYER::END];

	UINT		m_TileRow;
	UINT		m_TileCol;
	
public:
	virtual void init() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;

	virtual void begin();
	virtual void tick();
	virtual void render(HDC _dc);

public:
	template <typename T>
	void GetObjects(vector<T*>& _Object);

	// 레벨이 소유하고 있는 특정 레이어의 오브젝트 목록을 반환
	const vector<MyObject*>& GetObjects(LAYER _LayerType) { return m_Layer[(UINT)_LayerType]->m_vecObject; }

	MyLayer* GetLayer(int _LayerIdx)
	{
		assert(!(_LayerIdx < 0 || (int)LAYER::END <= _LayerIdx));
		return m_Layer[_LayerIdx];
	}

protected:
	void AddObject(LAYER _LayerType, MyObject* _Object);
	void DeleteAllObjects();
	void DeleteObjectsByLayer(LAYER _Layer);

public:
	void CreateTile(UINT _Row, UINT _Col);

public:
	MyLevel();
	~MyLevel();

	friend class MyLevelMgr;
	friend class MyTaskMgr;
};


// 템플릿으로 선언한 이유 -> 오브젝트 클래스를 상속받는 다른 모든 클래스에서도 사용하기 위해
// 인자를 레퍼런스로 받기 때문에 원본에 접근할 수 있다

// 특정 오브젝트가 생성되면 MyObject 클래스의 AddObject함수로 해당 객체에 push_back으로 추가한다
// 따라서 객체가 생성된 만큼(즉, m_vecObject의 사이즈만큼) 반복문을 돌아서
// 자신이 원하는 객체 클래스로 다운 캐스팅하여 대입한다

// 이때, dynamic_cast를 하는 이유는 m_vecObject는 MyObject의 자료형을 가지고 있는데
// 형변환을 안전하게 해주기 위하여 dynamic_cast를 사용한다
// 만일 다른 객체를 대입하려 할 경우 오류를 발생시켜 미연에 방지할 수 있다

// pObject가 nullptr이 아니라면 객체가 있었다는 것이므로 이를 인자로 받은 객체에 push_back하여
// 목록을 받아올 수 있도록 한다
template<typename T>
inline void MyLevel::GetObjects(vector<T*>& _Object)
{
	for (UINT j = 0; j < (UINT)LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_Layer[j]->m_vecObject.size(); ++i)
		{
			T* pObject = dynamic_cast<T*>(m_Layer[j]->m_vecObject[i]);

			if (nullptr != pObject)
			{
				_Object.push_back(pObject);
			}
		}
	}
}
