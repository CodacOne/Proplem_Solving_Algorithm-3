#include<iostream>
#include<string>
#include<vector>

using namespace std;


// how count word in string using Vector


string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}


vector <string> SpiltString(string S1, string Delim)
{  
	vector <string> vString; 


	short counter = 1;
//	string Delim = " ";  // delemiter
	string Word;
	short Pos = 0;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{

		Word = S1.substr(0, Pos);
		if (Word != "")

		{
			vString.push_back(Word);

		}
		S1.erase(0, Pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);   // it adds last word of the string.

	}
	return vString;

}


int main()
{
	vector <string> vString;
	string S1 = ReadString();
	cout << S1 << endl;

	// cout << "The number of words in your string is : " << endl;

	vString	=SpiltString(S1," ");

	cout << "Token : " << vString.size() << "\n\n";

	for (string & MyWord : vString)
	{
		cout << MyWord << endl;


	}



}