#pragma once

#define SINGLETON(ClassType)	public:\
									static ClassType* GetInst()\
									{\
										static ClassType engine;\
										return &engine;\
									}\
								public:\
									ClassType* operator = (const ClassType& _other) = delete;\
								private:\
									ClassType();\
									ClassType(const ClassType& _other) = delete;\
								public:\
									~ClassType();

#define KEY_CHECK(Key, State) CKeyMgr::GetInst()->GetKeyState(Key) == State

#define KEY_TAP(Key)		KEY_CHECK(Key, TAP)
#define KEY_PRESSED(Key)	KEY_CHECK(Key, PRESSED)
#define KEY_RELEASED(Key)	KEY_CHECK(Key, RELEASED)
#define KEY_NONE(Key)		KEY_CHECK(Key, NONE)

#define PI 3.14159265348979f

#define GAME_FOLDER MyGame

// Key Value
enum KEY// 컴파일러는 enum class 선언하는 것을 추천
{
	_0, // 숫자 키들
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,

	NUM0, // 넘버패드
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,

	Q, // 문자
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,

	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,

	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	TAB,
	LSHIFT,
	RSHIFT,
	LALT,
	SPACE,

	ESC,
	ENTER,
	BACK,

	LEFT,
	RIGHT,
	UP,
	DOWN,

	KEY_END,

};


enum KEY_STATE
{
	NONE,
	TAP,
	PRESSED,
	RELEASED,
};
