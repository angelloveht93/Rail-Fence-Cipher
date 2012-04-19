/*
	File:		RailFence.h
	Author: 	Cory Bohon <cory@corybohon.com>
	Date: 		April 18, 2012
	Version: 	1.0
	Purpose:	Header file for RailFence.cpp that defines a rail-fence cipher for non-import encryption
*/

#include <iostream>
#include <string.h>

using namespace std;

class RailFence
{
	public:
		string encrypt(string text);
		string decrypt(string text);

	private:
		string 	depth1;
		string 	depth2;
		int		numberOfDepths;
	};