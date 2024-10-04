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
	cout << "Enter your string pls,\n " << endl;
	getline(cin, S1);
	return S1;
}


void PrintFirstLetterOfEachWord(string S1)
{
	bool iSFirstLetter = true;
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] !=' '  && iSFirstLetter)
		{
			cout << S1[i] << endl;

		}
		iSFirstLetter = (S1[i] == ' ' ? true : false);


	}


}



int main()

{
	PrintFirstLetterOfEachWord(ReadString());



	cout << "\n First Liters of this String :\n" << endl;
	
/*   string S1 = "Mohammed Saqer Abu_Hadhoud @programming Advices";
 
     cout << S1.at( S1.find("Mohammed")) << endl;
 	cout << S1.at(S1.find("Saqer"))<< endl;
	cout << S1.at(S1.find("Abu_Hadhoud")) << endl;
	cout << S1.at(S1.find("@programming")) << endl;
	cout << S1.at(S1.find("Advices")) << endl;

	*/
	system("pause");
	return 0;

}