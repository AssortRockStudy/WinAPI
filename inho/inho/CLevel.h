#pragma once

#include "CEntity.h"
#include "CLayer.h"

class CObj;

class CLevel : public CEntity {

  private:
    CLayer* m_Layer[LAYER::END];

  public:
    void tick();
    void render(HDC _dc);

  public:
    template <typename T> void GetObjects(vector<T*>& _Out);

    const vector<CObj*>& GetObjects(LAYER _LayerType) {
        return m_Layer[_LayerType]->m_vecObjects;
    }

  private:
    void AddObject(LAYER _LayerType, CObj* _Object);

  public:
    CLevel();
    ~CLevel();

    friend class CLevelMgr;
    friend class CTaskMgr;
};

template <typename T> inline void CLevel::GetObjects(vector<T*>& _Out) {
    for (UINT j = 0; j < LAYER::END; ++j) {
        for (size_t i = 0; i < m_Layer[j]->m_vecObjects.size(); ++i) {
            T* pObj = dynamic_cast<T*>(m_Layer[j]->m_vecObjects[i]);

            if (nullptr != pObj) {
                _Out.push_back(pObj);
            }
        }
    }
}