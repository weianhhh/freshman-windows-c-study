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
        case 1:  // ����
            c ^= 0x66;
            break;
        case 2:  // ����
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
        printf("������Ҫ���ܵ�FileName������ 'quit' �� 'q' ���˳���:");
        scanf("%s", srcFileName);

        if (strcmp(srcFileName, "quit") == 0 || strcmp(srcFileName, "q") == 0) {
            break;
        }

        printf("������Ҫ����ļ����ļ���:");
        scanf("%s", dstFileName);

        FILE* fpSrc = fopen(srcFileName, "rb");
        FILE* fpDst = fopen(dstFileName, "wb");

        if (NULL == fpSrc || NULL == fpDst) {
            printf("�޷����ļ�\n");
            continue;
        }
        else {
            printf("�ɹ�д���ļ�\n");
        }

        int option;
        printf("������ѡ�1: ����, 2: ���ܣ���");
        scanf("%d", &option);

        encrypt_decrypt(fpSrc, fpDst, option);

        fclose(fpSrc);
        fclose(fpDst);
    }

    return 0;
}
