#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    HANDLE hDisk = INVALID_HANDLE_VALUE;
    DWORD dwRead;
    char sector[512];

    // �򿪴����豸����Ҫ����ԱȨ��
    hDisk = CreateFile(TEXT("\\\\.\\PhysicalDrive0"), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (hDisk == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open disk device, error code = %d", GetLastError());
            return 1;
    }

    // ��ȡ��һ������
    if (!ReadFile(hDisk, sector, sizeof(sector), &dwRead, NULL))
    {
        printf("Failed to read sector, error code = %d", GetLastError());
            CloseHandle(hDisk);
        return 2;
    }

    // �ر��豸����ӡ��������
    CloseHandle(hDisk);
    for (int i = 0; i < sizeof(sector); i++)
    {
        printf("%02X ", (unsigned char)sector[i]);
        if ((i + 1) % 16 == 0)
            printf("");
    }

    return 0;
}
