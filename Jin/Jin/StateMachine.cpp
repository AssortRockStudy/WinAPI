#include "pch.h"
#include "StateMachine.h"

#include "State.h"
#include "LogMgr.h"


StateMachine::StateMachine(Obj* _Owner)
	: Component(_Owner)
	, m_pCurState(nullptr)
{
}

StateMachine::StateMachine(const StateMachine& _Origin)
	: Component(_Origin)
	, m_pCurState(nullptr)
{
	for (const auto& pair : _Origin.m_mapState)
	{
		State* pCloneState = pair.second->Clone();
		pCloneState->m_pSM = this;
		m_mapState.insert(make_pair(pair.first, pCloneState));
	}

	if (nullptr != _Origin.m_pCurState)
	{
		UINT ID = _Origin.m_pCurState->GetStateID();
		map<UINT, State*>::iterator iter = m_mapState.find(ID);
		if (iter != m_mapState.end())
		{
			m_pCurState = iter->second;
		}
	}
}

StateMachine::~StateMachine()
{
	for (const auto& pair : m_mapState)
	{
		delete pair.second;
	}

	for (const auto& pair : m_mapBlackboard)
	{
		delete pair.second;
	}
}

void StateMachine::finaltick(float _DT)
{
	if (nullptr != m_pCurState)
	{
		m_pCurState->finaltick(_DT);
	}
}

void StateMachine::AddState(UINT _id, State* _State)
{
	State* pFindState = FindState(_id);

	if (nullptr != pFindState)
	{
		LOG(LOG_LEVEL::ERR, L"!!이미 같은 아이디의 State 가 StateMachine 에 있음!!");
		return;
	}

	m_mapState.insert(make_pair(_id, _State));
	_State->m_pSM = this;


}

State* StateMachine::FindState(UINT _id)
{
	map<UINT, State*>::iterator iter = m_mapState.find(_id);
	if (iter == m_mapState.end())
	{
		return nullptr;
	}
	return iter->second;
}

void StateMachine::ChangeState(UINT _NextID)
{
	State* pNextState = FindState(_NextID);

	if (nullptr == pNextState)
	{
		LOG(LOG_LEVEL::ERR, L"!!변경할 다음 상태가 없음!!");
		return;
	}

	if (nullptr != m_pCurState)
	{
		m_pCurState->Exit();
	}

	m_pCurState = pNextState;
}

void* StateMachine::GetDataFromBlackboard(const wstring _strKey)
{
	map<wstring, void*>::iterator iter = m_mapBlackboard.find(_strKey);
	if (iter == m_mapBlackboard.end())
	{
		LOG(LOG_LEVEL::ERR, L"!!블랙보드에 해당 키 데이터 없음!!");
		return nullptr;
	}
	return iter->second;
}


