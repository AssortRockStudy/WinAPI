#include "pch.h"
#include "KeyMgr.h"
#include "Engine.h"

KeyMgr::KeyMgr() {}
KeyMgr::~KeyMgr() {}

int g_KeySync[KEY::KEY_END] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

	VK_NUMPAD0, VK_NUMPAD1,
	VK_NUMPAD2, VK_NUMPAD3,
	VK_NUMPAD4, VK_NUMPAD5,
	VK_NUMPAD6, VK_NUMPAD7,
	VK_NUMPAD8, VK_NUMPAD9,

	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',

	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',

	'Z', 'X', 'C', 'V', 'B', 'N', 'M',

	VK_TAB, VK_LSHIFT, VK_LMENU,
	VK_LCONTROL, VK_SPACE,
	
	VK_ESCAPE, VK_RETURN, VK_BACK,

	VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,

	VK_LBUTTON, VK_RBUTTON
};


void KeyMgr::init()
{
	m_vecKeyData.reserve(KEY::KEY_END);

	for (UINT i = 0; i < KEY_END; ++i)
	{
		m_vecKeyData.push_back(FKeyData{(KEY)i, NONE, false});
	}
}

void KeyMgr::tick()
{ 
	for (size_t i = 0; i < m_vecKeyData.size(); ++i)
	{	// 매 틱마다 모든 키보드 키를 검사하는데 눌린 키가 있다? 
		if (GetAsyncKeyState(g_KeySync[m_vecKeyData[i].eKey]) & 0X8001)
		{
			if (m_vecKeyData[i].bPressed)
			{
				m_vecKeyData[i].eState = PRESSED;
			}
			else
			{
				m_vecKeyData[i].eState = TAP;
			}
			m_vecKeyData[i].bPressed = true;
		}
		else
		{
			if (m_vecKeyData[i].bPressed)
			{
				m_vecKeyData[i].eState = RELEASED;
			}
			else
			{
				m_vecKeyData[i].eState = NONE;
			}
			m_vecKeyData[i].bPressed = false;
		}
	}

	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(Engine::GetInst()->GetMainWind(), &pt);
	m_vMousePos = pt;
}