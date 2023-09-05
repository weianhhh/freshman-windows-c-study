#include <windows.h>
#include <stdio.h>
#pragma warning(disable:4996)

DWORD WINAPI PrintProc(LPVOID lpParam) {
    CHAR* szText = (CHAR*)lpParam;
    printf("%s\n", szText);
    return 0;
}

void CReateThread(LPVOID Proc, int i) {
    CHAR szText[100];
    sprintf(szText, "thread %d...........", i);

    DWORD dwThreadID = 0;
    HANDLE hThread1 = CreateThread(NULL, 0, PrintProc, szText, 0, &dwThreadID);

    WaitForSingleObject(hThread1, INFINITE); //等待线程结束
    CloseHandle(hThread1);
}

int main() {
    for (int i = 1; i <= 100; i++) {
        CReateThread(PrintProc, i);
    }

    return 0;
}
