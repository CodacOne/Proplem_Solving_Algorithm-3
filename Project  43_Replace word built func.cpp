#include <iostream>

#include <vector>
#include <string>

using namespace std;


// Replace Word In Funcion Using custom Function

string AllStringLower(string S1)
{
	for (int i = 0; i< S1.length(); i++)
	{
		S1 = tolower(S1[i]);

	}

	return S1;
}

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

string JoinString(vector <string>& vString, string Delim)
{
	string S2 = "";
	for (string Snew : vString)
	{

		S2 = S2 + Snew + Delim;

	}
	return S2;

}

string ReplaceWordInFuncionUsingcustomFunction(string S1, string StringToReplace,
	   string ReplaceTo,bool MatchCase=1)

{
	vector <string> vString;
	
	

	vString=SplitString(S1, " ");

	for (string& Snew : vString)
	{
		if(MatchCase)
		    { 
		if (Snew == StringToReplace)
		{

			Snew = ReplaceTo;
		}
		    }
		else
		{ 
			if (AllStringLower(Snew) == AllStringLower(StringToReplace))
			{
				Snew= ReplaceTo;

			}
			
		}
   
	}

	return (JoinString(vString, " "));
}

int main() {

	string S1 = "I'm Abdalfattah from SyriA ,Welcome to syria";
	string StringToReplace = "syria";
	string ReplaceTo = "Gaza";
	cout << "\n" << S1 << "\n\n";

	cout << "\nString After Replace :\n";

	cout << ReplaceWordInFuncionUsingcustomFunction(S1, StringToReplace, ReplaceTo) ;
	 cout << "\n\n";


	 cout << ReplaceWordInFuncionUsingcustomFunction(S1, StringToReplace, ReplaceTo,0);
	 cout << "\n\n";
	return 0;
}