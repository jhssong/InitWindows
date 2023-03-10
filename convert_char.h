#pragma once
#include <iostream>
#include <wchar.h>
#include <mbstring.h>

char* ConvertWCtoC(const wchar_t*);  // wchar_t* -> char*
wchar_t* ConvertCtoWC(const char*);  // char* -> wchar_t*