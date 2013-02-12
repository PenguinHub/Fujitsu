#include <iostream>
void AllocateAndCopy (char *destination, const char* source)
{
	destination = new char[strlen(source)];
	strcpy(destination, source);
}
class Test
{
private:
	char* p;

public:
	Test(const char* source)
	{
		AllocateAndCopy(p, source);
	}
	~Test()
	{
		delete p;
	}
	void Print()
	{
		std::cout << p;
	}
};
void TestFunction()
{
	Test c("Testing");
	Test d = c;
	d.Print();
}
void main()
{
	TestFunction();
}