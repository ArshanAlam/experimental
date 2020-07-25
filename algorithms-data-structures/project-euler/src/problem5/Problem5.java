/**
 *	@author		Arshan Alam
 *
 *	Problem 5
 *
 * 	2520 is the smallest number that can be divided
 *	by each of the numbers from 1 to 10 without any remainder.
 *	What is the smallest positive number that is evenly divisible
 *	by all of the numbers from 1 to 20?
 **/

package problem5;

class Problem5 {
	public static void main(String[] args) {
		int result = 19;	// Start with 19 because
		// it gets incremented in the while loop to 20.
		// thus we are really started with 20.
		// 20 is the smallest integer divisible by the
		// largest number between 1..20 (namely 20).
		while(!(isDivisibleByAll(++result)));
		System.out.println(result);
	}
	
	/**
	 * Determine if the given integer, num, is divisble
	 * by all integers between 1..20.
	 **/
	static boolean isDivisibleByAll(int num) {
		for(int i = 1; i <= 20; i++) {
			if((num % i) > 0) return false;
		}
		return true;
	}
}