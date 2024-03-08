#pragma once
#ifdef DLL_EXPORTS
#    define API_CLASSEXT _declspec(dllexport)
#    define API_STDEXT _declspec(dllexport)
#else
#    define API_CLASSEXT _declspec(dllimport)
#    define API_STDEXT _declspec(dllimport)
#endif

#include <string>
API_STDEXT int OpenOsgbFile(std::string);