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

char ReadCharacter()
{
	char Character;
	cout << "Enter your Character pls,\n " << endl;
	cin>> Character;
	return Character;
}


char ConversionCharacterToupper(char S1)
{

	return isupper(S1) ? tolower(S1) : toupper(S1);


// My solousion
	/* char S2;
	cout << "\n Character After inverting case :\n" << endl;

	int a = int(S1);
	if (a >= 65 && a <= 90)
	{
		S2 = tolower(S1);
		cout << S2 << "\n";

	}
	
	else if (a >= 97 && a <= 122)
	{

		S2 = toupper(S1);
		cout << S2 << "\n";
	}*/
}


int main()

{
	char S1 = ReadCharacter();

	cout<<" \nAfter inverting Case : "<<ConversionCharacterToupper(S1)<<"\n\n";
	

	system("pause");
	return 0;

}