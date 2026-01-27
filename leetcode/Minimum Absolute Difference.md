# Minimum Absolute Difference - Solution Analysis

## Problem
Given an array of distinct integers, find all pairs of elements with the minimum absolute difference.

## Initial Solution - Two-Pass Approach
My first solution was a simple difference computation using the .sort() method which gives a time complexity of O(n log n).

```py
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        min_dif = float("inf")
        res = []
        temp = []

        # [4, 2, 1, 3] -> loop through each element and find min dif O(n)
        # eg. 4 - 2 -> min_dif = 2, 4 - 1 -> min_dif = 3, 4 - 3, min_dif = 1
        # O(n) for finding the min_dif, then O(n) to find the pairs.

        arr.sort()

        for i in range(len(arr) - 1):
            min_dif = min(abs(arr[i + 1] - arr[i]), min_dif)

        for i in range(len(arr) - 1):
            if abs(arr[i + 1] - arr[i]) == min_dif:
                    temp.append(arr[i])
                    temp.append(arr[i + 1])
                    res.append(temp)
                    temp = []
            

        return res
```

## Optimization - Single-Pass Approach
I realized we can find the minimum difference and collect pairs in one pass:

```py
        for i in range(len(arr) - 1):
            diff = arr[i + 1] - arr[i]

            if diff < min_diff: # found a smaller difference
                min_diff = diff
                res = [[arr[i], arr[i + 1]]] # reset the result list 
            elif diff == min_diff:
                res.append([arr[i], arr[i + 1]])
```

### Trial and Error
The time complexity of my previous solution was O(n logn) because of the .sort().  I had this idea to sort the array and then do min_dif = arr[1] - arr[0] thinking that would be automatically the smallest gap, but after dry running I saw that it's not the same in every case. Like yeah, it works for 4 2 3 1 (sorted: 1 2 3 4) or 1 3 6 10.. but if we have 1 5 6 7 (example) it would not work.

## Attempting Counting Sort - O(n) Approach
Then I started thinking about what makes my solution slow. The .sort takes O(n logn) time and I learned in my DSA class that Counting and Bucket sort have O(n) time complexity (technically O(n + k) for both, depening on the numbers). So I implemented the counting sort and the code looked like this:

```py
class Solution:
    def count_sort(self, arr):
        max_elem = max(arr)
        count = [0] * (max_elem + 1)

        for a in arr:
            count[a] += 1

        for i in range(1, max_elem + 1):
            count[i] += count[i - 1]

        ans = [0] * len(arr)

        for i in range(len(arr) - 1, -1, -1):
            v = arr[i]
            ans[count[v] - 1] = v
            count[v] -= 1

        return ans


    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # 1 2 3 4 -> 1
        # 1 3 6 10 15 -> 2

        arr = self.count_sort(arr)
        min_dif = float("inf")
        temp = []
        res = []

        for i in range(len(arr) - 1):
            min_dif = min(min_dif, abs(arr[i + 1] - arr[i]))
        
        for i in range(len(arr) - 1):
            if abs(arr[i + 1] - arr[i]) == min_dif:
                temp.append(arr[i])
                temp.append(arr[i + 1])
                res.append(temp)
                temp = []

        return res
```

### Problem: Negative Numbers
The problem I encountered into was that counting sort doesn't handle negatives, since it uses values as array indices and we all know that indices can't be negative. 

## Solutions for Negative Numbers
To solve this, I thought about 2 options:

### 1. HashMap-Based Counting Sort
Using a hashmap to store key-value pairs. Here we can safely store negative numbers as the 'key' element. Great for sparse arrays or huge range.

```py
def count_sort(self, arr):
        max_elem = max(arr)
        count = {}

        for a in arr:
            if a in count:
                count[a] += 1
            else:
                count[a] = 1

        keys = sorted(count.keys())
        total = 0
        for k in keys:
            total += count[k]
            count[k] = total

        ans = [0] * len(arr)

        for i in range(len(arr) - 1, -1, -1):
            v = arr[i]
            ans[count[v] - 1] = v
            count[v] -= 1

        return ans
```


### 2. Offset-Based Counting Sort
Subtracting the min value from every number to get a positive array, do the frequency and then undo the shift. This is actually closer to the counting sort style and can be even faster than using a hashmap, but it's only efficient for small range of min-max values.

```py
def count_sort(self, arr):
        max_elem = max(arr)
        min_elem = min(arr)
        count = [0] * (max_elem - min_elem + 1)

        shifted = [x - min_elem for x in arr]

        for a in shifted:
            count[a] += 1

        for i in range(1, len(count)):
            count[i] += count[i - 1]

        ans = [0] * len(shifted)

        for i in range(len(arr) - 1, -1, -1):
            v = arr[i]
            shifted_v = v - min_elem
            ans[count[shifted_v] - 1] = v
            count[shifted_v] -= 1

        return ans
```

## Conclusion
In practice, I use Python's built-in .sort() method because it is highly optimized (Timsort implementation in C). Counting sort is only beneficial when the range of values is small (eg. [0, 1000]) or when there are many duplicate values. For this problem, the .sort() approach with a single-pass solution is the most practical choice.