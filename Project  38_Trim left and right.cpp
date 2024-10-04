#include<iostream>
#include<string>
#include<vector>

using namespace std;


// Trim & Trim lift & Trim Right using three function

/*  string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}  */




string TrimLeft(string S1)
{
	
      for(int i= 0 ; i < S1.length() ;i++)
	  {
		  if (S1[i] !=' ')
		  {
			return   S1.substr(i, S1.length());

		  }
		  
		 
	  }
		
	return "";

}


string TrimRight(string S1)
{
	int Initialvalue = S1.length();
	short Pos = 0;

	for (int i = Initialvalue; i >0; i--)
	{
		if (S1[i] != ' ')
		{
			Pos = i;

		}
		return   S1.substr(0,i);
		
	}

	return "";

}

string Trim(string S1)
{

  return (TrimLeft(TrimRight(S1)));


}

int main()
{
	
	string S1 ="             Abdulafattah     ";
	// cout << S1 << endl;

	
	cout << "  Trim Left  =" << TrimLeft(S1) << endl;
	cout << "  Trim Right =" << TrimRight(S1) << endl;
	cout << "  Trim       =" << Trim(S1) << endl;

	// cout << "Token : " << vString.size() << "\n\n";




}