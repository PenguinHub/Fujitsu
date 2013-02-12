#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sub
{
public:
	Sub(void);
	~Sub(void);



};

bool isSubstring(string s, string s2)
{
	int count=0;
	//	for(int i=0;i<s.length;i++)
	//	{

	//}

	for(int i = 0; s[i] != '\0'; i++)
		
	{
			bool foundNonMatch = false;
			for(int j = 0; s2[j] != '\0'; j++)
			{
					if (s[i + j] != s2[j])
						
					{
							foundNonMatch = true;
							break;
					}
			}
				if (!foundNonMatch)
					count++;

			if(count!=0)
			{
				cout<<"YES string 2 is a substring of string 1\n";
				return true;

			}
    
			else
			{
				cout<<"string 2 is NOT a substring of string 1\n";
				return false;

			}

	}

}

