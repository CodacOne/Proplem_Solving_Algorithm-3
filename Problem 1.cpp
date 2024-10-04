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



void MiddleRowMatrix(int arr[3][3] ,int MidRowArray[3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{  
		   if(i==1)
		   {
			   MidRowArray[j] = arr[i][j];
		   }
			
		}
	}
}


void MiddleColsMatrix(int arr[3][3], int MidRowArray[3], short Rows, short Cols)
{

	for (int j = 0; j < Cols; j++)
	{
		for (int i = 0; i < Rows; i++)
		{
			if (j == 1)
			{
				MidRowArray[i] = arr[i][j];
			}

		}
	}
}


void PrintMiddleArray(int arr[3], short Elemnts)
{

	for (int i = 0; i < Elemnts; i++)

	{
		printf("%0*d   ", 2, arr[i]);

	}


	cout << endl;
}

int main()

{
	srand(time(NULL));

	int arr[3][3];
	int MidRowArray[3];
	int MidColArray[3];


	cout << " Matrix   : " << endl;
    FillArrayElements(arr, 3, 3);
    PrintArayElements(arr, 3, 3);


	cout << " \n\n Middle Row of Matrix is : " << endl;
	 MiddleRowMatrix(arr, MidRowArray, 3, 3);
	 PrintMiddleArray(MidRowArray, 3);



	 cout << " \n\n Middle col of Matrix is : " << endl;
	 MiddleColsMatrix(arr, MidColArray, 3, 3);
	 PrintMiddleArray(MidColArray, 3);


	system("pause");
	return 0;

}