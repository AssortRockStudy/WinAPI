#pragma once
class CEntity {
  private:
    static UINT_PTR g_NextID;

  private:
    const UINT_PTR m_ID;
    wstring m_strName;

  public:
    UINT_PTR GetID() { return m_ID; }
    void SetName(const wstring& _strName) { m_strName = _strName; }
    const wstring& GetName() { return m_strName; }

  public:
    virtual CEntity* Clone() { return nullptr; }

  public:
    CEntity();
    CEntity(const CEntity& _other);
    virtual ~CEntity();
};
