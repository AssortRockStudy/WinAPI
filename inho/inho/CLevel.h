#pragma once

class CObj;
class CMonster;

class CLevel {
  private:
    vector<CObj*> m_vecObjects;
    vector<CMonster*> m_vecMonsters;

  public:
    void tick();
    void render(HDC _dc);

  public:
    void AddObject(CObj* _Object) { m_vecObjects.push_back(_Object); }
    void AddMonster(CMonster* _Monster) { m_vecMonsters.push_back(_Monster); }
    const vector<CMonster*> GetMonsters() { return m_vecMonsters; }

  public:
    CLevel();
    ~CLevel();
};
