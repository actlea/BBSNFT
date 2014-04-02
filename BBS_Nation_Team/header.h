#pragma once
#include "string/ci_string.h"
#include "string/debug.h"
#include "string/utils.h"
#include "string/Extensions.h"
//Table
#include "./table/StringPlus.h"
#include "./table/Table.h"

#include <WinSock2.h>
#include<iostream>
#include<string>
#include<fstream>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include "Data.h"
#include "file.h"
#include "global.h"
#include <time.h>
#include <tchar.h>


#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"./ICTCLAS/ICTCLAS50")

using std::string;
using std::vector;
using std::cout;
using std::endl;

//#if defined(_UNICODE)
//#define _T(x) L ##x
//#else
//#define _T(x) x
//#endif

static std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


//
//std::wstring stemp = s2ws(myString);
//LPCWSTR result = stemp.c_str();