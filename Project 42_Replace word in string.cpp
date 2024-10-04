#include <iostream>
	
#include <vector>
#include <string>

using namespace std;


// Replace Word In Funcion Using Built Function

string ReplaceWordInFuncionUsingBuiltFunction(string S1, string StringToReplace, string ReplaceTo)

{

	short Pos = 0;
	
	Pos = S1.find(StringToReplace);

	while (Pos  != std::string::npos)
	{
		S1 = S1.replace(Pos, StringToReplace.length(), ReplaceTo);
		Pos = S1.find(StringToReplace);  // find next
	}

	return S1;
}

int main() {
	
	string S1 =  "I'm Abdalfattah from syria ,Welcome to syria";
	string StringToReplace = "syria";
	string ReplaceTo = "Gaza";
	cout << "\n" << S1 << "\n\n";

	cout << "\nString After Replace :\n";
	
	cout<<ReplaceWordInFuncionUsingBuiltFunction(S1, StringToReplace, ReplaceTo)<<"\n\n";
	return 0;
}