#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

// Read Clients file and Show them on the screen 

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

	vClinteData =SplitString(line, Delim);

	sClientdata.AccountNumber = vClinteData[0];
	sClientdata.Name = vClinteData[1];
	sClientdata.PinCode = vClinteData[2];
	sClientdata.Phone = vClinteData[3];
	sClientdata.AcoountBalance = stod(vClinteData[4]); // casting string to double

	return sClientdata;
}



vector <stClientdata> LoadClientDataFromFile(string FileName)
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

		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(10) << left << Client.Phone;
		cout << "| " << setw(15) << left << Client.AcoountBalance;
		

	}

	


	void printAllClientsData(vector <stClientdata> vClientdata)

	{
		cout << setw(40) << "Client List (" << vClientdata.size() << ") Client(S). " << endl;

		cout << "--------------------------------------------------";
			cout << "------------------------------" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(10) << "Pin code";
		cout << "| " << left << setw(10) << "Phone";
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
int main() {

	vector <stClientdata> vClientdata;
	
	vClientdata =LoadClientDataFromFile(ClientdataFileName);

	printAllClientsData(vClientdata);




	return 0;
}