#include "pch.h"
#include "CKeyMgr.h"

int g_Keysync[KEY::KEY_END] = 
{
	'0', // 숫자 키들
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',

	VK_NUMPAD0, // 넘버패드
	VK_NUMPAD1,
	VK_NUMPAD2,
	VK_NUMPAD3,
	VK_NUMPAD4,
	VK_NUMPAD5,
	VK_NUMPAD6,
	VK_NUMPAD7,
	VK_NUMPAD8,
	VK_NUMPAD9,

	'Q', // 문자
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_TAB,
	VK_LSHIFT,
	VK_RSHIFT,
	VK_LMENU,
	VK_SPACE,

	VK_ESCAPE,
	VK_RETURN,
	VK_BACK,

	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

};


void CKeyMgr::init()
{
	// vector 의 Capacity 를 미리 확보. 지금 같은 경우는 KEY의 개수 만큼
	// 
	m_vecKeyData.reserve(KEY::KEY_END);	// reserve() 함수는 배열의 크기를 받아가고, 크기를 미리 확장 시켜놓음.
											// 수용량 늘리기

	//m_vecKeyData.resize(KEY::KEY_END);		// 해당 크기만큼 이미 다 데이터가 채워진 상태가 됨. 
											// => 입력한 데이터까지 기본 데이터로 채워짐 == 개수만 늘리고 인덱스 접근으로 사용

	for (UINT i = 0; i < KEY_END; ++i) 
	{
		m_vecKeyData.push_back(FKeyData{ (KEY)i, NONE, false });
	}// 한 방에 초기화해서 넣기

}

void CKeyMgr::tick()
{
	for (size_t i = 0; i < m_vecKeyData.size(); ++i) 
	{
		if (GetAsyncKeyState(g_Keysync[m_vecKeyData[i].eKey]) & 0x8001)
		{
			// 이번 프레임에 해당 키가 눌려있다 ==> 길게 누르고 있는 상태
			if (m_vecKeyData[i].bPressed)
			{
				// 이전에도 눌려있었다
				m_vecKeyData[i].eState = PRESSED;
			}
			else
			{
				// 이전에는 눌려있지 않았다 ==> 막 눌린 상태
				m_vecKeyData[i].eState = TAP;
			}
			m_vecKeyData[i].bPressed = true;
		}
		else
		{
			// 이번 프레임에 해당 키는 눌려있지 않았다
			if (m_vecKeyData[i].bPressed)
			{
				// 이전에는 눌려있었다 ==> 막 뗀 상태
				m_vecKeyData[i].eState = RELEASED;
			}
			else
			{
				// 이전에도 안눌려있었고 이번 프레임에도 눌려있지 않았다 ==> 아무 것도 아닌 상태
				m_vecKeyData[i].eState = NONE;
			}
			m_vecKeyData[i].bPressed = false;
		}
	}
}

CKeyMgr::CKeyMgr()
{

}
CKeyMgr::~CKeyMgr()
{}