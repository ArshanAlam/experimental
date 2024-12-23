/**
 *	@author		Arshan Alam
 *
 * 	Problem 2
 * 
 * 	Each new term in the Fibonacci sequence is generated by adding
 * 	the previous two terms. By starting with 1 and 2, the first 10 terms
 * 	will be:
 * 
 * 	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 
 * By considering the terms in the Fibonacci sequence whose
 * values do not exceed four million, find the sum of the even-valued terms.
 **/

package problem2;

// Here is my direct solution to the problem.

class Problem2 {
	public static void main(String[] args) {
		int result = 0;
		int term = 2;
		int termVal = 2;
		while(termVal < 4000000) {
			if((termVal % 2) == 0) result += termVal;
			termVal = fib(++term);
		}
		System.out.println(result);
	}
	
	static int fib(int term) {
		return
				(term == 1)? 1:
					(term == 2)? 2:
						fib(term - 1) + fib(term - 2);
	}
}