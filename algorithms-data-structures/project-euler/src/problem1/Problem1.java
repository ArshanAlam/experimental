/**
 *	@author Arshan Alam
 *
 *	Problem 1
 *
 *	If we list all the natural numbers below 10 that are multiples of 3 or 5,
 *	we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *	
 *	Find the sum of all the multiples of 3 or 5 below 1000.
 **/

package problem1;

class Problem1 {
	public static void main(String[] args) {
		int result = 0;
		
		// The algorithm, below, is using the fact from set theory
		// |A u B| = |A| + |B| - |A n B|
		
		for(int i = 0; i < 1000; i += 3) {
			result += i;
		}
		for(int i = 0; i < 1000; i += 5) {
			if((i % 3) == 0) continue;
			result += i;
		}
		System.out.println(result);
	}
}