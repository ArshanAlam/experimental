import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;

class QuickSelect {
  private static ThreadLocalRandom random = ThreadLocalRandom.current();

  public static void main(String[] args) throws IOException {
    if (args.length != 1) {
      System.exit(1);
    }
    
    String fileName = args[0];
    int[] nums = Files.readAllLines(Paths.get(fileName)).stream().mapToInt(x -> Integer.parseInt(x)).toArray();
    System.out.println(new QuickSelect().select(nums, 5));
  }

  /**
   * Select the kth smallest element in the given array in-place using randomized quick select.
   * @param nums - The array of numbers that we want to select from
   * @param k - The index of the element that we want to select
   * @return int - The selected element
   */
  private int select(int[] nums, int k) {
    return select(nums, k, 0, nums.length - 1);
  }
  
  /**
   * Select the kth smallest elements in the given array in-place between [left, right] inclusive using randomized quickselect.
   * @param nums - The array of numbers that we want to select from
   * @param k - The index of the element that we want to select
   * @param left - The start index where left is less than the right.
   * @param right - The end index where left is less than the right
   * @return int - The selected element
   */
  private int select(int[] nums, int k, int left, int right) {
    if (left >= right) {
      return nums[Math.min(left, nums.length - 1)];
    }

    int pivot = getPivot(left, right);
    int partitionIndex = partition(nums, pivot, left, right);
    if (partitionIndex == k) {
      return nums[k];
    } else if (partitionIndex < k) {
      return select(nums, k, partitionIndex + 1, right);
    } else {
      return select(nums, k, left, partitionIndex - 1);
    }
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
