#include <iostream>
#include <regex>
using namespace std;
int main()
{
	smatch results;
	string str = "HyperWorks contains HyperMesh and HyperView and HyperStudy.";
	//string pat("Hyper[^ ]+[ |.]");
	string pat(" Hyper.*\.");
	regex r(pat);
	for(sregex_iterator it(str.begin(), str.end(), r),end_it;it != end_it;++it)
	{ 
		cout << it->str() << endl;
	}
	string str2;
	str2 = regex_replace(str,r,"hello ");
	cout << str2 << endl;
	if (regex_match(str,results,r)) 
	{
		cout << results[0] << endl;
	}
	else 
	{
		cout <<"not match" << endl;
	}
	return 0;
}