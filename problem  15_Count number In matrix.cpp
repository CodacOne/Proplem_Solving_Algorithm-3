#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



void PrintArayElements(int arr[3][3], short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			// printf("%0*d   ", 2, arr[i][j]);
			cout << setw(5) << arr[i][j];
		}

		cout << endl;
	}

}




int CheckMatrixToCountGivenNumber(int arr[3][3], short CountNumber, short Rows, short Cols)
{
	int counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (CountNumber == arr[i][j])
			{
				counter++;
			}

		}

	}
	return counter;
}


int main()

{
	srand(time(NULL));

	int arr[3][3] = { { 5,9,9 },{ 0,9,2 },{ 9,07,5 } };
	short CountNumber = 0;



	cout << "\nMatrix   : " << endl;

	PrintArayElements(arr, 3, 3);
	cout << "\n Enter The Number to count in matrix  : " << endl;
	cin >> CountNumber;

	CheckMatrixToCountGivenNumber(arr, CountNumber, 3, 3);
	cout << "\n Number " << CountNumber << " count in matrix is : " <<
		CheckMatrixToCountGivenNumber(arr, CountNumber, 3, 3) << endl;
	system("pause");
	return 0;

}