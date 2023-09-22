#pragma once

#include "CCamera.h"
#include "CEntity.h"
#include "CTaskMgr.h"

class CCollider;

class CObj : public CEntity {
  private:
    Vec2                      m_Pos;
    Vec2                      m_Scale;
    vector<class CComponent*> m_vecComponent;
    int m_iLayerIdx;
    bool m_bDead;

  public:
    Vec2 GetPos() { return m_Pos; }
    Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_Pos); }
    Vec2 GetScale() { return m_Scale; }

    void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
    void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
    
    int GetLayerIdx() { return m_iLayerIdx; }
    bool IsDead() { return m_bDead; }

  protected:
    template <typename T> T* AddComponent(const wstring& _strName = L"") {
        T* pNewCom = new T(this);
        m_vecComponent.push_back(pNewCom);
        pNewCom->SetName(_strName);
        return pNewCom;
    }

  public:
      virtual void begin() {};
    virtual void tick(float _DT);
    virtual void finaltick(float _DT) final;
    virtual void render(HDC _dc);

    void Destroy();

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) {}
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) {}
    virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) {}

  private:
    virtual void Abstract() = 0;

  public:
    CObj();
    virtual ~CObj();

    friend class CLevel;
    friend class CTaskMgr;
};
