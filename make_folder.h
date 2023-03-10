#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 사용자 Windows 경로를 가져오기 위한 헤더파일
#include <shlobj_core.h >
#include <wchar.h>

// 경로가 이미 존재하는지 확인하기 위한 헤더파일
#include <io.h>

// CreateDirectory 함수를 사용하기 위한 헤더파일
#include <Windows.h>

using namespace std;

wchar_t* makeFolder();