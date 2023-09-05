#include <iostream>
#include <string>
#include <regex>
using namespace std;
//regex_match(输入字符串,要求);
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
		cout << "请输入邮箱:";
		cin >> Email;
		if (CheckEmail(Email))
		{
			cout << Email << "是邮箱" << endl;
		}
		else
		{
			cout << Email << "不是邮箱" << endl;
		}
	}
	
	system("pause");
	return 0;
}