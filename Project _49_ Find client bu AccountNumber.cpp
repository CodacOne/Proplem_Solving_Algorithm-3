#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

// find  Clients file and Show them on the screen 

const string ClientdataFileName = "Clientdata.txt";

struct stClientdata
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	int AcoountBalance;


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

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")

	{
		vString.push_back(S1);
	}

	return vString;

}




stClientdata ConvertLinetoRecord(string line, string Delim = "#//#")
{
	vector<string> vClinteData;
	stClientdata sClientdata;

	vClinteData = SplitString(line, Delim);

	sClientdata.AccountNumber = vClinteData[0];
	sClientdata.Name = vClinteData[1];
	sClientdata.PinCode = vClinteData[2];
	sClientdata.Phone = vClinteData[3];
	sClientdata.AcoountBalance = stod(vClinteData[4]); // casting string to double

	return sClientdata;
}



vector <stClientdata> LoadClientDataFromFile(string FileNam)
{

	fstream MyData;
	stClientdata Client;
	vector <stClientdata> Clientdata;

	string line = "";

	MyData.open("Clientdata.txt", ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{

			Client = ConvertLinetoRecord(line);
				Clientdata.push_back(Client);

		}

		return Clientdata;
	}

}

void PrintRecord(stClientdata Client)
{
	
	cout << " " << setw(5) << left <<"AccountNumber : "<< Client.AccountNumber << endl;
	cout << " " << setw(5) << left << "Name : " << Client.Name << endl;
	cout << " " << setw(5) << left << "PinCode : " << Client.PinCode << endl;
	cout << " " << setw(5) << left << "Phone : " << Client.Phone << endl;
	cout << " " << setw(5) << left << "AcoountBalance : " << Client.AcoountBalance << endl;
	
}

bool FindClientByAccountNumber(string AccountNumber, stClientdata & ResultClient)
{
	vector <stClientdata> Client;
	stClientdata stClient;
	Client=LoadClientDataFromFile(ClientdataFileName);

	for(stClientdata MyClient: Client)
	{
		if (MyClient.AccountNumber == AccountNumber)
		{


			ResultClient = MyClient;
			return true;
		}
	
	
	}
	
	return false;

}




int main() {
	string AccountNumber = "";
	stClientdata Client;
	vector <stClientdata> vClientdata;
	cout << " Plc,Enter Account Number ?\n\n";
	cin >> AccountNumber;
	
	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		cout << "The Following are the client details :\n\n";
		PrintRecord(Client);

	}

	else 
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}
		
	
	




	return 0;
}