#include <iostream>
#include <string>
#include <regex>
using namespace std;
//regex_match(�����ַ���,Ҫ��);
bool CheckEmail(char* username)
{
	regex object("(\\w+)@(\\w+)(\\.(\\w+))+");
	/*************************************************/
	bool result = regex_match(username, object);
	return result;
}
using namespace std;
int main()
{
	while (1)
	{
		char Email[20] = "";
		cout << "����������:";
		cin >> Email;
		if (CheckEmail(Email))
		{
			cout << Email << "������" << endl;
		}
		else
		{
			cout << Email << "��������" << endl;
		}
	}
	
	system("pause");
	return 0;
}