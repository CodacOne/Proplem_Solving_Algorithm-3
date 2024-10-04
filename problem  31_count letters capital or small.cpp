#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>



using namespace std;

enum enWhatToCount { CapittalLetter = 0, SmallLetter = 1 };

short CountTheCharacter(string S1, char Letter)
{
	short counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{

		if (S1[i] == Letter)
		{
			counter++;

		}

	}


	return counter;
}




short CountTheCharacterCapitalOrSmall(string S1, char capital , char Small)
{
	short counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{

		if (S1[i] == capital || S1[i] == Small)
		{
			counter++;

		}

	}


	return counter;
}


string ReadString()

{
	string S1;
	cout << "Enter your string pls,\n " << endl;
	getline(cin, S1);
	return S1;
}




// Function to  Methode 2

short CountLetters(string S1, char Letter,bool MatchCase=true)
{  
	short Counter = 0;
	for (int i = 0; i < S1.length(); i++)

	{
		if (MatchCase)
		{  
			if(S1[i] == Letter)
			{
				Counter++;
			}
			

		}


		else 
		{
			if (tolower(S1[i]) == tolower(Letter))
		
				Counter++;
			}
	}
	return Counter;
}



int main()

{
	string S1 = ReadString();
	char chracter = ' ';


	cout << " please Enter A chracter " << endl;

	cin >> chracter;

 char	CapitalCharacter = toupper(chracter);
 char  SmallCharacter = tolower(chracter);


	cout << " Letter '" << chracter << "' count = " <<
		CountTheCharacter(S1, chracter) << "\n\n";


	cout << " Letter  '" << SmallCharacter <<"' Or '"<< CapitalCharacter <<"' count = "
		<<CountTheCharacterCapitalOrSmall(S1, CapitalCharacter, SmallCharacter) << "\n\n";


	cout << " Methode  2 \n\n";

	cout << " Letter '" << chracter << "' count = " << CountLetters(S1, chracter) << endl;


	cout << " Letter  '" << SmallCharacter << "' Or '" << CapitalCharacter << "' count = "
		<<CountLetters(S1, chracter, false) << "\n\n";

	system("pause");
	return 0;

}