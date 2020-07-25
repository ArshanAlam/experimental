/**
*	Author:	Arshan Alam
*
*	Problem 10
*
*	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
*
*	Find the sum of all the primes below two million.
*
*/

package problem10;

public class Problem10 {

	/**
	*	isPrime
	*	<p>
	*		Determine if the given integer `n` is prime.
	*	</p>
	*	@param n - Positive integer.
	*
	*	@return true if n is prime, false otherwise.
	*/
	static boolean isPrime(int n) {
		if (n == 2) {
			return true;
		} else if ((n < 2) || ((n % 2) == 0)) {
			return false;
		}

		for (int i = 3; i <= Math.sqrt(n); i += 2) {
			if ((n % i) == 0) {
				return false;
			}
		}
		return true;
	}

	static final int UPPER_BOUND = 2000000;

	public static void main(String[] args) {
		long sum = 2L;
		for (int i = 3; i < UPPER_BOUND; i += 2) {
			if (isPrime(i)) {
				sum += i;
			}
		}
		System.out.println(sum);
	}
}
