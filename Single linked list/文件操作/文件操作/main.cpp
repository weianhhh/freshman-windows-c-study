#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1

struct Student_type {
    int id;
    int age;
    char name[10];
    char addr[15];
};

void Save(const char* filename, const char* mode, struct Student_type stu[], int size) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("�޷��򿪴��ļ�: %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        if (fwrite(&stu[i], sizeof(struct Student_type), 1, fp) != 1) {
            printf("�ļ�д�����\n");
        }
    }
    fclose(fp);
}

int main() {
    char filename[10], mode[2];
    struct Student_type stu[SIZE];

    printf("�������ļ���: ");
    scanf("%s", filename);
    printf("������ģʽ: ");
    scanf("%1s", mode);

    printf("������ѧ������:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("�������%d��ѧ����id, ����, ����, ��ַ: ", i + 1);
        scanf("%d %s %d %s", &stu[i].id, stu[i].name, &stu[i].age, stu[i].addr);
    }

    Save(filename, mode, stu, SIZE);
    return 0;
}
