#pragma once


#include "targetver.h"
#include "global.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include <vector>
#include <list>
#include <map>
#include <string>


using std::vector;
using std::list;
using std::map;
using std::string;
using std::make_pair;

//���� ������ �ذ�?
#define RGB_BLACK   (RGB(0, 0, 0))
#define RGB_RED		(RGB(255, 0, 0))
#define RGB_GREEN	(RGB(0, 255, 0))
#define RGB_BLUE	(RGB(0, 0, 255))
#define RGB_WHITE	(RGB(255, 255, 255))
#define RGB_YELLOW	(RGB(255, 255, 0))

//enum ��������= pen �ε��� üũ��(����Ǽ�)
enum COLOR
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	WHITE,
	YELLOW,
};