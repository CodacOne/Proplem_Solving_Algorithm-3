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




bool CheckMatricesIfAreScalar(int arr[3][3], short Rows, short Cols)
{  
	int FirstDiagonalElements = arr[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			

			if (i == j &&   arr[i][j]!= FirstDiagonalElements)
			{
				

				return false;
			}

			else if (i != j &&  arr[i][j] != 0)
			{
				return false;

			}

		}

	}
	return true;

}


int main()

{
	srand(time(NULL));

	int arr[3][3] = { { 5,0,0 },{ 0,5,0},{ 0,0,5 } };




	cout << "\nMatrix   : " << endl;

	PrintArayElements(arr, 3, 3);



	if (CheckMatricesIfAreScalar(arr, 3, 3))


		cout << " \n Yes, Matrix Is Scalar ." << endl;

	else if (!CheckMatricesIfAreScalar(arr, 3, 3))

	{
		cout << " \n No, Matrix Is NOT Scalar ." << endl;
	}

	system("pause");
	return 0;

}