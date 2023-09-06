#pragma once
class CTimeMgr {

    SINGLETON(CTimeMgr);

  private:
    LARGE_INTEGER m_Frequency;
    LARGE_INTEGER m_PrevCount;
    LARGE_INTEGER m_CurCount;
    float         m_DeltaTime;

  public:
    float GetDeltaTime() { return m_DeltaTime; }

  public:
    void init();
    void tick();
};
