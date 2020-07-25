/**
 *	@author		Arshan Alam
 *
 *	@dateCompleted 20151104
 *
 *	Project Euler
 *
 *	Problem 8
 *
 * The four adjacent digits in the 1000-digit number that
 * have the greatest product are 9 × 9 × 8 × 9 = 5832.
 * 
 *
		73167176531330624919225119674426574742355349194934
		96983520312774506326239578318016984801869478851843
		85861560789112949495459501737958331952853208805511
		12540698747158523863050715693290963295227443043557
		66896648950445244523161731856403098711121722383113
		62229893423380308135336276614282806444486645238749
		30358907296290491560440772390713810515859307960866
		70172427121883998797908792274921901699720888093776
		65727333001053367881220235421809751254540594752243
		52584907711670556013604839586446706324415722155397
		53697817977846174064955149290862569321978468622482
		83972241375657056057490261407972968652414535100474
		82166370484403199890008895243450658541227588666881
		16427171479924442928230863465674813919123162824586
		17866458359124566529476545682848912883142607690042
		24219022671055626321111109370544217506941658960408
		07198403850962455444362981230987879927244284909188
		84580156166097919133875499200524063689912560717606
		05886116467109405077541002256983155200055935729725
		71636269561882670428252483600823257530420752963450
 * 
 * 
 * Find the thirteen adjacent digits in the 1000-digit
 * number that have the greatest product.
 * What is the value of this product?
 */

package problem8;

class Problem8 {
	public static void main(String[] args) {
		
		final String NUM_STR =
			"73167176531330624919225119674426574742355349194934"
		+	"96983520312774506326239578318016984801869478851843"
		+	"85861560789112949495459501737958331952853208805511"
		+	"12540698747158523863050715693290963295227443043557"
		+	"66896648950445244523161731856403098711121722383113"
		+	"62229893423380308135336276614282806444486645238749"
		+	"30358907296290491560440772390713810515859307960866"
		+	"70172427121883998797908792274921901699720888093776"
		+	"65727333001053367881220235421809751254540594752243"
		+	"52584907711670556013604839586446706324415722155397"
		+	"53697817977846174064955149290862569321978468622482"
		+	"83972241375657056057490261407972968652414535100474"
		+	"82166370484403199890008895243450658541227588666881"
		+	"16427171479924442928230863465674813919123162824586"
		+	"17866458359124566529476545682848912883142607690042"
		+	"24219022671055626321111109370544217506941658960408"
		+	"07198403850962455444362981230987879927244284909188"
		+	"84580156166097919133875499200524063689912560717606"
		+	"05886116467109405077541002256983155200055935729725"
		+	"71636269561882670428252483600823257530420752963450";
		
		final int LENGTH = NUM_STR.length();	// The length of numStr
		final int NUM_ADJACENT_DIGITS = 13;
		
		// NOTE double precision is needed because the largest product
		// exceeds MAX_INT
		
		double largestProduct = 1;
		double prevAdjacentProduct;
		for(int i = 0; i < NUM_ADJACENT_DIGITS; i++) {
			// subtracting the character '0' from NUM_STR.charAt(i)
			// parses NUM_STR.charAt(i) to an integer
			largestProduct *= NUM_STR.charAt(i) - '0';
		}
		
		// by default the previous adjacent product is the
		// largestProduct initially!
		prevAdjacentProduct = largestProduct;
		
		for(int i = NUM_ADJACENT_DIGITS; i < LENGTH; i++) {
			// the factor that will be leaving the prevAdjacentProduct
			int outFactor = NUM_STR.charAt(i-NUM_ADJACENT_DIGITS) - '0';
			
			// the factor that will be entering prevAdjacentProduct
			int inFactor = NUM_STR.charAt(i) - '0';
			
			// The next adjacent product from NUM_STR
			double curProduct = prevAdjacentProduct;
			
			// If both inFactor and outFactor are not 0 then determine
			// the current product
			if((outFactor != 0)
				&& (inFactor != 0)) {
				curProduct /= outFactor;
				curProduct *= inFactor;
			} else if(outFactor == 0) {
				// if the outFactor is 0, then we must re-calculate
				// the current product
				curProduct = 1;
				for(int j = i - NUM_ADJACENT_DIGITS + 1;
						j <= i;
						j++) {
					// subtracting the character '0' from NUM_STR.charAt(i)
					// parses NUM_STR.charAt(i) to an integer
					curProduct *= NUM_STR.charAt(j) - '0';
				}
			} else {
				// Lastly, if inFactor is 0, then the current product is zero
				curProduct = 0;
				
				// Skip the next NUM_ADJACENT_DIGITS adjacent products
				// because they will all be zero!
				i+= NUM_ADJACENT_DIGITS - 1;
			}

			// if the current product is larger than the
			// largest product, then set the current product
			// to be the largest product
			if(curProduct > largestProduct) {
				largestProduct = curProduct;
			}	// end of if block
			
			// set the previous product to be the current product
			prevAdjacentProduct = curProduct;
		}	// end of for block
		
		// SINCE we are using double precision, the result will
		// be in scientific notation
		// Thus we must manually convert it back into an integer
		// print the largest product in NUM_STR
		System.out.println(largestProduct);
	}	// end of main
}	// end of class