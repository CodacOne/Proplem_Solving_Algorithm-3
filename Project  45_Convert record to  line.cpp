#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Convert Data Record to line 

struct stClientdata
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	int AcoountBalance;


};

stClientdata ReadClientData()
{
	stClientdata Clientdata;

	cout << "Enter Account number ?" << endl;
	getline(cin, Clientdata.AccountNumber);

	cout << "Enter Pin code ?" << endl;
	getline(cin, Clientdata.PinCode);

	cout << "Enter Name ?" << endl;
	getline(cin, Clientdata.Name);

	cout << "Enter Phone ?" << endl;
	getline(cin, Clientdata.Phone);

	cout << "Enter Acoount Balance ?" << endl;
	cin>> Clientdata.AcoountBalance;

	return Clientdata;

}

void ConvertRecordToLine(stClientdata Client,string Delim)
{
	string S2 = "";

	S2 = S2 + Client.AccountNumber + Delim;
	S2 = S2 + Client.Name + Delim;
	S2 = S2 + Client.Phone + Delim;
	S2 = S2 + Client.PinCode + Delim;
	S2 = S2 + to_string(Client.AcoountBalance) + Delim;
		

	cout << S2;

}



int main() {

	stClientdata Client;
	cout << "\n pls, Enter Client data \n";
	Client=ReadClientData();

	cout << "\n  Client Record for saving is : \n";
	ConvertRecordToLine(Client,"//");

	return 0;
}