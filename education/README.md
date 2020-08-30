# Education
This is a set of useful informations that I've learned and I've created this README to help with [recall](https://en.wikipedia.org/wiki/Recall_(memory)).

---

## Learning How To Learn

### It's quite common to get stuck on a problem--often because you have initial ideas about what the solution should be that block your ability to see the real solution. What is a good next best step to take when you've already spent time reanalyzing the problem by focusing intently, and you find that you are simply stuck?
<details>

* Take a little break. You can focus on something different, or even just relax and not focus on anything at all, perhaps going out for a walk. 
* Taking a little break is a good idea. Taking your attention off of what you want to solve helps allow other neural modes to have access to the material. You won't be conscious of your brain continuing to work in the background on the problem--but it is!
</details>

### After you have become an expert at using the "Pomodoro technique," you should:
<details>

* Continue to use the "Pomodoro technique" when you have difficulty learning a subject or getting yourself motivated to get started on the task, but make sure to also take breaks in between your Pomodoro sessions. 
* The Pomodoro technique is a time-management, time-boxing technique in which the focused-learning mode is utilized on some task or logically related tasks for 25 minutes continuously, with zero interruptions. It helps you focus on learning, and when you break/reward yourself, it helps you internalize what you went through during the Pomodoro session.
</details>


### In the ___ mode, the brain makes random connections in a relaxed fashion.
<details>
diffuse


![Diffuse Mode Octopus](images/learning-how-to-learn/diffuse-mode-octopus.png)
![Diffuse Mode Pinball Machine](images/learning-how-to-learn/diffuse-mode.jpg)
</details>


### Procrastination
<details>

* When you don't want to work on something, a sense of neural discomfort arises. However, researchers have found that not long after you might start working on something that you find unpleasant, that neural discomfort disappears. So an important aspect of tackling procrastination is to just get yourself through that initial period of discomfort. The Pomodoro technique helps you do that.
* Everybody has some issues with procrastination.
* Even if you keep right on task by prioritizing and working on the most important things, you are still procrastinating on whatever you are not working on. But if you are properly prioritizing your work--and also allowing for a little relaxation time in your life!--your problems with procrastination can be minimized.
</details>


### The focused mode is:
<details>

* Ideas, concepts, and problem-solving techniques that are at least somewhat familiar to you--your previous knowledge lays a sort of underlying neural pathway that you tend to follow.
* A pinball machine that has bumpers which are very tightly grouped together, so the pinball (the thought) can't go very far without bumping into a bumper.


![Focused Mode Pinball Machine](images/learning-how-to-learn/focus-mode.jpg)
</details>


### Sleep
<details>

* Too little sleep over too long a time is associated with all sorts of nasty conditions, including headaches, depression, heart disease, diabetes, and just plain dying earlier.
* During sleep, your brain erases the less important parts of memories and simultaneously strengthens areas that you need or want to remember.
</details>


### Memory
<details>

* Repetition is needed so your metabolic vampires--natural dissipating processes--don't suck the memories away.
* Research has shown that if you try to glue things into your memory by repeating something twenty times in one evening, for example, it won't stick nearly as well as if you practice it the same number of times over several days.
* Long term memory is like a storage warehouse.
</details>


### Practice
<details>

* Practice helps make memories more permanent.
* Neurons become linked together through repeated use. The more abstract something is, the more important it is to PRACTICE in order to bring these ideas into reality for you.
</details>


### Activities that would be more apt to arouse the diffuse (rather than focused) mode:
<details>

* Go for a walk.
* Getting some form of exercise while not concentrating on anything in particular.
* Take a shower.
</details>


### Exercise
<details>

* Helps improve your ability to learn and remember.
* Research is showing that exercise seems to be just as important as an enriched environment in allowing the brain to grow new neurons and remain healthy.
</details>


### Math and science might sometimes be more challenging because
<details>

* Math is not so directly related to emotions that we can feel.
* Math and science often involves more abstract, rather than concrete, ideas.
* In math and science, it's sometimes difficult to find analogous real-world concepts to point to--the abstract nature of a `+` symbol, for example, isn't like the word cow, which involves an animal you can directly point to.
</details>


### The ___ mode involves a direct approach to solving problems using rational, sequential, analytical approaches. It is associated with the concentrating abilities of the brain's prefrontal cortex, located right behind your forehead.
<details>
Focused


![Focused Mode Prefrontal Cortex](images/learning-how-to-learn/focused-mode-prefrontal-cortex.png)
</details>


### According to Dr. Sejnowski’s, what happens in your brain during sleep that helps you remember new experiences?
<details>Your brain forms new synapses.</details>


### True statements about the human brain:
<details>

* Sleeping helps the brain form new synapses (neural connections).
* Brain connectivity is dynamic (that is, it changes), not static.
</details>


## Algorithms

### Definition of Big O Notation
<details>

Let `T(n)` be a function on `n = 1, 2, 3,...`. Then `T(n) = O(f(n))` if and only if there exist constant `c, n_0 > 0` such that `T(n) <= cf(n)`. For all `n >= n_0`.
</details>


### Definition of Big ![Big Omega Symbol][big_omega] Notation
<details>

Let `T(n)` be a function on `n = 1, 2, 3,...`. Then ![tn_omega_fn][tn_omega_fn] if and only if there exist constant `c, n_0 > 0` such that `T(n) >= cf(n)`. For all `n >= n_0`.

[tn_omega_fn]: https://render.githubusercontent.com/render/math?math=T(n)%20=%20\Omega(f(n))
[big_omega]: https://render.githubusercontent.com/render/math?math=\Omega
</details>


### Definition of Big ![Big Theta Symbol][big_theta] Notation
<details>

Let `T(n)` be a function on `n = 1, 2, 3,...`. Then ![tn_theta_fn][tn_theta_fn] if and only if ![tn_omega_fn] and `T(n) = O(f(n))`.

[tn_theta_fn]: https://render.githubusercontent.com/render/math?math=T(n)%20=%20\Theta(f(n))
[big_theta]: https://render.githubusercontent.com/render/math?math=\Theta
</details>


### Karatsuba Multiplication
<details>

Karatsuba Mutiplication is a recursive algorithm for multiplying two `n` digit numbers.

* Time Complexity: `O(n^(log_2(3)))` which is approximately `O(n^1.59)`
* Space Complexity: `O(n)`


```
// x = 10^(n/2) * a + b
// y = 10^(n/2) * c + d
// x * y = 10^n * a * c  + 10^(n/2) * (a * d + b * c) + (b * d)
// 1. Recursively compute ac
// 2. Recursively compute bd
// 3. Recursively compute (a + b)(c + d) = ac + bd + ad + bc
// Gauss' Trick: (3) - (1) - (2) = ad + bc
// Upshot: Only need three recursive multiplications (and some additions)
def karatsuba(x, y) {
    if (x < 10 && y < 10) {
        return x * y
    }

    // calculate the size of the input (the number of digits)
    n = min(size_base10(x), size_base10(y))
    nHalf = n / 2

    // split the digits in the middle
    xHigh, xLow = split_at(x, nHalf)
    yHigh, yLow = split_at(y, nHalf)

    // 3 calls made to numbers that are approximately half the size
    z0 = karatsuba(xLow, yLow)
    z1 = karatsuba((xLow + xHigh), (yLow + yHigh))
    z2 = karatsuba(xHigh, yHigh)

    return (z2 * 10^(nHalf * 2)) + ((z1 - z2 - z0) * 10^nHalf) + z0
}
```

*Here is the [implementation](../algorithms-data-structures/karatsuba-multiplication/Karatsuba.java)*
</details>


### Merge Sort
<details>

[Merge sort](https://en.wikipedia.org/wiki/Merge_sort) is a [divide and conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) that sorts an array of `n` numbers.

* Time Complexity: `O(nlogn)`
* Space Complexity: `O(n)`


```
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
```

*Here is the [implementation](../algorithms-data-structures/merge-sort/MergeSort.java)*
</details>

### Counting Inversions
<details>

Counting inversions is a problem of counting the number of pairs of indices `(i, j)` in an array `nums` where `i < j` and `nums[i] > nums[j]`.

* Input: Array `nums` containing the numbers `1, 2, 3,..., n` in some arbitrary order
* Output: Number of inversions = number of pairs `(i, j)` of array indices with `i < j` and `nums[i] > nums[j]`.

Turns out we could use a [divide and conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) algorithm similar to merge sort to help us solve this problem.

![Counting Inverions Using Merge Sort](images/algorithms/counting-inversions.png)

* Time Complexity: `O(nlogn)`
* Space Complexity: `O(n)`

```
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
```

*Here is the [implementation](../algorithms-data-structures/counting-inversions/CountingInversions.java)*
</details>