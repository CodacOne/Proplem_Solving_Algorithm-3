#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//  Generate Tow Random Number Array  of 1 to 100


int RandomNumber(int from, int to)
{
	int randomNumber;

	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}


void FillArrayElements(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			arr[i][j] = RandomNumber(1, 10);

		}


	}

}

void PrintArayElements(int arr[3][3], short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			printf("%0*d   ", 2, arr[i][j]); 
		}

		cout << endl;
	}

}



void MultiTowMatrix(int arr1[3][3] ,int arr2[3][3],
	            int SumArray[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			SumArray[i][j] = arr1[i][j] * arr2[i][j];
			
		}
	}
}

int main()

{
	srand(time(NULL));

	int arr1[3][3];
	int arr2[3][3];
	int ResultArray [3][3];
	cout << " Matrix  1 : " << endl;
    FillArrayElements(arr1, 3, 3);
    PrintArayElements(arr1, 3, 3);


	cout << " \n\nMatrix  2 : " << endl;
	FillArrayElements(arr2, 3, 3);
    PrintArayElements(arr2, 3, 3);

	cout << "\n\n Results  : " << endl;
	 MultiTowMatrix(arr1,arr2, ResultArray, 3, 3);
	 PrintArayElements(ResultArray, 3, 3);


	system("pause");
	return 0;

}