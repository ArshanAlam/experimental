# Quickselect
This is an implementation of [Randomized Quickselect](https://en.wikipedia.org/wiki/Quickselect).

```
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
```


## Time Complexity
- Worst-Case `O(n^2)`
- Best-Case `O(n)`
- Average Case `O(n)`


## Space Complexity
The space complexity is `O(1)` because we select in-place.
