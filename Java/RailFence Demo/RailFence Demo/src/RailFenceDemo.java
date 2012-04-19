/*
 * @author		Cory Bohon <cory@corybohon.com>
 * 
 * Purpose		Demonstrate the RailFence cipher in action
 * 
 */

public class RailFenceDemo 
{

	public static void main(String[] args) 
	{
		//string to be encrypted
		String originalText = "This is my name...";
			
		//Print out the original string
		System.out.println("Original Text: \t\t" + originalText);
		
		//create a new RailFence object
		RailFence fence = new RailFence();
		
		//call the method encrypt in the RailFence class to encrypt the passed originalText 
		//store the return in the encryptedString variable
		String encryptedString = fence.encrypt(originalText);
		
		//Print out the encrypted text
		System.out.println("Encrypted Text: \t" + encryptedString);
		
		//call the method decrypt in the RailFence class to decrypt the passed encryptedText
		//store the return in the decryptedString variable 
		String decryptedString = fence.decrypt(encryptedString);
		
		//Print out the decrypted text
		System.out.println("Decrypted Text: \t" + decryptedString);
	}

}
