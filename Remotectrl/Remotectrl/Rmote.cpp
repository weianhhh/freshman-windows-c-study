//#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
struct Book {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
int main(int argc, char* argv[])
{
    char bookname;
    char bookauthor;
    char booksubject;
    int bookbook_id;
    scanf_s("����������:%s\n", &bookname);
    scanf_s("�������������:%s\n", &bookauthor);
    scanf_s("��������Ŀ�Ŀ:%s\n", &booksubject);
    scanf_s("���������id:%d\n", &bookbook_id);
    struct Book Book1;
    struct Book Book2;
    strcpy_s(Book1.title, &bookname);
    strcpy_s(Book1.author, &bookauthor);
    strcpy_s(Book1.subject, &booksubject);
    Book2.book_id = bookbook_id;
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);
}