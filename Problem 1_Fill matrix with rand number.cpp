#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
 

//  Generate Random Number Array  of 1 to 100


int RandomNumber(int from, int to)
{
	int randomNumber;

	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}


void FillArrayElements(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			arr[i][j] = RandomNumber(1, 100);
		}


	}

}

void PrintArayElements(int arr[3][3])
{


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			cout<<setw(5)<<arr[i][j]<<"     ";
		}

		cout << endl;
	}




}

int main()

{  
	srand(time(NULL));
	 
	int arr[3][3];

	cout << "The Following is a 3*3 Random Matrix : " << endl;

   FillArrayElements(arr);
    
   PrintArayElements(arr);

	cout << "\n\nHello" << endl;

	system("pause");
	return 0;

} 