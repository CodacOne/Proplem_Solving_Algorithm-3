#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//  Print Sum Cols Matrix


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

			arr[i][j] = RandomNumber(1, 100);

		}


	}

}

void PrintArayElements(int arr[3][3], short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			cout << setw(5) << arr[i][j] << "     ";
		}

		cout << endl;
	}

}

int  ColsSum(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (int i = 0; i < Rows; i++)
	{

		sum = sum + arr[i][Cols];

	}
	return sum;
}



void PrintSumArayElements(int arr[3][3], short Rows, short Cols)
{
	for (int j = 0; j < Cols; j++)
	{

		cout << "Cols : " << j + 1 << "->  Sum =  " << ColsSum(arr,Rows, j) << endl;
	}


}

int main()

{
	srand(time(NULL));

	int arr[3][3];
	int Arrsum[3];
	cout << "The Following is a 3*3 Random Matrix : " << endl;

	FillArrayElements(arr, 3, 3);

	PrintArayElements(arr, 3, 3);
	cout << "\n\nHello" << endl;


	
	PrintSumArayElements(arr, 3, 3);


	system("pause");
	return 0;

}

