/**
 *	@author		Arshan Alam
 *
 *	Problem 4
 *
 * 	A palindromic number reads the same both ways.
 * 
 * 	The largest palindrome made from the product of two
 * 	2-digit numbers is 9009 = 91 × 99.
 * 
 * 	Find the largest palindrome made from the product of two 3-digit numbers.
 **/


package problem4;

class Problem4 {
	public static void main(String[] args) {
		
		// Largest Palindrome so-far
		int largest = 0;
		// Iterate from the largest 3-digit numbers
		for(int i = 999; i >= 100; i--) {
			for(int j = 999; j >= 100; j--) {
				int curNum = i*j;
				// if we find a palindrome then print it
				if(isPalindrome(curNum)) {
					// If the current palindrome is greater
					// then the largest so-far, then set
					// the largest palindrome to be the
					// current palindrome
					if(largest < curNum) {
						largest = curNum;
					}
					// and break out of the outer for loop
				}
			}	
		}
		System.out.println(largest);
	}
	
	/**
	 * Determine if the given integer, num, is a Palindrome.
	 **/
	static boolean isPalindrome(int num) {
		/**
		 * Maximum length of a number that is the product
		 * of two 3-digit numbers is 6.
		 */
		int digit[] = new int[6];
		
		int length = 0;
		int tempNum;
		
		// Store all the digits of the given num in the digit array
		while((tempNum = (int) (num / Math.pow(10, length))) > 0) {
			digit[length++] = (tempNum % 10);
		}
		
		// compare the first half of the num with the second half
		for(int i = 0; i < length/2; i++) {
			if(digit[i] != digit[length-(i+1)]) {
				return false;
			}
		}
		return true;
	}
}