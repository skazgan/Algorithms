# Reverse Integer

A numeric-overflow problem, implemented in **Python**, **Java**, and **C++**.

## Problem

**Difficulty:** Medium (LeetCode #7)

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, return `0` instead.

### Example

```
Input:  x = 123
Output: 321
```

```
Input:  x = -123
Output: -321
```

```
Input:  x = 120
Output: 21
```

```
Input:  x = 1534236469
Output: 0     (reversed digits would be 9646324351, which overflows)
```

## Approach: digit-by-digit extraction, overflow checked before it happens

Strip the sign, then repeatedly peel the last digit off `x` (`x % 10`) and build up the reversed number one digit at a time — the same way you'd read a number's digits starting from the ones place and writing them down in that order:

```python
result = result * 10 + digit
```

The part that actually matters is *when* you check for overflow. Before every multiply, check whether it would push `result` past the signed 32-bit limit:

```python
if result > (INT_MAX - digit) // 10:
    return 0
```

This is algebraically the same question as "will `result * 10 + digit` exceed `INT_MAX`?", just rearranged so the check happens *before* the oversized value would ever be produced. That distinction only matters in a language with a genuinely fixed-width integer type (Java, C++) — by the time you'd computed the too-large value and checked it *afterward*, it would already have silently wrapped around to something else. Python's arbitrary-precision integers don't have that failure mode, but the same before-the-fact check is used here anyway, both because it's the correct habit and because it's what makes this solution translate directly into Java and C++ without changes in logic.

```python
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1

        sign = -1 if x < 0 else 1
        x = abs(x)

        result = 0
        while x != 0:
            digit = x % 10
            x //= 10

            if result > (INT_MAX - digit) // 10:
                return 0

            result = result * 10 + digit

        result *= sign
        return result if INT_MIN <= result <= INT_MAX else 0
```

### Worked example

Tracing the code above on `x = 120`:

| step | `x` before | `digit` | `x` after | overflow check | `result` after |
|---|---|---|---|---|---|
| 1 | 120 | 0 | 12 | `0 > (2147483647-0)//10`? no | 0 |
| 2 | 12 | 2 | 1 | `0 > (2147483647-2)//10`? no | 2 |
| 3 | 1 | 1 | 0 | `2 > (2147483647-1)//10`? no | 21 |

`x` is now `0`, loop ends. `result *= sign (1)` → `21`, within bounds → **`21`**. Matches `120` reversed (`"021"` → `21`).

And on the overflow case, `x = 1534236469`: partway through extracting its ten digits, `result` grows large enough that `result > (INT_MAX - digit) // 10` becomes true — the function returns `0` immediately, never actually computing the full (invalid) `9646324351`.

**Edge case:** `x = -2^31` (`-2147483648`, the smallest possible 32-bit int) — its magnitude reversed is `8463847412`, which overflows just like the positive case above. Casting to a wider type before taking the absolute value (`long` in Java, `long long` in C++) also matters here for a separate reason: naively negating `-2147483648` in a fixed-width 32-bit type is itself undefined/incorrect, since `2147483648` has no positive 32-bit representation.

**Complexity:** `O(log₁₀ x)` time — one iteration per digit of `x` — and `O(1)` space.

## Real-world analogy

Picture `x`'s digits as a stack of numbered plates in a cafeteria dispenser, with the ones-place digit sitting on top. You're moving plates one at a time onto a brand-new stack on a shelf that's only rated to hold so much weight — that rating is the signed 32-bit limit.

Before setting each plate down, you check the shelf's weight rating first. If adding this next plate would exceed what the shelf can bear, you stop right there and clear the new stack entirely, empty-handed — you don't leave a half-built, overloaded stack sitting on a shelf that can't actually hold it. Otherwise, you place the plate and move on to the next one. Once every plate from the original pile has been moved over, read the new stack top to bottom — that's your reversed number.

## Files

| Language | File |
|----------|------|
| Python | [`python/reverse_integer.py`](python/reverse_integer.py) |
| Java   | [`java/ReverseInteger.java`](java/ReverseInteger.java) |
| C++    | [`cpp/reverse_integer.cpp`](cpp/reverse_integer.cpp) / [`cpp/reverse_integer.hpp`](cpp/reverse_integer.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/reverse_integer.py

# Java
javac java/ReverseInteger.java -d java/out
java -cp java/out ReverseInteger

# C++
g++ -std=c++17 cpp/reverse_integer.cpp -o cpp/reverse_integer
./cpp/reverse_integer
```

Each entry point runs `123`, `-123`, `120`, and `1534236469`, printing `321`, `-321`, `21`, and `0`.

## Tests

Seven cases per language: a positive number, a negative number, a number with a trailing zero, zero itself, a positive value whose reversal overflows (the classic example), `INT_MIN` (whose reversal also overflows, plus exercises the abs-of-minimum-value pitfall), and a large value near the boundary that does *not* overflow (checking the bounds check doesn't false-positive).

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/reverse_integer.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_reverse_integer.cpp -o tests/test_reverse_integer
./tests/test_reverse_integer

# Java (no JUnit dependency; compiles the solution and test together)
javac java/ReverseInteger.java tests/ReverseIntegerTest.java -d tests/out
java -cp tests/out ReverseIntegerTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
