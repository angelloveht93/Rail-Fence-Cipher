/*
 * @author      Cory Bohon <cory@corybohon.com>
 * @version     1.0
 * @since       2012-04-18
 * 
 * @purpose		Class that defines a rail-fence cipher for non-important encryption
 */

class RailFence
{
	//instance variables
	int depth;
	String depth1;
	String depth2;
	
	/* 
	 * RailFence Constructor
	 * 
	 * Initializes the depths and the depth variable
	 * 
	 */
	public RailFence()
	{
		clearAllDepths();
		depth = 2;
		
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
	public String encrypt(String text)
	{
		clearAllDepths();
		
		boolean boolSwitch = true;
		
		for(int counter = 0; counter < text.length(); counter++)
		{
			if(boolSwitch)
			{
				depth1 += text.charAt(counter);
				boolSwitch = false;
			}
			else
			{
				depth2 += text.charAt(counter);
				boolSwitch = true;
			}
		}
		
		String muxedString = depth1 + depth2;
		
		clearAllDepths();
		
		return muxedString;
	}
	
	/*
	 * decrypt
	 * 
	 * Decrypts a passed string of text
	 * 
	 * @param text A string of text to be decrypted
	 * @return The original text 
	 * 
	 */
	public String decrypt(String text)
	{
		clearAllDepths();
		
		int lengthDivision = 0;
		
		if(text.length() %2 != 0)
			lengthDivision = (text.length() / depth)+1;
		else
			lengthDivision = (text.length() / depth);
		
		depth1 = text.substring(0, lengthDivision);
		depth2 = text.substring(lengthDivision, text.length());
		
		String demuxedString = "";
		
		for(int counter = 0; counter < lengthDivision; counter++)
		{
			if(depth1.length() > counter)
			{
				demuxedString += depth1.charAt(counter);
			}
			
			if(depth2.length() > counter)
			{
				demuxedString += depth2.charAt(counter);
			}
		}
		
		clearAllDepths();
		
		return demuxedString;
	}
	
	/*
	 * clearAllDepths
	 * 
	 * Clears out the strings in all of the depth String variables
	 * 
	 */
	private void clearAllDepths()
	{
		depth1 = "";
		depth2 = "";
	}
}