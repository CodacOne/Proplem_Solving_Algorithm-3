#include<iostream>
#include<string>
#include<vector>

using namespace std;


// join string by one function


/*  string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}  */




string  JoinString(vector <string>& vString, string Delim)
{
	string S1 = "";

	for (string S : vString)
	{

		S1 = S1 + S + Delim;

	}
	return S1.substr(0, S1.length() - Delim.length());

}



string  JoinString(string arrString[],short stringLength, string Delim)
{
	string S1 = "";

	for (int i=0;i< stringLength;i++)
	{
		S1 = S1 + arrString[i] + Delim;
		

	}
	return S1.substr(0, S1.length() - Delim.length());

}


int main()
{

	vector <string> vString = { "Abdulafattah","Mohammed","fatima","batoul" };
	string arrString[]=  { "Abdulafattah","Ali","fatima","Albatoul" };


	cout << " Vector After Join  =" << endl;
	cout << " Join String  =" << JoinString(vString, " , ") << endl;


	cout << " Array After Join =" << endl;
	cout << " Join String  =" << JoinString(arrString, 4," , ") << endl;





}