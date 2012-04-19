/*
	File		RailFenceDemo.cpp
	Author		Cory Bohon <cory@corybohon.com>
	Date		April 18, 2012
	Version		1.0
	Purpose		To demonstrate the RailFence class
*/

#include "RailFence.h"
#include <iostream>
#include <string.h>

using namespace std; 
	
int main()
{
	//Create a new RailFence object
	RailFence *railFence = new RailFence();

	//Create the string containing the original text
	string original_text = "This is my name...";
	
	//Print out the original text
	cout << "ORIGINAL TEXT:" << original_text << endl;
	
	//Encrypt the original text, storing the return in a new variable
	string encrypted_text = (*railFence).encrypt(original_text);
	
	//Print out the encrypted text
	cout << "ENCRYPTED TEXT:" << encrypted_text << endl;
	
	//Decrypt the encrypted text, storing the return in a new variable 
	string decrypted_text = (*railFence).decrypt(encrypted_text);
	
	//Print out the decrypted text 
	cout << "DECRYPTED TEXT:" << encrypted_text << endl;
	
	return 0;
}