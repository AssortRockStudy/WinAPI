#include "pch.h"
#include "KeyMgr.h"

int g_KeySync[KEY::KEY_END] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',

	VK_NUMPAD0,
	VK_NUMPAD1,
	VK_NUMPAD2,
	VK_NUMPAD3,
	VK_NUMPAD4,
	VK_NUMPAD5,
	VK_NUMPAD6,
	VK_NUMPAD7,
	VK_NUMPAD8,
	VK_NUMPAD9,

	'Q',
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
	VK_LMENU,
	VK_LCONTROL,
	VK_SPACE,

	VK_ESCAPE,
	VK_RETURN,
	VK_BACK,

	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
};

KeyMgr::KeyMgr() {}
KeyMgr::~KeyMgr(){}

void KeyMgr::init()
{
	vecKeyData.reserve(KEY::KEY_END);
	for (UINT i = 0; i < KEY_END; ++i) {
		vecKeyData.push_back(FKeyData{ (KEY)i, NONE, false });
	}
}

// 4가지 상황 확인 후 업데이트
// 1. 지금 tick에 눌림 + 전 tick에 눌려있었음 > pressed
// 2. 지금 tick에 눌림 + 전 tick에 안눌려있었음 > tap
// 3. 지금 tick에 안눌림 + 전 tick에 눌려있었음 > release
// 4. 지금 tick에 안눌림 + 전 tick에 안눌림 > None
void KeyMgr::tick()
{
	for (size_t i = 0; i < vecKeyData.size(); ++i) {
		if (GetAsyncKeyState(g_KeySync[vecKeyData[i].key]) & 0x8001) {
			if (vecKeyData[i].isPressed)
				vecKeyData[i].state = PRESSED;
			else
				vecKeyData[i].state = TAP;
			vecKeyData[i].isPressed = true;
		}
		else {
			if (vecKeyData[i].isPressed)
				vecKeyData[i].state = RELEASED;
			else
				vecKeyData[i].state = NONE;
			vecKeyData[i].isPressed = false;
		}
	}
}
