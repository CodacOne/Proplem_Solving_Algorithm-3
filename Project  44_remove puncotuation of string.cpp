#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Remove puncutuations in All string Using custom Function




void RemovePuncutuationsFromString(string S1)

{

	for (int i = 0; i< S1.length(); i++)
	{

		if (! ispunct(S1[i]))
		{
			cout << S1[i];
		}
		

	}



}

int main() {

	string S1 = "I'm Abdalfattah; from sy:ria ,Welcome to syria :";
	
	

	cout << "\nString After Remove :\n";

	 RemovePuncutuationsFromString(S1) ;

	 cout << "\n\n";
	return 0;
}