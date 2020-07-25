/**
 *	Author:	Arshan Alam
 *
 * Project Euler
 * 
 * Problem 9
 *
 */

package problem9;

/**
 *	<p>
 *		A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *	</p>
 *	<p>
 *		a^2 + b^2 = c^2
 *	</p>
 *
 *	<p>
 *		For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *	</p>
 *
 *	<p>
 *		There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *	</p>
 *
 *	<p>
 *		Find the product abc.
 * </p>
 **/
public class Problem9 {
	
	/**
	 * <p>
	 * 		Get a the product of Pythagorean triplets that
	 * 		add up to the given sum.
	 * 	</p>
	 * 
	 * <p>
	 * 		That is find
	 * 		{ a * b * c | a < b < c; a^2 + b^2 = c^2 and a + b + c = sum }
	 * </p>
	 * 
	 * @return	The product > 0 or -1 if the solution could not be determined
	 **/
	public static int getProductOfPythagoreanTriplet(int sum) {
		int product = -1;
		for(int c = 5; c < sum; c++) {
			for (int b = 4; b < c; b++) {
				int a = sum - c - b;
				if((a < b) && (a*a + b*b) == (c*c)) {
					return a*b*c;
				}
			}
		}
		return product;
	}	// end of getProductOfPythagoreanTriplet
	
	public static void main(String[] args) {
		System.out.println(getProductOfPythagoreanTriplet(1000));
	}
}	// end of class