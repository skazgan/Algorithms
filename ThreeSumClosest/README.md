# 3Sum Closest

A sort-and-two-pointers problem, implemented in **Python**, **Java**, and **C++**.

## Problem

**Difficulty:** Medium (LeetCode #16)

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of those three integers. You may assume each input has exactly one solution.

### Example

```
Input:  nums = [-1, 2, 1, -4], target = 1
Output: 2     (-1 + 2 + 1 = 2, the closest possible sum to 1)
```

## Approach: sort, then two pointers per anchor

Sort the array first. Fix one element at index `i` as an "anchor," then use two pointers — `left` starting just after the anchor, `right` at the end of the array — to scan for the pair that, combined with the anchor, gets the sum as close to `target` as possible:

- if the current sum is too small, move `left` right (swap in a bigger number)
- if it's too large, move `right` left (swap in a smaller number)
- if it's an *exact* match, that's provably the best possible answer — no other triplet can beat a difference of `0`, so return immediately

Repeat with every index taking a turn as the anchor, tracking the closest sum found across all of them. Because the array is sorted, this explores every relevant pair for each anchor in a single sweep, rather than checking every possible triplet individually.

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            while left < right:
                current = nums[i] + nums[left] + nums[right]

                if current == target:
                    return current

                if abs(current - target) < abs(closest - target):
                    closest = current

                if current < target:
                    left += 1
                else:
                    right -= 1

        return closest
```

### Worked example

Tracing the code above on `nums = [1, 1, 1, 0]`, `target = 2` (sorted: `[0, 1, 1, 1]`) — the exact case that matters most here, since it's the one where the sum lands precisely on the target:

| `i` | `left`, `right` | `current` | comparison | action |
|---|---|---|---|---|
| 0 | 1, 3 | `0+1+1 = 2` | `current == target` | **return `2` immediately** |

That's the whole trace — the very first triplet checked happens to hit `target` exactly, and the function returns without examining anything else. This is also the scenario that mattered most while building this solution: a naive version of the pointer-move logic (`if current < target: ... elif current > target: ...`, with no `else`) never accounts for `current == target` at all, so neither pointer moves when the sum lands exactly on `target` — the `while left < right` loop then re-examines the identical state forever, hanging indefinitely. The early `return` here isn't just an optimization; it's what keeps the loop from ever reaching that stuck state, since it exits before the (missing) pointer-move step would even matter.

For a non-exact case, `nums = [-1, 2, 1, -4]`, `target = 1` (sorted: `[-4, -1, 1, 2]`):

| `i` | `left`, `right` | `current` | `abs(current-target)` vs best so far | `closest` after |
|---|---|---|---|---|
| 0 | 1, 3 | `-4-1+2 = -3` | `4` < `4` (initial `closest=-4-1+1=-4`, diff `5`)? updates | `-3` |
| 0 | 2, 3 | `-4+1+2 = -1` | `2 < 4`, updates | `-1` |
| 1 | 2, 3 | `-1+1+2 = 2` | `1 < 2`, updates | `2` |

`left` reaches `right` after that, and `i=2,3` can't form a valid window (`left < right` never holds). Final answer: **`2`**.

**Complexity:** `O(n²)` time — `O(n log n)` to sort, then `n` anchors each doing an `O(n)` two-pointer sweep — and `O(1)` extra space.

## Real-world analogy

Picture the numbers as a row of weights on a shelf, sorted lightest to heaviest, and you're trying to pick exactly three of them that balance a scale as closely as possible against a target weight.

Pick one weight to hold fixed. Then start by pairing it with the *lightest* and *heaviest* of the remaining weights. Put all three on the scale and read the result: if it's too light, swap out your current light weight for the next one up the shelf — you need more weight, so reach for something heavier from that end. If it's too heavy, swap out your heavy weight for the next one down — you need less, so reach for something lighter from that end. If the scale balances exactly, stop right there; you've found the best possible combination, and nothing else on the shelf could do better than a perfect balance.

Keep sliding those two choices toward each other — always correcting in whichever direction the scale is off — until they meet in the middle and there's nothing left to try with this fixed weight. Then give a different weight a turn being the fixed one, and repeat. Across every fixed weight you try, keep whichever three-weight combination ever got closest to balancing.

## Files

| Language | File |
|----------|------|
| Python | [`python/three_sum_closest.py`](python/three_sum_closest.py) |
| Java   | [`java/ThreeSumClosest.java`](java/ThreeSumClosest.java) |
| C++    | [`cpp/three_sum_closest.cpp`](cpp/three_sum_closest.cpp) / [`cpp/three_sum_closest.hpp`](cpp/three_sum_closest.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/three_sum_closest.py

# Java
javac java/ThreeSumClosest.java -d java/out
java -cp java/out ThreeSumClosest

# C++
g++ -std=c++17 cpp/three_sum_closest.cpp -o cpp/three_sum_closest
./cpp/three_sum_closest
```

Each entry point runs `[-1, 2, 1, -4]` with target `1` (prints `2`) and `[0, 0, 0]` with target `1` (prints `0`).

## Tests

Eight cases per language, most of them tracing directly back to a bug found while building this solution: the classic example, an exact match that must trigger an immediate return (the case that used to hang forever), all-identical elements, exactly three elements (no special-casing needed — `closest` is valid from initialization), an exact match involving negative numbers, a target far beyond anything reachable (closest just settles on the only achievable sum), duplicate values forming an exact zero-sum triplet, and a larger array with no exact match at all.

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/three_sum_closest.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_three_sum_closest.cpp -o tests/test_three_sum_closest
./tests/test_three_sum_closest

# Java (no JUnit dependency; compiles the solution and test together)
javac java/ThreeSumClosest.java tests/ThreeSumClosestTest.java -d tests/out
java -cp tests/out ThreeSumClosestTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
