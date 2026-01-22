# Tries (Prefix Trees)
A Trie is a tree-based data structure used mainly for efficient storage and retrieval of words/sequences. Also known as a prefix tree/digital tree.

## Characteristics
- Each nodes represents a character/digit in a sequence
- Root node is empty
- Each path from root to a node represents a prefix
- Nodes maked as "end of word" indicate valid sequences
- Universe of k characters means each node has k children

### Visual Example (k=26 for lowercase letters)
```
Storing words: "cat", "car", "dog"

         root
        /    \
       c      d
       |      |
       a      o
      / \     |
     t*  r*   g*

* = isEndOfWord = true
```

## Operations

### Insertion
- Time complexity: O(m) - m is length of a word
- Space complexity: O(m+k) worst case
- Process:
  1. Start at root
  2. For each characters, follow/create child node
  3. Mark last node as end of word

### Search
- Time complexity: O(m)
- Space complexity: O(1)
- Process:
  1. Start at root
  2. Follow path corresponding to characters
  3. Return true only if path exists and ends at isEndOfWord flag

### Delete
- Time complexity: O(m)
- Space complexity: O(m) - recursion stack
- Process:
  1. Unmark isEndOfWord flag
  2. Recursively delete nodes that become unnecessary
  3. Keep nodes that are part of other words or have children

## Advantages
- Fast prefix operations
- No hash collisions unlike hash tables
- In-order traversal gives sorted words
- Space efficient for common prefixes

## Disadvantages
- Memory overhead because each nodes stores k pointers
- Wastes memory if many words have different prefixes
- More complex to implement than hash tables