import java.util.stream.Stream;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.util.Arrays;

class MergeSort {
  public static void main(String[] args) throws IOException {
    if (args.length != 1) {
      System.exit(1);
    }
    
    String inputFileName = args[0];
    int[] nums;
    try (Stream<String> stream = Files.lines(Paths.get(inputFileName))) {
      nums = stream.map(Integer::parseInt).mapToInt(i -> i).toArray();
    }
    
    // sort the array then print it
    mergeSort(nums);
    System.out.println("Sorted Array: " + Arrays.toString(nums));
  }
  
  /**
   * Given the array of integers, sort them in ascending order.
   * @param nums - The list of numbers
   */
  private static void mergeSort(int[] nums) {
    mergeSort(nums, 0, nums.length - 1);
  }

  /**
   * Given the array of integers, sort them in ascending order.
   * @param nums - The list of numbers
   * @param left - The start index
   * @param right - The end index
   */
  private static void mergeSort(int[] nums, int left, int right) {
    if (left >= right) {
      return;
    }
    
    // Get the middle index between [left, right] using bit shift to prevent overflow
    int mid = left + ((right - left) >> 1);
    
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // merge the left and right in sorted order
    int[] sorted = new int[right - left + 1];
    
    int sortedIndex = 0;
    int leftIndex = left;
    int rightIndex = mid + 1;

    while (leftIndex <= mid && rightIndex <= right) {
      if (nums[leftIndex] < nums[rightIndex]) {
        sorted[sortedIndex] = nums[leftIndex++];
      } else {
        sorted[sortedIndex] = nums[rightIndex++];
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
  }
}
