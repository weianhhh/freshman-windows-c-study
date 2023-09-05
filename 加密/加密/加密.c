// 加密.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int result = 1;
    int count;
    char text[128] = {'\0'};
    char passw[128] = {'\0'};
    int i;
    //int j =;
    
    while (1)
    {
        if (result == 1)
        {
            printf("输入加密明文:\n");
            scanf("%s",&text);
            count = strlen(text);
            for (i = 0; i < count; i++)
            {   
                /*printf("输入加密位数:\n");*/
                passw[i] = text[i] + i + 6;
            }
            passw[i] = '\0';
            printf("加密后的内容%s\n",passw);
        }
        else if (result == 2)
        {
            printf("输入解密明文:\n");
            scanf("%s", &text);
            count = strlen(text);
            for (i = 0; i < count; i++)
            {
                /*printf("输入加密位数:\n");*/

                text[i] = passw[i] - i - 6;
            }
            text[i] = '\0';
            printf("解密后的内容:%s\n", passw);
        }
        else
        {
            if (result == 3)
            {
                break;
            }
            /*else if (result == 4)
            {
                scanf("输入加密位数:%d", &j);
                j--;
                break;
            }*/
            else
            {
                printf("输入内容\n");

            }
        }
        printf("输入1加密，输入2解密,输入3中断\n");
        scanf("%d", &result);
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
