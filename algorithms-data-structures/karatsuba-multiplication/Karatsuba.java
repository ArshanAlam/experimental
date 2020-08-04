import java.util.Arrays;

class Karatsuba {
  public static void main(String[] args) {
    if (args.length != 2) {
      System.exit(-1);
    }
    System.out.println(Karatsuba.multiply(args[0], args[1]));
  }

  private Karatsuba() {}
  

  /**
   * Multiple two large integers s1 * s2.
   * The basic steps involved in the algorithm outlined in https://en.wikipedia.org/wiki/Karatsuba_algorithm#Basic_step
   * are very useful for getting started.
   */
  public static String multiply(String s1, String s2) {
    if ((s1.length() <= 2) && (s2.length() <= 2)) {
      return String.valueOf(Integer.valueOf(s1) * Integer.valueOf(s2));
    }
    
    int n = Math.max(s1.length(), s2.length());
    int nHalf = n / 2;

    System.out.println();
    String[] s1Terms = Karatsuba.getTerms(s1);
    String[] s2Terms = Karatsuba.getTerms(s2);
    System.out.println("s1Terms = " + Arrays.toString(s1Terms));
    System.out.println("s2Terms = " + Arrays.toString(s2Terms));
    
    String z0 = Karatsuba.multiply(s1Terms[0], s2Terms[0]);
    String z1 = Karatsuba.multiply(s1Terms[1], s2Terms[1]);
    System.out.println("z0 = s1Terms[0] * s2Terms[0] = " + s1Terms[0] + " * " + s2Terms[0] + " = " + z0);
    System.out.println("z1 = s1Terms[1] * s2Terms[1] = " + s1Terms[1] + " * " + s2Terms[1] + " = " + z1);

    String s1Sum = Karatsuba.add(s1Terms[0], s1Terms[1]);
    String s2Sum = Karatsuba.add(s2Terms[0], s2Terms[1]);
    System.out.println("s1Sum = s1Terms[0] + s1Terms[1] = " + s1Terms[0] + " + " + s1Terms[1] + " = " + s1Sum);
    System.out.println("s2Sum = s2Terms[0] + s2Terms[1] = " + s2Terms[0] + " + " + s2Terms[1] + " = " + s2Sum);

    String sumProd = Karatsuba.multiply(s1Sum, s2Sum);
    System.out.println("sumProd = s1Sum * s2Sum = " + s1Sum + " * " + s2Sum + " = " + sumProd);

    String sumZ = Karatsuba.add(z0, z1);
    System.out.println("sumZ = z0 + z1 = " + z0 + " + " + z1 + " = " + sumZ);

    String z2 = Karatsuba.subtract(sumProd, sumZ);
    System.out.println("z2 = sumProd - sumZ = " + sumProd + " - " + sumZ + " = " + z2);
    
    String result = Karatsuba.add(Karatsuba.add(Karatsuba.shift(nHalf * 2, z0), Karatsuba.shift(nHalf, z2)), z1);
    System.out.println("n = " + n + " nHalf = " + nHalf);
    System.out.println("result = s1 * s2 = z0 * 10^n + z2 * 10^(n / 2) + z1 = " + s1 + " * " + s2 + " = " + result);
    System.out.println();

    return result;
  }
  
  /**
   * Multiply s by 10^n.
   */
  public static String shift(int n, String s) {
    StringBuilder sb = new StringBuilder(s);
    for (int i = 0; i < n; i++) {
      sb.append("0");
    }
    System.out.println("Shift s by n = " + s + " shift by " + n + " = " + sb.toString());
    return sb.toString();
  }


  /**
   * Subtract two large integers s1 - s2.
   */
  public static String subtract(String s1, String s2) {
    StringBuilder sb = new StringBuilder();
    int borrow = 0;
    int n = Math.min(s1.length(), s2.length());
    s1 = new StringBuilder(s1).reverse().toString();
    s2 = new StringBuilder(s2).reverse().toString();

    for (int i = 0; i < n; i++) {
      int a = Character.getNumericValue(s1.charAt(i));
      int b = Character.getNumericValue(s2.charAt(i));
      if (borrow > 0) {
        a -= 1;
      }

      if (a < b) {
        borrow = 1;
        sb.append(String.valueOf(10 + a - b));
      } else {
        borrow = 0;
        sb.append(String.valueOf(a - b));
      }
    }
    
    String longer = s1;
    if (s2.length() > s1.length()) {
      longer = s2;
    }
    
    for (int i = n; i < longer.length(); i++) {
      int a = Character.getNumericValue(longer.charAt(i));
      if (borrow > 0) {
        a -= 1;
      }

      if (a < 0) {
        borrow = 1;
        sb.append(String.valueOf(10 + a));
      } else {
        borrow = 0;
        sb.append(String.valueOf(a));
      }
    }

    if (borrow > 0) {
      sb.append("-");
    }

    return sb.reverse().toString();
  }


  /**
   * Add two large integers s1 + s2.
   */
  public static String add(String s1, String s2) {
    StringBuilder sb = new StringBuilder();
    int carry = 0;
    int n = Math.min(s1.length(), s2.length());

    s1 = new StringBuilder(s1).reverse().toString();
    s2 = new StringBuilder(s2).reverse().toString();

    for (int i = 0; i < n; i++) {
      int a = Character.getNumericValue(s1.charAt(i));
      int b = Character.getNumericValue(s2.charAt(i));
      int c = a + b + carry;
      sb.append(String.valueOf(c % 10));
      carry = (c - (c % 10)) / 10;
    }
    
    String longer = s1;
    if (s2.length() > s1.length()) {
      longer = s2;
    }
    
    for (int i = n; i < longer.length(); i++) {
      int a = Character.getNumericValue(longer.charAt(i));
      int c = a + carry;
      sb.append(String.valueOf(c % 10));
      carry = (c - (c % 10)) / 10;
    }

    if (carry > 0) {
      sb.append(String.valueOf(carry));
    }
    
    return sb.reverse().toString();
  }
  
  /**
   * Get the terms [x0, x1] of the large integer s such that s = x0*(10^m) + x1 
   * where m = length(s) / 2.
   */
  public static String[] getTerms(String s) {
    String[] result = new String[2];
    int n = s.length();
    result[0] = s;
    result[1] = "0";
    if (n > 1) {
      result[0] = s.substring(0, n / 2 + (n % 2));
      result[1] = s.substring(n / 2 + (n % 2), n);
    }
    return result;
  }
}
