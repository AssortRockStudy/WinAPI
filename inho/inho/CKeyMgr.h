#pragma once
class CKeyMgr {

    SINGLETON(CKeyMgr);

  private:
    vector<FKeyData> m_vecKeyData;

  public:
    KEY_STATE GetKeyState(KEY _Key) { return m_vecKeyData[_Key].eState; }

  public:
    void init();
    void tick();
};
