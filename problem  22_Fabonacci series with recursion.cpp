#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



void FibonacciSeriesUsingRecursion(int Number, int prev1, int prev2)
{


	short FebSeries = 0;


	if (Number > 0)
	{
		FebSeries = prev2+ prev1;
		prev1 = FebSeries;
		prev2 = prev1;

		cout << FebSeries << " ";
		FibonacciSeriesUsingRecursion(Number - 1, prev1, prev2);
	}
	
}


int main()

{
	
	
	


	cout << "\n Fibonacci Series  : " << endl;
	FibonacciSeriesUsingRecursion(10,0,1);



	system("pause");
	return 0;

}