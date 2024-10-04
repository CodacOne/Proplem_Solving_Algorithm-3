#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
	getline(cin>>ws, Clientdata.AccountNumber);

	cout << "Enter Pin code ?" << endl;
	getline(cin, Clientdata.PinCode);

	cout << "Enter Name ?" << endl;
	getline(cin, Clientdata.Name);

	cout << "Enter Phone ?" << endl;
	getline(cin, Clientdata.Phone);

	cout << "Enter Acoount Balance ?" << endl;
	cin >> Clientdata.AcoountBalance;

	return Clientdata;

}

string ConvertRecordToLine(stClientdata Client, string Delim)
{
	string S2 = "";

	S2 = S2 + Client.AccountNumber + Delim;
	S2 = S2 + Client.Name + Delim;
	S2 = S2 + Client.Phone + Delim;
	S2 = S2 + Client.PinCode + Delim;
	S2 = S2 + to_string(Client.AcoountBalance) + Delim;


	return  S2;

}


void AddDataLineToFile(stClientdata Client)
{
	fstream MyData;
	string Sdata = "";
	MyData.open("Clientdata.txt", ios::out | ios::app );

	if (MyData.is_open())
	{

		Sdata=ConvertRecordToLine(Client, "#//#");
		MyData << Sdata << endl;
		MyData.close();
	}
}

void AddNewClient()
{
	stClientdata Client;

	Client = ReadClientData();

	
	AddDataLineToFile(Client);


}

void AddClient() 
{
	char AddMore= 'y';
	do {

		system("cls");
		cout << "\n Adding new Client \n\n";

		AddNewClient();

		cout << "\n  Client Added Successfully, Do you want to add more Clients Y/N ? \n";
		cin >> AddMore;
	   } while (toupper(AddMore)=='Y');
	
}


int main() {



	AddClient();
	

	
	

	
	return 0;
}