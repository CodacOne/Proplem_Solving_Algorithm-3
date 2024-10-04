#include<iostream>

using namespace std;

char ReadChar()
{
	char charLetter ;
	cout << "Enter a chararacter pls :" << endl;
	cin >> charLetter;
	return charLetter;

}


bool IsVowel(char CharLetter)
{

	CharLetter = tolower(CharLetter);

	return ((CharLetter == 'a') || (CharLetter == 'e') || (CharLetter == 'o') || (CharLetter == 'i') || (CharLetter == 'u'));
}


int main()
{

	char character=ReadChar();
	cout << character << endl;
	if (IsVowel(character))
	{
		cout <<"Yes Letter "<< character <<" Is Vowel"<<endl;
	}

	else 
		cout << "NO Letter " << character << " Is NOT Vowel" << endl;
}