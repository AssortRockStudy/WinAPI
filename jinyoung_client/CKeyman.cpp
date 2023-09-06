#include "pch.h"
#include "CKeyman.h"

void CKeyman::init()
{
	//capacity만늘림
	m_vecKeyData.reserve(KEY::KEY_END);

	//공간과 데이터를 공백으로 다채움(구조체)
	//m_vecKeyData.resize(KEY::KEY_END);
}

void CKeyman::tick()
{
}


CKeyman::CKeyman()
{
}

CKeyman::~CKeyman()
{
}