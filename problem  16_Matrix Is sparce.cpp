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

int CheckMatrixIfSparce(int arr[3][3], short Rows, short Cols)
{
	int NumberOfZeros = 0, counter = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (NumberOfZeros == arr[i][j])
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
	short Rows = 3;
	short Cols = 3;
	int arr[3][3] = { { 5,0,0 },{ 0,9,0 },{ 0,0,5 } };
	



	cout << "\nMatrix   : " << endl;

	PrintArayElements(arr, 3, 3);
	
	

	if (CheckMatrixIfSparce(arr, 3, 3) > (Rows * Cols) / 2)
	{
		cout << "\n Yes Is it Sparse : " << endl;
	}
	else
		cout << "\n NO It's NOT  Sparse : " << endl;
	system("pause");
	return 0;

}