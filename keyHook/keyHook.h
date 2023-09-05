#pragma once
#include <windows.h>
HHOOK hHOok;
LRESULT CALLBACK hookproc(int code, WPARAM wParam, LPARAM lParam);
extern "C" _declspec(dllexport) bool installHook();

extern "C" _declspec(dllexport) bool uninstallHook();

