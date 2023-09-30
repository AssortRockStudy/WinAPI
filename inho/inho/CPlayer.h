#pragma once
#include "CObj.h"

class CPlayer : public CObj {
    GENERATED_OBJECT(CObj);

  private:

    float m_Speed;

    class CCollider* m_Collider;
    class CAnimator* m_Animator;
    class CMovement* m_Movement;

  public:
    virtual void tick(float _DT) override;
    
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

  public:
    CPlayer();
    ~CPlayer();
};
