#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// ����� Windows ��θ� �������� ���� �������
#include <shlobj_core.h >
#include <wchar.h>

// ��ΰ� �̹� �����ϴ��� Ȯ���ϱ� ���� �������
#include <io.h>

// CreateDirectory �Լ��� ����ϱ� ���� �������
#include <Windows.h>

using namespace std;

wchar_t* makeFolder();