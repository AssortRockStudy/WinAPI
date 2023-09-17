#pragma once

#include "CTaskMgr.h"
#include "CEntity.h"
#include "CCamera.h"

class CObj: public CEntity {
  private:
    Vec2 m_Pos;
    Vec2 m_Scale;
    vector<class CComponent*> m_vecComponent;

  public:
    Vec2 GetPos() { return m_Pos; }
    Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_Pos); }
    Vec2 GetScale() { return m_Scale; }

    void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
    void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

protected:
    template <typename T>
    T* AddComponent() {
        T* pNewCom = new T(this);
        m_vecComponent.push_back(pNewCom);
        return pNewCom;
    }

  public:
    virtual void tick(float _DT);
    virtual void finaltick(float _DT) final;
    virtual void render(HDC _dc);

private:
    virtual void Abstract() = 0;

  public:
    CObj();
    virtual ~CObj();
};
