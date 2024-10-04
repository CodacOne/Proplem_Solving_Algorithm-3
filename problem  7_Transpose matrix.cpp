#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//  print Array In Order numbers

void FillMatrixWithOrderNumber(int arr[3][3], short Rows, short Cols)

{
	int counter = 0;

	for (int i = 0; i < Rows; i++)
	{

		for (int j = 0; j < Cols; j++)
		{
			counter++;
			arr[i][j] = counter;


		}
	}
}

void PrintArayBeforeElements(int arr[3][3], short Rows, short Cols)
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





void PrintArrayElements (int arr[3][3], short Rows, short Cols)
{
	

	for (int j = 0; j < Cols; j++)
	{

		for (int i = 0; i < Rows; i++)
		{


			cout << setw(5) << arr[i][j] << "     ";

		}

		cout << endl;
	}

}




int main()

{
	srand(time(NULL));

	int arr[3][3];

	cout << "The Following is a 3*3 Orderd Matrix : " << endl;

	FillMatrixWithOrderNumber(arr, 3, 3);
	PrintArayBeforeElements(arr, 3, 3);

	cout << "\n\nThe Following is a 3*3 transported Matrix : " << endl;
	
	PrintArrayElements(arr, 3, 3);
	cout << "\n\nHello" << endl;




	system("pause");
	return 0;

}

