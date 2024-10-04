#include<iostream>
#include<string>
#include<vector>

using namespace std;


// Reversing string by one function


string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}



// First Methode


vector <string>SplitString(string S1, string Delim)
{
	vector <string> vString;
	short Pos = 0;
	string Sword = "";

	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		Sword = S1.substr(0, Pos);
		if (Sword != " ")
		{
			vString.push_back(Sword);
		}
		S1.erase(0, Pos + Delim.length());
	}
	if (S1 != " ")
	{
		vString.push_back(S1);
	}
	return vString;

}


string ReverseStringByVector(string S1)
{
	string S2 = "";

	vector <string> vString;
	vString = SplitString(S1, " ");

	vector <string>::iterator  iterString = vString.end();

	while (iterString != vString.begin())
	{
		--iterString;
		S2 = S2 + *iterString+" ";
		
	}
	S2 = S2.substr(0, S2.length() - 1);
	return S2;

}



// second Methode

string  ReversingString( string S1)
{
	 short Length =S1.length() ;
	 string S2 = "";
	 short Pos = 0;


	 for (int i = Length; i > 0; i--)
	 {
		 if (S1[i] == ' ')
		 {
			 Pos = i;
			 S2 = S2+S1.substr(Pos, S1.length());
			 S1.erase(Pos, S1.length());
		 }

	 }
	 S2 = S2+" "+S1.substr(0, S1.length());
	 return S2;
}





int main()
{
	string S1 = ReadString();

	cout << "\n\nMethode 1 \n\n";
	cout << " String After Reversing words By vector and iterator = " << endl;
	cout << ReverseStringByVector(S1);

	cout << "\n\nMethode 2 \n\n";
	cout << "String After Reversing words By for loop = " << endl;
	cout << ReversingString(S1) << endl;
	
}