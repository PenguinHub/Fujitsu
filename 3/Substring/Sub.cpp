#include "Sub.h"


Sub::Sub(void)
{
}


Sub::~Sub(void)
{
}

bool checkSS(string s, string s2)// quick and dirty, wanted to do a hashmap with booleans, however I did  not have enough time to implement it
{
	unsigned match = s.find(s2);
	unsigned size = s2.size();
	for(int i=0; i<size; i++)
	{
		if(match+i >s.size())
		{
			return false;
		}
		else  if(s[match+i] == s2[i])
			 {}
		
		else
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{

	string s,s2;
	getline(cin, s);
	cout<<"this is your first string: "<<s<<endl;
	getline(cin,s2);
	cout<<"this is your second string: "<<s2<<endl;

	if(checkSS(s,s2))
		cout<<"It's there"<<endl;
	else
		cout<<"It's not there"<<endl;

	system("pause");
	return 0;
}