# Hash Tables

## Definition
Hash Table is a data structure that stores key-value pairs and supports fast operations like insert, search, delete

## Core Components
- **Hash Function**: `h(k)` - Maps keys to array indices
- **Table Size**: Should be prime number for better distribution
- **Load Factor**: `α = n/m` where n = # of elements, m = table size

## Time Complexity
| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insert    | O(1)         | O(n)       |
| Search    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |

## Collisions:
### Separate Chaining: 
- Each bucket stores a list (linked list) of items
- Multiple keys can hash to the same index
- **Pros**:
- Simple implementation
- Load factor α can exceed 1
- Deletion is easy
- **Cons**:
- Extra memory for pointers
- Cache performance suffers
- **Best when**: α ≈ 1 or table size unknown

**Example:**
```
Table[0] → NULL
Table[1] → [23] → [34] → [45] → NULL
Table[2] → [13] → NULL
Table[3] → NULL
```


### Open Addressing:
- All items live in the array.
- If a bucket is taken, you probe for another slot
- Requires `α < 1` (table never completely full)

**Example (Linear Probing):**
```
Insert 23: [_, 23, _, _, ...]  (slot 1)
Insert 34: [_, 23, 34, _, ...]  (collision → slot 2)
Delete 23: [_, DEL, 34, _, ...]  (preserve chain)
```


## Comparison

| Aspect | Chaining | Open Addressing |
|--------|----------|-----------------|
| Memory | Extra pointers | Compact (no pointers) |
| Load Factor | Can exceed 1 | Must be < 1 |
| Cache | Poor (pointer chasing) | Good (array locality) |
| Deletion | Easy | Needs DELETED marker |
| Best for | Unknown size, high α | Known size, low α |
