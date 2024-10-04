#include<iostream>
#include<string>


using namespace std;

string ReadString()
{
	 string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}


void PrintEachWordInString(string S1) 
{
	string Delim = " ";  // delemiter
	string Word ;
	short Pos = 0;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, Pos);

		
			cout << Word << endl;
		
		S1.erase(0, Pos+Delim.length());
	}

	cout << S1 << endl;

}


int main()
{

   string S1 = ReadString();
	cout << S1 << endl;

	PrintEachWordInString(S1);
		
		
		


}