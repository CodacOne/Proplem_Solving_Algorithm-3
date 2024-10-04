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

int PrintSumNumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum = sum + arr[i][j];

		}

	}
	return sum;

}

void CheckMatricesIfAreEqual(short SumArray1, short SumArray2)

{
	if (SumArray1 == SumArray2)
	{

		cout << "\n Yes , Both Matrices Are equal  -) " << endl;

	}

	else 
		cout << " \n No , The Matrices Are NOT equal -( \n" << endl;



}

int main()

{
	srand(time(NULL));

	int arr1[3][3];
	int arr2[3][3];
	int SumMatrixOf1=0, SumMatrixOf2=0;

	cout << "\nMatrix 1  : " << endl;
	FillArrayElements(arr1, 3, 3);
	PrintArayElements(arr1, 3, 3);


	cout << " \nMatrix 2  : " << endl;
	FillArrayElements(arr2, 3, 3);
	PrintArayElements(arr2, 3, 3);


	SumMatrixOf1 =PrintSumNumOfMatrix(arr1, 3, 3);
	SumMatrixOf2 =PrintSumNumOfMatrix(arr2, 3, 3);

	cout << " \nSum Matrix 1  : " << SumMatrixOf1<< endl;
	cout << " \nSum Matrix 2  : " << SumMatrixOf2 << endl;

	CheckMatricesIfAreEqual(SumMatrixOf1, SumMatrixOf2);

	system("pause");
	return 0;

}