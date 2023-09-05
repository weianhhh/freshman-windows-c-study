#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    HANDLE hDisk = INVALID_HANDLE_VALUE;
    DWORD dwRead;
    char sector[512];

    // 打开磁盘设备，需要管理员权限
    hDisk = CreateFile(TEXT("\\\\.\\PhysicalDrive0"), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (hDisk == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open disk device, error code = %d", GetLastError());
            return 1;
    }

    // 读取第一个扇区
    if (!ReadFile(hDisk, sector, sizeof(sector), &dwRead, NULL))
    {
        printf("Failed to read sector, error code = %d", GetLastError());
            CloseHandle(hDisk);
        return 2;
    }

    // 关闭设备并打印扇区数据
    CloseHandle(hDisk);
    for (int i = 0; i < sizeof(sector); i++)
    {
        printf("%02X ", (unsigned char)sector[i]);
        if ((i + 1) % 16 == 0)
            printf("");
    }

    return 0;
}
