#pragma once

#ifdef TEXTDLL_EXPORTS
#define TEXTDLL_API __declspec(dllexport)
#else
#define TEXTDLL_API __declspec(dllimport)
#endif

extern "C" TEXTDLL_API LPCWSTR GetText();
