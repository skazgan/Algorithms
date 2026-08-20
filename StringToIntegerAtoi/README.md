# String to Integer (atoi)

A string-parsing problem, implemented in **Python**, **Java**, and **C++**.

## Problem

**Difficulty:** Medium (LeetCode #8)

Implement the `myAtoi(s)` function, which converts a string to a 32-bit signed integer, similar to C/C++'s `atoi` function.

The algorithm:

1. Skip any leading whitespace.
2. Check for an optional `'+'` or `'-'` sign, and consume it if present.
3. Read in digits until the next non-digit character or the end of the string, ignoring everything after. If no digits were read, the result is `0`.
4. Clamp the result to the signed 32-bit range `[-2^31, 2^31 - 1]` if it would otherwise fall outside it.

### Example

```
Input:  s = "42"
Output: 42
```

```
Input:  s = "   -42"
Output: -42
```

```
Input:  s = "4193 with words"
Output: 4193
```

```
Input:  s = "words and 987"
Output: 0
```

## Approach: consume, then accumulate digit by digit

Strip leading whitespace, consume an optional sign character, then walk the remaining string one character at a time. The moment a non-digit character is seen, **stop** — everything after that point is ignored, no matter what it contains. Build the result as you go (`num = num * 10 + digit`), the same digit-by-digit accumulation used in [Reverse Integer](../ReverseInteger/README.md), rather than collecting the digit characters into a substring and converting the whole thing in one call at the end — LeetCode's judge for this specific problem disallows calling `int()` on a multi-character substring, since that would let a single built-in call do the actual parsing this exercise exists to test.

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX, INT_MIN = 2**31 - 1, -2**31

        if not s or not s.strip():
            return 0

        s = s.strip(" ")
        sign = 1

        if s[0] == "-":
            sign = -1
            s = s[1:]
        elif s[0] == "+":
            sign = 1
            s = s[1:]

        num = 0
        for char in s:
            if not char.isdigit():
                break
            num = num * 10 + int(char)

        num *= sign

        if num < INT_MIN:
            return INT_MIN
        elif num > INT_MAX:
            return INT_MAX
        else:
            return num
```

### Worked example

Tracing the code above on `s = "   -42"`:

| step | what happens | state |
|---|---|---|
| 1 | `not s or not s.strip()` — string isn't empty/all-whitespace | continue |
| 2 | `s = s.strip(" ")` — leading spaces removed | `s = "-42"` |
| 3 | `s[0] == "-"` — sign consumed | `sign = -1`, `s = "42"` |
| 4 | `'4'` is a digit → `num = 0*10 + 4` | `num = 4` |
| 5 | `'2'` is a digit → `num = 4*10 + 2` | `num = 42` |
| 6 | no characters left, loop ends | — |
| 7 | `num *= sign` | `num = -42` |
| 8 | within `[INT_MIN, INT_MAX]`, no clamping needed | return `-42` |

**Edge cases worth knowing about (each one broke an earlier draft of this solution along the way):**

- **No digits at all** (`"words and 987"`) — the very first non-whitespace character already isn't a digit or sign, so the loop breaks before collecting anything; the result defaults to `0`. Note this also means digits appearing *later* in the string (after non-digit characters) must never be picked up — only the leading run counts.
- **Empty or all-whitespace input** (`""`, `"   "`) — handled by an explicit guard at the top, before any indexing into the string happens.
- **Overflow in either direction** (`"-91283472332"`, `"2147483648"`) — clamps to `INT_MIN`/`INT_MAX` rather than returning the true (out-of-range) value.
- **Exactly `INT_MIN`** (`"-2147483648"`) — this is a *valid* boundary value, not an overflow, so it must be returned as-is rather than clamped away. Its magnitude (`2147483648`) is actually one greater than `INT_MAX` (`2147483647`), which is why the Java/C++ versions compare the *signed* accumulated value against the bounds rather than comparing the unsigned magnitude against a single limit — using magnitude alone would incorrectly clamp this exact case.

**Complexity:** `O(n)` time — one pass over the string — and `O(1)` space.

## Real-world analogy

Picture an old mechanical adding machine, the kind with a physical digit display, being fed a number one keystroke at a time by someone reading off a handwritten note.

The operator first skips past any blank space on the note before the writing starts. If the very next mark is a `+` or `-`, they note it down as the sign and move past it, without punching it into the machine. Then they read the note digit by digit, punching each one into the machine in order — the machine's display updates after every keystroke, shifting its current total left and adding the new digit, exactly like sliding old digits over to make room. The instant the operator's eye lands on something that isn't a digit — a letter, a space, anything — they stop reading entirely, mid-note, and whatever's been punched in so far is the final answer. If the note never had a number to begin with, nothing gets punched in, and the machine just shows `0`.

The machine's display can only physically show so many digits, though — it has a hard limit on how large (or how negative) a number it can display. If the number being punched in would run past that limit, the machine doesn't jam or show garbage: it just pins the display at the largest (or smallest) value it's capable of showing, and stays there.

## Files

| Language | File |
|----------|------|
| Python | [`python/string_to_integer_atoi.py`](python/string_to_integer_atoi.py) |
| Java   | [`java/StringToIntegerAtoi.java`](java/StringToIntegerAtoi.java) |
| C++    | [`cpp/string_to_integer_atoi.cpp`](cpp/string_to_integer_atoi.cpp) / [`cpp/string_to_integer_atoi.hpp`](cpp/string_to_integer_atoi.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/string_to_integer_atoi.py

# Java
javac java/StringToIntegerAtoi.java -d java/out
java -cp java/out StringToIntegerAtoi

# C++
g++ -std=c++17 cpp/string_to_integer_atoi.cpp -o cpp/string_to_integer_atoi
./cpp/string_to_integer_atoi
```

Each entry point runs `"42"`, `"   -42"`, `"4193 with words"`, and `"words and 987"`, printing `42`, `-42`, `4193`, and `0`.

## Tests

Ten cases per language — each one traces back to a bug found and fixed while building this solution: a basic positive number, leading whitespace combined with a sign, stopping at the first non-digit, no leading digits at all (returns `0`), an explicit `'+'` sign, overflow in both directions (clamped to `INT_MIN`/`INT_MAX`), the exact `INT_MIN` boundary (valid, not clamped), and both an empty string and a whitespace-only string.

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/string_to_integer_atoi.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_string_to_integer_atoi.cpp -o tests/test_string_to_integer_atoi
./tests/test_string_to_integer_atoi

# Java (no JUnit dependency; compiles the solution and test together)
javac java/StringToIntegerAtoi.java tests/StringToIntegerAtoiTest.java -d tests/out
java -cp tests/out StringToIntegerAtoiTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
