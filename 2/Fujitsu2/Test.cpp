#include <iostream>
using namespace std;
class Test
{
private://
	char* p;
public://
	void AllocateAndCopy(char* destination, const char* source);
	Test(const char* source)
	{
		AllocateAndCopy(p,source);
	}
	~Test()
	{
	//	delete p; can't delete it!
	}
	void Print()
	{
		cout << p<<endl;
	}
};
void Test::AllocateAndCopy ( char* destination, const char* source)
{

	char c=' ';
	int i =0;

	destination = new char[strlen(source)];
	while(i<strlen(source))
	{
		c=source[i];
		destination[i] = c;
		i++;
	}
	destination[i]='\0';
	p=destination;
	//strcpy(destination, source); shouldn't be there, cant use strings
}
void TestFunction()
{
	Test c("Testing");
	Test d = c;
	d.Print();
	system("pause");
}

void main()
{
	TestFunction();

}