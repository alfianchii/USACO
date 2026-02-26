# [CSES Apple Division - Easy](https://cses.fi/problemset/task/1623)

## Problem Description

There are `n` apples with known weights. Your task is to divide the apples into two groups so that the absolute difference between the total weights of the two groups is minimal.

### Input

The first input line has an integer `n`: the number of apples.
The next line has `n` integers `P1, P2, ..., Pn` (1 <= Pi <= 10^9): the weight of each apple.

### Output

Print one integer: the minimum difference between the weights of the two groups.

### Example

**Input (`apple.in`):**

```bash
5
3 2 7 4 1
```

**Output (`apple.out`):**

```bash
1
```

**Explanation:**

Group 1 has weights 2, 3, and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8). The absolute difference is `abs(9 - 8) = 1`.

---

## Approach

Since the maximum number of apples is very small (`n <= 20`), this is a perfect candidate for a brute-force/complete search approach. We can generate all possible ways to divide the apples into two sets. There are two common ways to implement this idea: recursion and bitmasking.

### Recursive Complete Search

1. Recursive State: Create a recursive function that tracks the `index` of the current apple being evaluated, the `sum1` (total weight of Group 1 so far), and `sum2` (total weight of Group 2 so far).
2. Branching: For each apple at `index`, make two recursive calls:

- - Put the apple in Group 1 (`sum1 + weights[index]`).
- - Put the apple in Group 2 (`sum2 + weights[index]`).

3. Base Case: When `index == n` (all apples have been distributed), calculate and return the absolute difference `abs(sum1 - sum2)`.
4. Optimization: At each step, return the `min()` of the two recursive branches. The function will naturally bubble up the smallest absolute difference found across all combinations.

This approach explores all `2^n` possible divisions and works efficiently because `n` is small.

### Complete Search Using Bitmask

Instead of recursion, we can also represent each possible division using a bitmask.

1. Bitmask Representation

   Each integer `mask` from `0` to `2^n - 1` (we start from 0, not 1) represents one possible division:
   - The `i`-th bit of `mask` determines where apple `i` goes.
   - If the `i`-th bit is `1`, apple `i` is placed in Group 1.
   - If the `i`-th bit is `0`, apple `i` is placed in Group 2.

2. Iterating Over All Possibilities

   We loop through all values of `mask`. This guarantees that every possible division is considered exactly once.

3. Computing Group Sums

   For each `mask`, we iterate through all apples and add `weights[i]` to `sum1` if `(mask & (1 << i))` is non-zero. Otherwise, add `weights[i]` to `sum2`.

4. Tracking the Minimum Difference

   For each division, we do compute `abs(sum1 - sum2)` and keep track of the minimum value across all masks.

## Notes

- Nothing.
