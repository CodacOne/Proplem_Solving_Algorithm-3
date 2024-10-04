#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Convert Record line to Data  

struct stClientdata
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
 double AcoountBalance;


};

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	string sWord = " ";
	short pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{

		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0,pos+ Delim.length());
	}
	if (S1 != "")

	{
		vString.push_back(S1);
	}

	return vString;

}

stClientdata ConvertLineToRecord(string S1)

{
	stClientdata Clientdata;
	vector <string> vClientdata;
	vClientdata = SplitString(S1,"#//#");

	
	    Clientdata.AccountNumber= vClientdata[0];
		Clientdata.Name = vClientdata[1];
		Clientdata.Phone = vClientdata[2];
		Clientdata.PinCode = vClientdata[3];
		Clientdata.AcoountBalance = stod(vClientdata[4]);    //Casting string for Double 


		return Clientdata;

}

void PrintData(stClientdata Client)
{

	cout << "Enter Account number : " << Client.AccountNumber<< endl;
	cout << "Enter Pin code : " << Client.PinCode<< endl;
	cout << "Enter Name : " << Client.Name<<endl;
	cout << "Enter Phone : " << Client.Phone<< endl;
    cout << "Enter Acoount Balance : " << Client.AcoountBalance<< endl;

}

int main() {

	stClientdata Client;
	string S1 = "A150#//#1234#//#Abulfattah kashkash#//#094578541147#//#5270.0000";
	

	cout << "\n  Line Record is : \n";
	Client=ConvertLineToRecord(S1);

	PrintData(Client);

	return 0;
}