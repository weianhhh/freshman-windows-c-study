#pragma once
#include <windows.h>
namespace Registry
{
	void Write(const wchar_t* Path,
		const wchar_t* Name,
		DWORD Type,
		const wchar_t* Data)
	{
		HKEY hKey;
		REGSAM flag = KEY_WOW64_64KEY;
		DWORD dwDisposition = REG_OPENED_EXISTING_KEY;
		LONG lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,Path,0,KEY_ALL_ACCESS | flag,&hKey);
		if (ERROR_SUCCESS != lRet)
		{
			return;
		}
		RegCloseKey(hKey);
	}
}