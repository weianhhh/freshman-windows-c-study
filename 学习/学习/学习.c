#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
//#include <unistd.h>
void strcmp_test()
{
	char str1[20];
	char str2[20];
	int ret;
	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");
	ret = strcmp(str1, str2);
	printf("%d\n",ret);
	if (ret < 0)
	{
		printf("str1 < str2");
	}
	else if (ret > 0)
	{
		printf("str1 > str2");
	}
	else
	{
		printf("str1 = str2");
	}
	return 0;
}
void strchr_test()
{
	const char str[] = "https://www.baidu.com";
	const char ch = '.';
	char* ret;
	ret = strchr(str, ch);
	printf("|%c search is -|%s|\n",ch,ret);
	return 0;
}
void strchar_test2()
{
	char str[] = "https://www.baidu.com\n";
	char* find;
	find = strchr(str,'\n');
	if (find)
		*find = '\0';
	else
		while (getchar() != '\n')
			continue;
	return 0;
}
void strlen_test()
{
	char str[50];
	char len;
	strcpy(str, "http://www.baidu.com");
	len = strlen(str);
	printf("|%s| 的长度是 |%d|\n", str, len);
	return 0;
}
void memcpy_test()
{
	const char src[50];
	strcpy(src,"http://www.baidu.com");
	char dest[50];
	char strlen_test;
 	memcpy(dest,src,strlen(src)+1);
	printf("dest = %s\n",dest);
	return 0;
}
void memcpy2_test()
{
	char* s = "https://www.baidu.com";
	char d[20];
	memcpy(d,s+11,6);
	d[6] = '\0';
	printf("%s",d);
	return 0;
}
void memcpy3_test()
{
	char src[] = "***";
	char dest[] = "abcdefg";
	printf("使用memcpy前:%s\n",dest);
	memcpy(dest, src, strlen(src));
	printf("使用memcpy后:%s\n",dest);
	return 0;
}
void memset_test()
{
	char str[50];
	strcpy(str,"This is string.h library function");
	puts(str);
	memset(str, '$',7);
	puts(str);
	return 0;
}
void fopen_and_fprintf_test1()
{
	FILE* fp;
	fp = fopen("D:\\file.txt","w+");
	fprintf(fp,"%s %s %s %d","we","are","in",2022);
	fclose(fp);
	return 0;
}
void fopen_fgetc_feof_test()
{
	FILE* fp;
	int c;
	fp = fopen("D:\\file.txt", "r");
	if (fp == NULL)
	{
		perror("打开文件发生错误");
		return (-1);
	}
	while (1)
	{
		c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
	}
	printf("%c", c);
	fclose(fp);
	return 0;
}
void setvbuf_test()
{
	char buff[1024];
	memset(buff, '\0', sizeof(buff));
	fprintf(stdout, "启用全缓冲\n");
	setvbuf(stdout,buff,_IOFBF,1024);
	fprintf(stdout, "这里是 runoob.com\n");
	fprintf(stdout, "该输出将保存到 buff\n");
	fflush(stdout);
	fprintf(stdout, "这将在编程时出现\n");
	fprintf(stdout, "最后休眠五秒钟\n");
	Sleep(5);
	return 0;
}
//void sighandler(int signum)
//{
//	printf("捕获信号%d,跳出...\n",signum);
//	exit(1);
//}
//int main()
//{
//	void sighandler(int);
//	signal(SIGINT,sighandler);
//	while (1)
//	{
//		printf("开始休眠一秒钟...\n");
//	}
//	return 0;
//}


/*枚举example
enum DAY
{
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
};

int main()
{
	enum DAY day;
	for (day = MON; day <= SUN; day++)
	{
		printf("枚举元素：%d \n", day);
	}
	return 0;
}
*/

//int main()
//{
//	enum color { red = 1, green, blue };
//	enum  color favorite_color;
//	/* 用户输入数字来选择颜色 */
//	printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
//	scanf("%u", &favorite_color);
//	/* 输出结果 */
//	switch (favorite_color)
//	{
//	case red:
//		printf("你喜欢的颜色是红色");
//		break;
//	case green:
//		printf("你喜欢的颜色是绿色");
//		break;
//	case blue:
//		printf("你喜欢的颜色是蓝色");
//		break;
//	default:
//		printf("你没有选择你喜欢的颜色");
//	}
//	return 0;
//}
//void arry_test()
//{
//	int n[10];
//	int i, j;
//	for (i = 0; i < 10; i++)
//	{
//		n[i] = i + 100;
//		printf("Element[%d] = %d\n", i, n[i]);
//	}
//	for (j = 0; j < 10; j++)
//	{
//		printf("Element[%d] = %d\n", j, n[j]);
//	}
//	return 0;
//}

/*int main(int argc, char* grgv[])
{
	int a[] = { 1,2,3,4,5 };
	int b;
	int d;
	b = sizeof(a);
	d = sizeof(a[0]);
	//b = sizeof(a) / sizeof(a[0]);
	printf("数组元素个数为：%d\n", b);
	printf("数组元素个数为：%d\n", d);
	return 0;
}*/

