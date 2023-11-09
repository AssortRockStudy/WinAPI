#pragma once
#include "Component.h"
class State;

class StateMachine :
    public Component
{
private:
    map<UINT, State*> m_mapState;
    State* m_pCurState;

    map<wstring, void*> m_mapBlackboard;


public:
    void AddState(UINT _id, State* _State);
    State* FindState(UINT _id);
    void ChangeState(UINT _NextID);

    template<typename T>
    void AddDataToBlackboard(const wstring& _strKey, const T& _Data);
    void* GetDataFromBlackboard(const wstring _strKey);

    virtual void finaltick(float _DT) override;

public:
    CLONE(StateMachine);

    StateMachine(Obj* _Owner);
    StateMachine(const StateMachine& _Origin);
    ~StateMachine();
};

template <typename T>
inline void StateMachine::AddDataToBlackboard(const wstring& _strKey, const T& _Data)
{
    map<wstring, void*>::iterator iter = m_mapBlackboard.find(_strKey);
    if (iter != m_mapBlackboard.end())
    {
        LOG(LOG_LEVEL::ERR, L"!!블랙보드에 해당 데이터 키 이미 있음!!");
        return;
    }

    T* pData = new T;
    *pData = _Data;
    m_mapBlackboard.insert(make_pair(_strKey, pData));
}
