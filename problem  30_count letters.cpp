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


string ReadString()
{
	string S1;
	cout << "Enter your string pls,\n " << endl;
	getline(cin, S1);
	return S1;
}



int main()

{
	string S1 = ReadString();
	char chracter = ' ';
	

	cout << " please Enter A chracter " << endl;
	
	cin >> chracter;

	cout << " Letter '" << chracter << "' count = " << CountTheCharacter(S1, chracter) << "\n\n";
	


	system("pause");
	return 0;

}