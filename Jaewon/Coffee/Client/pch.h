#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
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
using std::make_pair;
using std::string;
using std::wstring;

// 싱글턴 매크로 함수 헤더
#include "define.h"

// 좌표 float 구조체 구현
#include "struct.h"