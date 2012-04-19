/*
	File:		RailFence.cpp
	Author: 	Cory Bohon <cory@corybohon.com>
	Date: 		April 18, 2012
	Version: 	1.0
	Purpose:	Implementation file for RailFence.h that defines a rail-fence cipher for non-import encryption
*/

#include "RailFence.h"
#include <iostream>
#include <string.h>

using namespace std;

/* 
* RailFence Constructor
* 
* Initializes the depths and the depth variable
*/
RailFence :: RailFence(void)
{
	depths = 2; 
	depth1 = "";
	depth2 = "";
}//end constructor

/*
 * Encrypt
 * 
 * Encrypts a passed text string
 * 
 * @param text A string of text to be encrypted
 * @return Returns an encrypted string of text
 * 
 */
public string RailFence :: encrypt(string text)
{
	string muxedString = "";
	depth1 = "";
	depth2 = "";
	
	boolean boolSwitch = true;
	
	for(int counter = 0; counter < text.length(); counter++)
	{
		if(boolSwitch)
		{
			strcpy(depth1, text[counter]);
			boolSwitch = false;
		}
		else
		{
			strcpy(depth2, text[counter]);
			boolSwitch = true;
		}
	}
	
	String muxedString = depth1 + depth2;
	
	return muxedString;
}//end encrypt

/*
 * decrypt
 * 
 * Decrypts a passed string of text
 * 
 * @param text A string of text to be decrypted
 * @return The original text 
 * 
 */
public string RailFence :: decrypt(string text)
{
	string demuxedString = "";
	depth1 = "";
	depth2 = "";
	
	int lengthDivision = 0;
	
	if(text.length() %2 != 0)
		lengthDivision = (text.length() / depth)+1;
	else
		lengthDivision = (text.length() / depth);
	
	depth1 = text.substr(0, lengthDivision);
	depth2 = text.substr(lengthDivision, text.length());
	
	String demuxedString = "";
	
	for(int counter = 0; counter < lengthDivision; counter++)
	{
		if(depth1.length() > counter)
		{
			strcpy(demuxedString, depth1[counter]);
		}
		
		if(depth2.length() > counter)
		{
			strcpy(demuxedString, depth2[counter]);
		}
	}
	
	return demuxedString;
}//end decrypt