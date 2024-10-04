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


void PrintFirstLetterOfEachWord(string S1)
{
	bool iSFirstLetter = true;
	cout << "\n String After Conversion :\n" << endl;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' '  && iSFirstLetter)
		{
			S1[i] = tolower(S1[i]);

		}
		iSFirstLetter = (S1[i] == ' ' ? true : false);

		cout << S1[i];
	}
	cout << "\n\n";

}



int main()

{
	string S2;
	PrintFirstLetterOfEachWord(ReadString());

	system("pause");
	return 0;

}