#include <windows.h>
#include <stdio.h>


//int main()
//{
//	
//	int k;
//	for (k =0; k < 4; k++)
//	{
//		printf("%d\n",k);
//		wchar_t title[20];
//		swprintf(title, 20, L"%d", k);
//		MessageBox(0, L"hello world!", title, MB_OK);
//
//	}
//	return 0;
//}
int main(HINSTANCE hinstance,//��ǰʵ�����
	HINSTANCE hPrevInstance, //֮ǰ�ľ��
	LPSTR lpCmdline,//�������
	int nCmdShow)//��ʾ״̬
{
	MessageBox(0, L"hello world!", L"title", MB_OK);
	return 0;
}