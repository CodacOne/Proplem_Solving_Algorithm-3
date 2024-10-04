#include<iostream>
#include<string>


using namespace std;


// how count word in string


string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}


int PrintEachWordInString(string S1)
{
	short counter = 1;
	string Delim = " ";  // delemiter
	string Word;
	short Pos = 0;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, Pos);
		counter++;

		

		S1.erase(0, Pos + Delim.length());
	}

	return counter;

}


int main()
{

	string S1 = ReadString();
	cout << S1 << endl;

	cout <<"The number of words in your string is : "<< PrintEachWordInString(S1);





}