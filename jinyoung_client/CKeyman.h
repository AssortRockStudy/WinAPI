#pragma once

// CKeyman
// ~ Ű�� ���°� ����(TAP,PRESSED,RELEASED,NONE)
//�����Ӵ� Ű�� ����ȭó�� ����

enum KEY
{
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
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

	KEY_END,

};

enum KEY_STATE
{
	TAP,
	PRESSED, 
	RELEASED, 
	NONE,
};

class CKeyman
{
	SINGLETON(CKeyman);
	vector<FKeyData> m_vecKeyData;


public:
	void init();
	void tick();


private:


};

