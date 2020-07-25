/**
 *	@author		Arshan Alam
 *
 **/

package problem6;
/**
 * 	<p>
 *		Problem 6
 *	</p>
 *
 *	<p>
 *		The sum of the squares of the first ten natural numbers is,
 *	</p>
 *
 *	<p>
 *		1^2 + 2^2 + ... + 10^2 = 385
 *	</p>
 *
 *	<p>
 *		The square of the sum of the first ten natural numbers is,
 *	</p>
 *
 *	<p>
 *		(1 + 2 + ... + 10)^2 = 55^2 = 3025
 *	</p>
 *
 *	<p>
 *		Hence the difference between the sum of the squares of the
 *		first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *	</p>
 *
 *	<p>
 *		Find the difference between the sum of the squares of
 *		the first one hundred natural numbers and the square of the sum.
 *	</p> 
 **/
public class Problem6 {
	public static void main(String[] args) {
		/**
		 * Solution uses facts from Mathematics
		 *
		 * sum[i: 1..n](i) = (n)(n+1)/2
		 *
		 * sum[i: 1..n](i^2) = (n)(n+1)(2n+1)/6
		 **/
		System.out.println(
				(((100*(100+1))/2)*((100*(100+1))/2))
				-
				((100*(100+1)*(2*100 + 1))/6));
	}	// end of main
	
}	// end of class Problem6