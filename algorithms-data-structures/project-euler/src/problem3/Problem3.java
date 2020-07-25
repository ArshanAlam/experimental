/**
 *	@author		Arshan Alam
 *
 *	Problem 3
 *
 *
 *	The prime factors of 13195 are 5, 7, 13 and 29.
 *	
 *	What is the largest prime factor of the number 600851475143 ?
 **/

package problem3;

class Problem3 {
	public static void main(String[] args) {
		long nextNum = 1;
		long largestPrimeFactor = 0L;
		final long NUM = 600851475143L;
		long product = 1L;
		
		/**
		 * If we did not find the largest prime factor in
		 * the pimreNum array, then start from the largest
		 * prime factor from the array, and find the largest
		 * prime fact for NUM.
		 */
		while(true) {
			if(NUM % ++nextNum == 0) {
				if (isPrime(nextNum)) {
					largestPrimeFactor = nextNum;
				}
				product *= nextNum;
				if(product == NUM) {
					break;
				}
			}
		}
		
		System.out.println(largestPrimeFactor);
	}
	
	/**
	 * Determine if the given long number is prime.
	 **/
	static boolean isPrime(long num) {
		if(num == 2) return true;
		else if(num % 2 == 0) return false;
		for (int i = 3; i < Math.sqrt(num); i+=2) {
			if(num % i == 0) return false;
		}
		return true;
	}
	
}