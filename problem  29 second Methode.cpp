#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>



using namespace std;

enum enWhatToCount{CapittalLetter=0 , SmallLetter=1};

short CountLetters(string S1 , enWhatToCount WhatToCount)
{
	short counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{

		if (WhatToCount == enWhatToCount::CapittalLetter && isupper(S1[i]))
		  {
		 	counter++;
 
		  }

		else if
			 (WhatToCount == enWhatToCount::SmallLetter  &&  islower(S1[i]))
			{
				counter++;

			}

	}


	return counter;
}


string ReadString()
{
	string S1;
	cout << "Enter your Character pls,\n " << endl;
	getline(cin, S1);
	return S1;
}



int main()

{
	string S1 = ReadString();

	cout << "String Length = " << S1.length() << endl;

	cout << " Capital Letter Count = " << CountLetters(S1,enWhatToCount::CapittalLetter)
		<< endl;

	cout << " Small Letter Count = " << CountLetters(S1,enWhatToCount::SmallLetter) 
		<< endl;


	system("pause");
	return 0;

}