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

void ChangeColomnsArray(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			arr2[i][j] = arr1[i][Cols-1-j];
			
		}

		cout << endl;
	}



}



bool CheckIfPalindromeOrNot(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{


	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr2[i][j] != arr1[i][j])
			{
				return false;
			}
			

		}

		
	}
	return true;
}


int main()

{
	//srand(time(NULL));
	
	int arr1[3][3] = { { 1,2,1 }
		,{ 4,9,4 }
	,{ 7,10,7 } };

	int arrPalindrom[3][3];

	cout << "\nMatrix 1  : " << endl;
	PrintArayElements(arr1, 3, 3);


	 ChangeColomnsArray(arr1, arrPalindrom, 3, 3);

	cout << "\nMatrix 2  : " << endl;
	PrintArayElements(arrPalindrom, 3, 3);

	if (CheckIfPalindromeOrNot(arr1, arrPalindrom, 3, 3))
	{
		cout << " \n\nYes: matrix is palindrome" << endl;
	}

	else 
		cout << " \n\nNo: matrix is Not palindrome" << endl;
	system("pause");
	return 0;

}