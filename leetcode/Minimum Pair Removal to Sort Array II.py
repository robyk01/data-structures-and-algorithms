# Goal: we're given an array, return the minimum number of operations that are required to sort the array in a non-decreasing order
# An operation is a merge of two adjacent elements that equal to the smallest sum of the array.
# Eg. [5, 2, 3, 1] -> Minimum sum is (3, 1) = 4 -> Merge 3 and 1 -> Array still not sorted
# [5, 2, 4] -> Minimum sum is (2, 4) = 6 -> Merge 2 and 4 -> Array still not sorted
# [5, 6] -> Array is sorted

# Approach: Priority Queue + Lazy Deletion
# We use a Priority Queue to efficiently find the min sum
# We use a Double Linked List to manage neighbours
# We use Lazy Deletion to handle data in the queue

from typing import List
import heapq

# Helper classes
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        class Node:
            def __init__(self, value, left):
                self.value = value
                self.left = left # original index
                self.prev = None
                self.next = None

        class PQItem:
            def __init__(self, first, second, cost):
                self.first = first
                self.second = second
                self.cost = cost # the sum of the pair
            
            def __lt__(self, other):
                # sort by cost (sum) , then by index (leftmost)
                if self.cost == other.cost:
                    return self.first.left < other.first.left
                return self.cost < other.cost
            
        pq = []
        head = Node(nums[0], 0)
        curr = head
        merged = [False] * len(nums) # tracks lazy deletions
        decrease_count = 0

        for i in range(1, len(nums)):
            node = Node(nums[i], i)
            curr.next = node
            node.prev = curr

            # add pair to heap
            heapq.heappush(pq, PQItem(node.prev, node, node.prev.value + node.value))

            # track monotonicity
            if node.prev.value > node.value:
                decrease_count += 1
            
            curr = node

        count = 0
        while decrease_count > 0:
            item = heapq.heappop(pq)
            first, second = item.first, item.second

            # lazy deletion check
            if merged[first.left] or merged[second.left]:
                continue

            merged[first.left] = True
            merged[second.left] = True

            count += 1 # count the operations

            new_val = first.value + second.value
            new_node = Node(new_val, first.left)

            # remove internal decreasing count if pair was decreasing
            if first.value > second.value:
                decrease_count -= 1

            prev_node = first.prev
            next_node = second.next

            # update logic for left neighbour
            if prev_node:
                if prev_node.value > first.value: decrease_count -= 1
                if prev_node.value > new_node.value: decrease_count += 1

            # update logic for right neighbour
            if next_node:
                if next_node.value < second.value: decrease_count -= 1
                if next_node.value < new_node.value: decrease_count += 1


            # we relink and then push pair
            new_node.prev = prev_node
            new_node.next = next_node

            if prev_node:
                prev_node.next = new_node
                heapq.heappush(pq, PQItem(prev_node, new_node, prev_node.value + new_node.value))

            if next_node:
                next_node.prev = new_node
                heapq.heappush(pq, PQItem(new_node, next_node, new_node.value + next_node.value))

        return count
    
# Time Complexity: O(n logn)
# Space Complexity: O(n)
    
