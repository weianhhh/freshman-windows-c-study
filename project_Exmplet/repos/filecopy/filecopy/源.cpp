#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void encrypt_decrypt(FILE* srcFile, FILE* dstFile, int option) {
    int r;
    char c;
    while (1) {
        r = fread(&c, 1, 1, srcFile);
        if (r < 1) {
            break;
        }

        switch (option) {
        case 1:  // 加密
            c ^= 0x66;
            break;
        case 2:  // 解密
            c ^= 0x66;
            break;
        default:
            break;
        }

        fwrite(&c, 1, 1, dstFile);
    }
}

int main() {
    char srcFileName[260] = { 0 };
    char dstFileName[260] = { 0 };
    char input[10];

    while (1) {
        printf("请输入要加密的FileName（输入 'quit' 或 'q' 以退出）:");
        scanf("%s", srcFileName);

        if (strcmp(srcFileName, "quit") == 0 || strcmp(srcFileName, "q") == 0) {
            break;
        }

        printf("请输入要保存的加密文件名:");
        scanf("%s", dstFileName);

        FILE* fpSrc = fopen(srcFileName, "rb");
        FILE* fpDst = fopen(dstFileName, "wb");

        if (NULL == fpSrc || NULL == fpDst) {
            printf("无法打开文件\n");
            continue;
        }
        else {
            printf("成功写入文件\n");
        }

        int option;
        printf("请输入选项（1: 加密, 2: 解密）：");
        scanf("%d", &option);

        encrypt_decrypt(fpSrc, fpDst, option);

        fclose(fpSrc);
        fclose(fpDst);
    }

    return 0;
}
