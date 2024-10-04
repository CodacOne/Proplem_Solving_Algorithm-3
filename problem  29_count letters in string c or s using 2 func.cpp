#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>



using namespace std;

string ReadString()
{
	string S1;
	cout << "Enter your Character pls,\n " << endl;
	getline(cin, S1);
	return S1;
}



int  CapitalCounter(string S1)
{  
	int CapitalCounter = 0;
	

	for (int i = 0; i < S1.length(); i++)
	{
		if
			(isupper(S1[i]))
		{
			CapitalCounter++;
		}

    }

	return CapitalCounter;

}


int  SmallCounter(string S1)
{

	int SmallCounter = 0;


	for (int i = 0; i < S1.length(); i++)
	{
		if
			(islower(S1[i]))
		{
			SmallCounter++;
		}

	}

	return SmallCounter;

}

int main()

{
	string S1 = ReadString();
	
	cout << "String Length = " << S1.length() << endl;

	cout << " Capital Letter Count = " << CapitalCounter(S1) << endl;

	cout << " Small Letter Count = " << SmallCounter (S1)<< endl;


	system("pause");
	return 0;

}