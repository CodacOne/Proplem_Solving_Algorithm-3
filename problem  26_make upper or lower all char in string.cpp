#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>


// write a program to read a string then uppercase the first letter 
//  of each word in that string
using namespace std;

string ReadString()
{
	string S1;
	cout << "Enter your string pls,\n " << endl;
	getline(cin, S1);
	return S1;
}


void ConversionStringWordToupper(string S1)
{
	
	cout << "\n String After Upper :\n" << endl;

	for (int i = 0; i < S1.length(); i++)
	{
		
			S1[i] = toupper(S1[i]);


		cout << S1[i];
	}
	cout << "\n\n";

}




void ConversionStringWordTolower(string S1)
{

	cout << "\n String After lower :\n" << endl;

	for (int i = 0; i < S1.length(); i++)
	{

		S1[i] = tolower(S1[i]);


		cout << S1[i];
	}
	cout << "\n\n";

}

int main()

{
	string S1 = ReadString();
	
	ConversionStringWordToupper(S1);
	ConversionStringWordTolower(S1);

	system("pause");
	return 0;

}