#pragma once


#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include <vector>
#include <list>
#include <map>
#include <string>
#include <crtdbg.h>
#include <assert.h>


#pragma comment(lib, "Msimg32.lib")


using std::vector;
using std::list;
using std::map;
using std::string;
using std::wstring;
using std::make_pair;

//순서 의존성 해결?
#define RGB_BLACK   (RGB(0, 0, 0))
#define RGB_RED		(RGB(255, 0, 0))
#define RGB_GREEN	(RGB(0, 255, 0))
#define RGB_BLUE	(RGB(0, 0, 255))
#define RGB_WHITE	(RGB(255, 255, 255))
#define RGB_YELLOW	(RGB(255, 255, 0))

//enum 선언이유= pen 인덱스 체크용(사람실수)
enum COLOR
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	WHITE,
	YELLOW,
};


#include "global.h"