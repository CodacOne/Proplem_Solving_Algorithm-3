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
	getline(cin,S1);
	return S1;
}



char ConversionCharacterToupper(char S1)
{

	return isupper(S1) ? tolower(S1) : toupper(S1);

}



void StringConversion(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{

		cout << ConversionCharacterToupper(S1[i]);

	}


}




int main()

{
	string S1 = ReadString();
	StringConversion(S1);
	//cout << " \nAfter inverting Case : " << ConversionCharacterToupper(S1) << "\n\n";


	system("pause");
	return 0;

}