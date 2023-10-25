#pragma once

class CTexture;

enum class CAM_EFFECT {
    FADE_IN,
    FADE_OUT,
    NONE,
};

class CCamera {
    SINGLETON(CCamera);

  private:
    Vec2 m_vLookAt;
    Vec2 m_vDiff;
    CTexture* m_Veil;

    float m_AccTime;
    float m_DestTime;
    CAM_EFFECT m_CamEffectType;

    UINT m_Alpha;

  public:
    void tick();
    void render(HDC _dc);
    void SetLookAt(Vec2 _vLookAt) { m_vLookAt = _vLookAt; }

    void FadeIn(float _time) {
        m_DestTime = _time;
        m_AccTime = 0.f;
        m_CamEffectType = CAM_EFFECT::FADE_IN;
    }

    void FadeOut(float _time) {
        m_DestTime = _time;
        m_AccTime = 0.f;
        m_CamEffectType = CAM_EFFECT::FADE_OUT;
    }

    Vec2 GetRenderPos(Vec2 _vRealPos) { return _vRealPos - m_vDiff; }
    Vec2 GetRealPos(Vec2 _vRenderPos) { return _vRenderPos + m_vDiff; }
};
