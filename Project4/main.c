#include <stdio.h>

int main() {
    int num;
    __asm {
        mov dword ptr[num], 20
    };
    printf("num=%d", num);
    return 0;
}
