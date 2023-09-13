#pragma once

// object layer
enum class LAYER
{
	DEFAULT,
	TILE,
	PLAYER,
	MONSTER,
	PLAYER_PJ,
	MONST_PJ,
	WORLD_STATIC,



	END,
};


enum class TASK_TYPE
{
	// Param1 : Layer Type, Param2 : Object Adress
	CREATE_OBJECT,

	// Param1 : Object Adress
	DELETE_OBJECT,
	LEVEL_CHANGE,


	END,
};

// Palette
enum class BRUSH_TYPE
{
	RED,
	GREEN,
	BLUE,
	BLACK,
	END,
};
enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

// KeyMgr
enum class KEY_STATE
{
	NONE,
	TAP,
	PRESSED,
	RELEASED,
	END,
};
enum class KEY
{
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,

	NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,

	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,

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
