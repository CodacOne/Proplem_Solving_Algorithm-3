#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

// Delete Clients file 

const string ClientdataFileName = "Clientdata.txt";

struct stClientdata
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AcoountBalance;
	bool DeleteMark = false;

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

void PrintClientRecord(stClientdata Client)
{

	cout << " " << setw(5) << left << "AccountNumber : " << Client.AccountNumber << endl;
	cout << " " << setw(5) << left << "Name : " << Client.Name << endl;
	cout << " " << setw(5) << left << "PinCode : " << Client.PinCode << endl;
	cout << " " << setw(5) << left << "Phone : " << Client.Phone << endl;
	cout << " " << setw(5) << left << "AcoountBalance : " << Client.AcoountBalance << endl;

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClientdata> vClientdata, stClientdata &ClientOrder)
{
	vector <stClientdata> Client;
	stClientdata stClient;
	

	for (stClientdata MyClient : vClientdata)
	{
		if (MyClient.AccountNumber == AccountNumber)
		{

			
		
			ClientOrder = MyClient;
			return true;
		}


	}

	return false;

}

string ConvertRecordToLine(stClientdata Clientdata)
{
	string Delim = "#//#";
	string line = "";
	line = line + Clientdata.AccountNumber + Delim;
	line = line + Clientdata.Name + Delim;
	line = line + Clientdata.PinCode + Delim;
	line = line + Clientdata.Phone + Delim;
	line = line + to_string(Clientdata.AcoountBalance) + Delim;

	return line;
}

void MarkClientForDeleteByAccoutNumber(string AccountNumber, vector <stClientdata>& vClientdata)
{

	for (stClientdata &c : vClientdata)
	{
		if (c.AccountNumber == AccountNumber)
		{

			c.DeleteMark = true;
		}


	}

}

vector <stClientdata> SaveClientDataToFile(vector <stClientdata> vClientdata)
{
	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(ClientdataFileName, ios::out);
	

	if (MyFile.is_open())
	{

		for (stClientdata Line : vClientdata)
		{
			if (Line.DeleteMark == false)
			{
				DataFileNew = ConvertRecordToLine(Line);
				MyFile << DataFileNew << endl;

			}
			
		}


		MyFile.close();
	}
	

	return vClientdata;
}



void DeleteClientByAccountNumber(string AccountNumber)
{
	stClientdata Client;
	vector <stClientdata> vClientdata;

	char ChoiceDelete = 'n';


	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	if (FindClientByAccountNumber(AccountNumber, vClientdata, Client))
	{
		cout << "The Following are the client details :\n\n";
		PrintClientRecord(Client);

		cout << "Do you sure you want delete this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if(ChoiceDelete=='Y' || ChoiceDelete=='y')
		{


			MarkClientForDeleteByAccoutNumber(AccountNumber, vClientdata);

			SaveClientDataToFile(vClientdata);


			// Refresh data of file
			vClientdata = LoadClientDataFromFile(ClientdataFileName);
		
			cout << "\n\n Cleint Delete Succefuly. \n";
		}
		
	}

	else
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}


	
}



string ReadAccountNumber()
{
	string AccountNumber = "";

	stClientdata Client;
	vector <stClientdata> vClientdata;

	cout << " Plc,Enter Account Number ?\n\n";
	cin >> AccountNumber;

	return AccountNumber;
}

int main() {
	
	string AcoountNumber=ReadAccountNumber();

	DeleteClientByAccountNumber(AcoountNumber);


	return 0;
}