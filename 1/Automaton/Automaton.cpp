//-----------------------------------------------------------------------------
// (c) 2012 MyCompany Inc.
//
// Author: John
// Module: main.cpp
// Description: This is the main module.
// Notes: None
//-----------------------------------------------------------------------------
#include <string>
#include <iostream>
using namespace std;
// This constant comes from the hardware specification. It will never change.
#define LENGTH_XS 15
class Automaton
{
private:
	int value;
	const int maxValue;
	int mode;
public:
	// Constructor
	Automaton(int value) : maxValue(12), value(value) {}
	bool HasValue() { return 0 != value; }
	// Returns true when exits with a special requestor.

	bool ExitProtectedMode(int requestor, int screenId)
	{
		cout << "---exit---" << endl;
		if (requestor != 0)
		{
			cout << "---special exit---" << endl;

			if (screenId == 7) // instead of calling 2 functions
			{
				this->mode = 9;
				ExitProtectedMode(0, 0);
			}
			return true;
		}
		else // got rid of a useless "if" statement
		{
			value = 0;
		}

		cout << "---exit was not very successful---" << endl;

		return false;
	}


	bool EnterProtectedMode(int mode)
	{
		cout << "---enter---" << endl;
		this->mode = mode;
		return true;
	}
};
// Hardware will never report data of length higher then this.
const int maxSupportedLength = 17;

bool trimString(string & s)
{
	bool retValue = false;
	if (!s.empty() && s.length() > 2)
	{
		retValue = true;
		s = s.substr(2);
	}
	return retValue;
}
int FixLength(int barcodeLength)
{
	// retValue was not needed
	if (barcodeLength >= LENGTH_XS)
	{
		// got rid of a useless "if" statement that would never be hit

		if ((barcodeLength > LENGTH_XS) && (barcodeLength < maxSupportedLength)) // compressed 2 if statements	
			barcodeLength = LENGTH_XS + 1;
		else
			barcodeLength = LENGTH_XS;
	}
	return barcodeLength;
}
int main()
{
	string s("123");
	if (trimString(s))
		cout << "The string has been trimmed to \"" << s << "\".\n";
	Automaton au(1);
	cout << "au has value? " << au.HasValue() << endl; // 1 unless its 0
	int length = 16;
	int fixedLength = FixLength(length);
	cout << "The original length, " << length << ", is corrected to the new value, " <<
		fixedLength << '.' << endl;
	au.EnterProtectedMode(9);
	au.ExitProtectedMode(12, 7);
	au.EnterProtectedMode(8);
	au.ExitProtectedMode(13, 5);
	au.EnterProtectedMode(8);
	au.ExitProtectedMode(11, 0);

	system("pause");
}
// End of module main.cpp.