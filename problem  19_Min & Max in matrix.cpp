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

int PrintMinInMatrix(int arr1[3][3], short Rows, short Cols)
{
	int MinNumber = arr1[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (MinNumber > arr1[i][j])
			{
				MinNumber = arr1[i][j];

			}
		}

	}   return MinNumber;
}



int PrintMaxInMatrix(int arr1[3][3], short Rows, short Cols)
{

	int MaxNumber = arr1[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (MaxNumber < arr1[i][j])
			{
				MaxNumber = arr1[i][j];

			}
		}

	}   return MaxNumber;

}

int main()

{
	srand(time(NULL));
	short const Rows = 3;
	short const Cols = 3;

	int arr1[Rows][Cols] = { { 5,2,3 },{ 4,9,20 },{ 7,10,540 } };
	

	cout << "\nMatrix 1  : " << endl;
	PrintArayElements(arr1, Rows, Cols);

	


	cout << "\n Intersected Numbers Are : " << endl;

	cout<<" Minumum Number is : "<< 
		PrintMinInMatrix(arr1, Rows, Cols)<<"\n\n";

		
	cout << " Maximum Number is : " << 
		PrintMaxInMatrix(arr1, Rows, Cols)<<"\n\n";

	system("pause");
	return 0;

}