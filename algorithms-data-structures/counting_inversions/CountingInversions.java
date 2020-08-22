import java.util.stream.Stream;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.util.Arrays;

class CountingInversions {
  public static void main(String[] args) throws IOException {
    if (args.length != 1) {
      System.exit(1);
    }
    
    String inputFileName = args[0];
    int[] nums;
    try (Stream<String> stream = Files.lines(Paths.get(inputFileName))) {
      nums = stream.map(Integer::parseInt).mapToInt(i -> i).toArray();
    }
    
    System.out.println("Number of inversions = " + countInversions(nums));
  }
  
  /**
   * Given the array of integers, count the number of inversions in this array.
   * https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
   * @param nums - The list of numbers
   * @return int - The number of inversions
   */
  private static long countInversions(int[] nums) {
    return countInversions(nums, 0, nums.length - 1);
  }

  /**
   * Given the array of integers, count the number of inversions in this array between the indices [left, right].
   * https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
   * @param nums - The list of numbers
   * @param left - The start index
   * @param right - The end index
   * @return int - The number of inversions
   */
  private static long countInversions(int[] nums, int left, int right) {
    if (left >= right) {
      return 0;
    }
    
    // Get the middle index between [left, right] using bit shift to prevent overflow
    int mid = left + ((right - left) >> 1);
    
    long leftInversions = countInversions(nums, left, mid);
    long rightInversions = countInversions(nums, mid + 1, right);

    // merge the left and right in sorted order while counting the inversions
    int[] sorted = new int[right - left + 1];
    
    long numInversions = leftInversions + rightInversions;
    int sortedIndex = 0;
    int leftIndex = left;
    int rightIndex = mid + 1;

    while (leftIndex <= mid && rightIndex <= right) {
      if (nums[leftIndex] < nums[rightIndex]) {
        sorted[sortedIndex] = nums[leftIndex++];
      } else {
        sorted[sortedIndex] = nums[rightIndex++];
        numInversions += (mid - leftIndex + 1);
      }
      sortedIndex += 1;
    }
    
    // copy the rest of elements into the sorted array
    while (leftIndex <= mid) sorted[sortedIndex++] = nums[leftIndex++];
    while (rightIndex <= right) sorted[sortedIndex++] = nums[rightIndex++];

    // sort the original nums array
    for (int i = 0; i < sorted.length; i++) {
      nums[left + i] = sorted[i];
    }

    return numInversions;
  }
}
