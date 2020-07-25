/**
 *	@author	Arshan Alam
 *
 *	Date Modified: 20160125
 */

package problem7;

/**
 *	<p>
 *		Problem 7
 *	</p>
 *	<p>
 *		By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *	</p>
 *	<p>
 *		What is the 10 001st prime number?
 *	</p>
 */
public class Problem7 {
	
	/**
	 * <p>isPrime</p>
	 * 
	 * @param num - The number to check for primeness.
	 * 
	 * @return boolean
	 * 
	 * <p>true	:	num is prime</p>
	 * <p>false	:	num is not prime</p>
	 **/
	public static boolean isPrime(int num) {
		if(num <= 1) {
			return false;
		} else if(num == 2) {
			// 2 is prime
			return true;
		} else if(num % 2 == 0) {
			// 2 is the only even prime number
			//
			// hence any even number greater than 2 is not prime
			return false;
		}
		
		// We only need to check for factors of 'num'
		// until the square root since if there are multiples
		// and each pair of the multiple will either be greater than
		// or less than the square root
		int sqrNum = (int) Math.sqrt(num);
		
		// since prime numbers > 2 are odd, we increase
		// the iterator by 2 (iterator is odd number)
		//
		// and all composite numbers have prime factors
		for(int i = 3; i <= sqrNum; i += 2) {
			if(num % i == 0) {
				return false;
			}
		}
		
		// if we reach this far in the method, then
		// 'num' has no factors, hence 'num' is prime
		return true;
	}	// end of isPrime
	
	public static void main(String[] args) {
		int primeCounter = 1;
		int num = 1;
		while(primeCounter < 10001) {
			// since prime numbers > 2 are odd, we increase
			// by 2 ('num' is always odd)
			num += 2;
			if(isPrime(num)) {
				primeCounter++;
			}
		}
		System.out.println(num);
	}	// end of main
}	// end of Problem7