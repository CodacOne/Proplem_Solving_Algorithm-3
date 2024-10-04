#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

// Project Bank_1_

void ShowMainMenuScreen();

const string ClientdataFileName = "Clientdata.txt";

enum eOptions
{

	eClientList = 1, eAddClient = 2, eDeleteClient = 3
	, eUpdateClient = 4, eFindClient = 5, eExit = 6



};

string ReadAccountNumber()
{
	string AccountNumber = "";

	cout << " Plc,Enter Account Number ?\n\n";
	cin >> AccountNumber;

	return AccountNumber;
}

struct stClientdata
{
	string AccountNumber;
	string Name;
	string PinCode;
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


bool ClientExistsOrNot(string AccountNumber)
{

	fstream MyData;
	stClientdata Client;

	string line = "";

	MyData.open("Clientdata.txt", ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{
			Client =ConvertLinetoRecord(line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyData.close();
			return true;
			}

		}

		MyData.close();
	}
	return false;
}

stClientdata ReadClientData() {
	
	stClientdata ClientData;

	cout << "Enter Account Number :\n";
	getline(cin >> ws, ClientData.AccountNumber);

	while(ClientExistsOrNot(ClientData.AccountNumber))
	{
cout << "\nClient With ( " << ClientData.AccountNumber << " ) already Exists , Enter another Account number ?\n";

	getline(cin >> ws, ClientData.AccountNumber);

	}

	cout << "Enter Name :\n";
	getline(cin , ClientData.Name);

	cout << "Enter PinCode :\n";
	getline(cin , ClientData.PinCode);

	cout << "Enter Phone :\n";
	getline(cin , ClientData.Phone);
		
	cout << "Enter Account Balance :\n";
	cin >> ClientData.AcoountBalance;


	return ClientData;
}


void PrintRecord(stClientdata Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(20) << left << Client.PinCode;
	cout << "| " << setw(20) << left << Client.Phone;
	cout << "| " << setw(15) << left << Client.AcoountBalance;


}

void PrintClientRecord(stClientdata Client)
{
	cout << "THE following are the Client details :\n";
	cout << "------------------------------------------\n";
	cout << " " << setw(20) << left << "AccountNumber : " << Client.AccountNumber << endl;
	cout << " " << setw(20) << left << "Name : " << Client.Name << endl;
	cout << " " << setw(20) << left << "PinCode : " << Client.PinCode << endl;
	cout << " " << setw(20) << left << "Phone : " << Client.Phone << endl;
	cout << " " << setw(20) << left << "AcoountBalance : " << Client.AcoountBalance << endl;
	cout << "------------------------------------------\n";
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

	for (stClientdata& c : vClientdata)
	{
		if (c.AccountNumber == AccountNumber)
		{

			c.DeleteMark = true;
		}


	}

}


vector <stClientdata> SaveClientDataToFileAfterUpdate(vector <stClientdata> vClientdata)
{
	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(ClientdataFileName, ios::out);


	if (MyFile.is_open())
	{


		for (stClientdata Line : vClientdata)
		{

				DataFileNew = ConvertRecordToLine(Line);
				MyFile << DataFileNew << endl;

		}


		MyFile.close();
	}


	return vClientdata;
}


vector <stClientdata> SaveClientDataToFileAfterDelete(vector <stClientdata> vClientdata)
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


void DeleteClientByAccountNumber()
{
	stClientdata Client;
	vector <stClientdata> vClientdata;

	string AccountNumber =ReadAccountNumber();

	char ChoiceDelete = 'n';


	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	if (FindClientByAccountNumber(AccountNumber, vClientdata, Client))
	{
		cout << "The Following are the client details :\n\n";
		PrintClientRecord(Client);

		cout << "Do you sure you want Delete this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete== 'Y' || ChoiceDelete == 'y')
		{


			MarkClientForDeleteByAccoutNumber(AccountNumber, vClientdata);
			SaveClientDataToFileAfterDelete(vClientdata);


			// Refresh data of file
		//	vClientdata = LoadClientDataFromFile(ClientdataFileName);

			cout << "\n\n Cleint Delete Succefuly. \n";
		}

	}

	else
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}



}

vector <stClientdata> UpdateClient(vector <stClientdata>& vClientdata)
{
	for (stClientdata& Client : vClientdata)

	{
		if (Client.DeleteMark == true)
		{
			cout << "Enter Name ? " << endl;
			getline(cin >> ws, Client.Name);


			cout << "Enter PinCode ? " << endl;
			cin >> Client.PinCode;

			cout << "Enter Phone ? " << endl;
			cin >> Client.Phone;

			cout << "Enter Account Balance ? " << endl;
			cin >> Client.AcoountBalance;
			break;   // Very important to speed code 
		}
	}
	return vClientdata;
}

void UpdateClientByAccountNumber()
{
	stClientdata Client;
	vector <stClientdata> vClientdata;
	
	char ChoiceDelete = 'n';
	
	cout << "\n---------------------------------------\n";
	cout << "\tUpdate Client Screen\n";
	cout << "---------------------------------------\n";
	
	string AccountNumber = ReadAccountNumber();


	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	if (FindClientByAccountNumber(AccountNumber, vClientdata, Client))
	{
		
		PrintClientRecord(Client);

		cout << "Do you sure you want Update this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			MarkClientForDeleteByAccoutNumber(AccountNumber, vClientdata);
			UpdateClient(vClientdata);
			SaveClientDataToFileAfterUpdate(vClientdata);


			// Refresh data of file
		//	vClientdata = LoadClientDataFromFile(ClientdataFileName);

			cout << "\n\n Cleint Update Succefuly. \n";
		}

	}

	else
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}



}


void AddDataLineToFile(string FileName,string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		
		MyFile.close();

	}

}


void printAllClientsData(vector <stClientdata> vClientdata)

{
	cout << setw(40) << "Client List (" << vClientdata.size() << ") Client(S). " << endl;

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(20) << "Pin code";
	cout << "| " << left << setw(20) << "Phone";
	cout << "| " << left << setw(15) << "Balance";

	cout << "\n\n--------------------------------------------------";
	cout << "------------------------------" << endl;


	for (stClientdata Result : vClientdata)
	{

		PrintRecord(Result);
		cout << endl;
	}

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;

}


void ShowClentList()
{
	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	printAllClientsData(vClientdata);

}

void AddNewClient()
{
	stClientdata Client;
	Client=ReadClientData();

	AddDataLineToFile(ClientdataFileName,ConvertRecordToLine(Client));

}

void AddNewClients()
{
	char AddMore = 'n';

	cout << "\n---------------------------------------\n";
	cout << "\tAdd New Client Screen\n";
	cout << "---------------------------------------\n";
	do
	{
		cout << "Adding New Client :\n\n\n";

		AddNewClient();

		cout << "Client Add successfully, Do you want to add more Clients ? Y/N ?\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y' );

	
}


void FindClientAndPrintDetails()
{
	vector <stClientdata> vClientdata;
	stClientdata Client;

	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	string AccountNumber = ReadAccountNumber();
	system("cls");
	cout << "--------------------------------\n";
	cout << "\tFind Client Screen\n";
	cout << "--------------------------------\n";

	for (stClientdata MyClient : vClientdata)
	{
		if (MyClient.AccountNumber == AccountNumber)
		{



			Client = MyClient;
			PrintClientRecord(Client);
			break;
		}

		else
			cout << "Client With Account Number ( " << AccountNumber << " ) is Not found!\n";
		break;
	}
 
}


void GoBackToMainMenu()
{

	cout << "Press any key to go back to Main Menu....\n";
	system("pause>0");
	system("cls");
	ShowMainMenuScreen();
}

void ExitProgram()
{

	cout << "\n\n------------------------------------\n";
	cout << "\tPrograms Ends :-)\n";
	cout << "------------------------------------\n";



}

int ReadNumberChioce()
{

	short NumberDoYouWant = 0;
	cout << "Chose what do you want to do? [1 to 6]?\n";
	cin >> NumberDoYouWant;
	return NumberDoYouWant;
}


void PerformWhatDoYouWant(short NumberDoYouWant)
{
	



	switch (NumberDoYouWant)
	     {
	case  eOptions::eClientList:
	{
		system("cls");
		ShowClentList();
		GoBackToMainMenu();
		break;
	}


	case  eOptions::eAddClient:
	{
		system("cls");
		AddNewClients();
		GoBackToMainMenu();
		break;
	}

	case  eOptions::eDeleteClient:
	{
		system("cls");
		DeleteClientByAccountNumber();
		GoBackToMainMenu();
		break;
	}
	case  eOptions::eUpdateClient:
	{
		system("cls");
		UpdateClientByAccountNumber();
		GoBackToMainMenu();
		break;
	}
	
	case eOptions::eFindClient:
	{

		system("cls");
		FindClientAndPrintDetails();
		GoBackToMainMenu();
		break;

	}

	case eOptions::eExit:
	{

		system("cls");
		ExitProgram();
		
		break;

	}
	      }
}



void ShowMainMenuScreen()
{

	cout << "============================================\n";
    cout << "            Main Menu Screen              \n";
	cout << "============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Fined Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "============================================\n";
	

	PerformWhatDoYouWant(ReadNumberChioce());
}





int main() {


	ShowMainMenuScreen();
	

	


	return 0;
}