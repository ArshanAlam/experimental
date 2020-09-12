import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;

class QuickSort {
  private static ThreadLocalRandom random = ThreadLocalRandom.current();

  public static void main(String[] args) throws IOException {
    if (args.length != 1) {
      System.exit(1);
    }
    
    String fileName = args[0];
    int[] nums = Files.readAllLines(Paths.get(fileName)).stream().mapToInt(x -> Integer.parseInt(x)).toArray();
    new QuickSort().quickSort(nums);
    System.out.println(Arrays.toString(nums));
  }

  /**
   * Sort the given array in-place using randomized quick sort.
   * @param nums - The array of numbers that we want to sort. 
   */
  private void quickSort(int[] nums) {
    quickSort(nums, 0, nums.length - 1);
  }
  
  /**
   * Sort the elements in the given array in-place between [left, right] inclusive using randomized quicksort.
   * @param left - The start index where left is less than the right.
   * @param right - The end index where left is less than the right
   */
  private void quickSort(int[] nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int pivot = getPivot(left, right);
    int partitionIndex = partition(nums, pivot, left, right);
    quickSort(nums, left, partitionIndex - 1);
    quickSort(nums, partitionIndex + 1, right);
  }

  
  /**
   * Partition the given array nums between [left, right] around the given pivot and return the index of the pivot element.
   * @param nums - The array we want to partition
   * @param pivot - The element we want to partition this array with respect to
   * @param left - The start of the range
   * @param right - The end of the range
   * @return int - The index of the pivot element.
   */
  private int partition(int[] nums, int pivot, int left, int right) {
    swap(nums, left, pivot);
    int swapIndex = left + 1;
    for (int j = left + 1; j <= right; j++) {
      if (nums[j] < nums[left]) {
        swap(nums, swapIndex, j);
        swapIndex += 1;
      }
    }
    swap(nums, swapIndex - 1, left);
    return swapIndex - 1;
  }
  
  /**
   * Swap the element at index x with the element at index y.
   * @param nums - The array in which we want to do a swap
   * @param x - The first index
   * @param y - The second index
   */
  private void swap(int[] nums, int x, int y) {
    if (x < 0 || x >= nums.length || y < 0 || y >= nums.length) {
      return;
    }

    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
  }
  
  /**
   * Pick a random pivot between left and right (inclusive).
   * @param left - The start index
   * @param right - The end index
   * @return int - The random pivot
   */
  private int getPivot(int left, int right) {
    return random.nextInt(left, right + 1);
  }
}
