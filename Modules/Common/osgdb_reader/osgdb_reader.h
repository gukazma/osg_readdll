#pragma once
#ifdef DLL_EXPORTS
#    define API_CLASSEXT extern "C" _declspec(dllexport)
#    define API_STDEXT extern "C" _declspec(dllexport)
#else
#    define API_CLASSEXT extern "C" _declspec(dllimport)
#    define API_STDEXT extern "C" _declspec(dllimport)
#endif

#include <string>
API_STDEXT int* OpenOsgbFile(const char* file);
API_STDEXT void CloseOsgbFile(int* ptr);
API_STDEXT int  GetChildCount(int* ptr);