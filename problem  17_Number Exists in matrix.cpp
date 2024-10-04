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

bool CheckMatrixIfNumberIsExists(int arr[3][3], short Number, short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Number == arr[i][j])
			{
				return true;
			}

		}

	}
	return false;
}


int main()

{
	srand(time(NULL));
	short const Rows = 3;
	short const Cols = 3;
	int arr[Rows][Cols] = { { 5,0,0 },{ 0,9,0 },{ 0,0,5 } };
	short NumberLookFor = 0;



	cout << "\nMatrix   : " << endl;

	PrintArayElements(arr, Rows, Cols);

	cout << "\n Enter the number to look for in Matrix : " << endl;
	cin >> NumberLookFor;



	if (CheckMatrixIfNumberIsExists(arr, NumberLookFor, Rows, Cols))
	{
		cout << "\n Yes it is there: " << endl;
	}
	else
		cout << "\n NO It's NOT  there : " << endl;


	system("pause");
	return 0;

}