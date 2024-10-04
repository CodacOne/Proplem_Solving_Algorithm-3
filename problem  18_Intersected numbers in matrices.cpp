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

bool IsNumberInMatrix_2_(short Number, int arr2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			if (Number == arr2[i][j])
			{

				return true;
			}

		}

	}
	return false;
}
void CheckIntersectedNumbers(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	int Number = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Number = arr1[i][j];
			if (IsNumberInMatrix_2_(Number, arr2, Rows, Cols))
			{
				cout << Number << "  ";
					
			}
		}

	}
}


int main()

{
	srand(time(NULL));
	short const Rows = 3;
	short const Cols = 3;

	int arr1[Rows][Cols] = { { 5,2,3 },{ 4,9,20 },{ 7,0,50 } };
	int arr2[Rows][Cols] = { { 5,10,0 },{ 7,19,1 },{ 30,3,49 } };
	





	cout << "\nMatrix 1  : " << endl;
	PrintArayElements(arr1, Rows, Cols);

	cout << "\nMatrix 2  : " << endl;
    PrintArayElements(arr2, Rows, Cols);


	cout << "\n Intersected Numbers Are : " << endl;
	
	CheckIntersectedNumbers(arr1, arr2, Rows, Cols);


	system("pause");
	return 0;

}