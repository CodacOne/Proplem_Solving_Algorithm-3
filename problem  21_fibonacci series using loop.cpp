#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



void FibonacciSeries( short Number,int arr[100])
{

    arr[0] = 1;
   arr[1] = 1;

	short sum = 0;

	for (int i = 2; i < Number; i++)
	{
		
		arr[i] = arr[i-1] +arr[i - 2];
		cout << endl;
	}

}





void PrintFibonacciSeries(short Number, int arr[100])
{

	for (int i = 0; i < Number; i++)
	{

		cout << arr[i] << " ";
		
	}
	cout << "\n\n";
}




int main()

{
	//srand(time(NULL));

	int arr[100];
	short number;

	cout << "\n Enter the Number you want to print series  : " << endl;
	cin >> number;


	cout << "\n Fibonacci Series  : " << endl;
	FibonacciSeries(number, arr);

	PrintFibonacciSeries(number, arr);

	system("pause");
	return 0;

}