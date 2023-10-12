#pragma once
// 첫번째 호출시 객체 생성
// 이후로는 해당 주소 반환
#define SINGLETON(ClassType) public:\
								static ClassType* GetInst() {\
									static ClassType inst;\
									return &inst;\
								}\
								public:\
									ClassType* operator = (const ClassType& _Origin) = delete;\
								private:\
									ClassType();\
									ClassType(const ClassType& _Origin) = delete;\
									~ClassType();

#define CREATEBLACKPEN CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
#define CREATEREDPEN CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
#define CREATEBLACKBRUSH CreateSolidBrush(RGB(0, 0, 0));
#define CREATEREDBRUSH CreateSolidBrush(RGB(255, 0, 0));

#define GENERATED_OBJECT(type) typedef type Super;\
							   virtual void Abstract() override {}


#define DEBUG_RENDER CEngine::GetInst()->chkDebugRender()
#define SELECT_PEN(DC, TYPE) SelectPen tempPenSelect(DC, TYPE)
#define SELECT_BRUSH(DC, hBrush) SelectBrush tempBrushSelect(DC, hBrush)

enum COLOR {
	red,
	blue,
	green,
	black,
};

enum KEY
{
	_0,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,

	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,

	Q,
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
	LALT,
	LCTRL,
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

enum KEYSTATE
{
	NONE,
	TAP,
	PRESSED,
	RELEASED,
};

enum LAYER
{
	DEFAULT,
	TILE,
	PLATFORM,
	PLAYER,
	MONSTER,
	PLAYER_PJ,
	MONSTER_PJ,
	WORLD_STATIC,





	END = 32,
};


enum TASK_TYPE
{
	// Param1 : Layer Type, Param2 : Object Adress
	CREATE_OBJECT,

	// Param1 : Object Adress
	DELETE_OBJECT,


	LEVEL_CHANGE,
};



enum PEN_TYPE
{
	GREEN_PEN,
	BLUE_PEN,
	RED_PEN,

	PEN_END,
};

enum LOG_LEVEL
{
	LOG,
	WARNING,
	ERR,
};

enum class LEVEL_TYPE
{
	START_LEVEL,
	PLAY_LEVEL,
	EDITOR_LEVEL,
	END,
};