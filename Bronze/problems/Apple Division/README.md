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

Since the maximum number of apples is very small (`n <= 20`), this is a perfect candidate for a brute-force/complete search approach. We can generate all possible ways to divide the apples into two sets.

1. Recursive State: Create a recursive function that tracks the `index` of the current apple being evaluated, the `sum1` (total weight of Group 1 so far), and `sum2` (total weight of Group 2 so far).
2. Branching: For each apple at `index`, make two recursive calls:

- - Put the apple in Group 1 (`sum1 + weights[index]`).
- - Put the apple in Group 2 (`sum2 + weights[index]`).

3. Base Case: When `index == n` (all apples have been distributed), calculate and return the absolute difference `abs(sum1 - sum2)`.
4. Optimization: At each step, return the `min()` of the two recursive branches. The function will naturally bubble up the smallest absolute difference found across all combinations.

## Notes

- Nothing.
