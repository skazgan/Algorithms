# Longest Palindromic Substring

A classic string problem, implemented in **Python**, **Java**, and **C++**.

## Problem

**Difficulty:** Medium (LeetCode #5)

Given a string `s`, return the longest substring of `s` that reads the same forwards and backwards (a palindrome).

### Example

```
Input:  s = "babad"
Output: "bab"     (note: "aba" is also a valid answer)
```

```
Input:  s = "cbbd"
Output: "bb"
```

## Approach: expand around center

Every palindrome is symmetric around a center, and that center is either:

- a single character (odd-length palindrome, e.g. `"aba"` is centered on the middle `a`)
- a gap between two characters (even-length palindrome, e.g. `"abba"` is centered between the two middle `b`s)

A string of length `n` has exactly `2n - 1` possible centers — `n` character-centers plus `n - 1` gap-centers between them.

For each center, expand outward in both directions at once, one step at a time, for as long as the characters on either side keep matching. The moment they stop matching, that center's palindrome is as wide as it will ever get. Do this for every center, and keep the widest one you ever find.

```python
def expand(s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return left + 1, right - 1   # step back to the last valid match
```

Run `expand(s, i, i)` (odd center) and `expand(s, i, i + 1)` (even center) for every index `i`, and keep whichever result is widest.

### Worked example

Tracing every center on `s = "babad"` (`start, end = 0, 0` initially — the trivial one-character palindrome `"b"`):

| `i` | odd center `expand(i, i)` | even center `expand(i, i+1)` | best so far |
|---|---|---|---|
| 0 | `(0, 0)` → `"b"`, width 0 — no update | mismatch (`'b'` vs `'a'`) — ignored | `(0, 0)` |
| 1 | `(0, 2)` → `"bab"`, width 2 — **updates best** | mismatch (`'a'` vs `'b'`) — ignored | `(0, 2)` |
| 2 | `(1, 3)` → `"aba"`, width 2 — tie, no update | mismatch (`'b'` vs `'a'`) — ignored | `(0, 2)` |
| 3 | `(3, 3)` → `"a"`, width 0 — no update | mismatch (`'a'` vs `'d'`) — ignored | `(0, 2)` |
| 4 | `(4, 4)` → `"d"`, width 0 — no update | out of bounds — ignored | `(0, 2)` |

Final `start, end = (0, 2)` → `s[0:3]` = **`"bab"`**. Note `"aba"` (found at `i=2`) is an equally valid answer per the problem, but the `>` comparison only replaces the best-so-far on a *strictly* wider match, so the first one found — `"bab"` — wins the tie.

**Complexity:** `O(n²)` time — `n` centers, each expansion costing up to `O(n)` — and `O(1)` extra space, since it only ever tracks a handful of index pointers.

## Real-world analogy

Picture the string printed on a long strip of paper, and imagine trying every possible place you could fold that strip in half — once at each letter, and once in each gap between two letters.

At any given fold line, hold the strip up to the light: the letters on the left should land exactly on top of their mirror image on the right. Starting right at the fold and working outward, check each pair of overlapping letters. The instant a pair doesn't match, the fold has gone as far as it can — that's the width of the palindrome for this particular fold line.

Try folding at every single position along the strip, and keep track of whichever fold let you match the most letters before the pattern broke. That best fold is your longest palindrome — and note it can be anywhere along the strip, not necessarily dead-center, which is exactly why you have to try every position rather than only checking the middle.

## Files

| Language | File |
|----------|------|
| Python | [`python/longest_palindromic_substring.py`](python/longest_palindromic_substring.py) |
| Java   | [`java/LongestPalindromicSubstring.java`](java/LongestPalindromicSubstring.java) |
| C++    | [`cpp/longest_palindromic_substring.cpp`](cpp/longest_palindromic_substring.cpp) / [`cpp/longest_palindromic_substring.hpp`](cpp/longest_palindromic_substring.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/longest_palindromic_substring.py

# Java
javac java/LongestPalindromicSubstring.java -d java/out
java -cp java/out LongestPalindromicSubstring

# C++
g++ -std=c++17 cpp/longest_palindromic_substring.cpp -o cpp/longest_palindromic_substring
./cpp/longest_palindromic_substring
```

Each entry point runs `"babad"` and `"cbbd"`, printing `bab` and `bb`.

## Tests

Seven cases per language: an odd-length palindrome with a tie to break (`"babad"`), an even-length palindrome (`"cbbd"`), a single character, a string that's a palindrome in its entirety (`"racecar"`), a string with no repeated characters (answer is any single character), an empty string, and a string of all-identical characters.

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/longest_palindromic_substring.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_longest_palindromic_substring.cpp -o tests/test_longest_palindromic_substring
./tests/test_longest_palindromic_substring

# Java (no JUnit dependency; compiles the solution and test together)
javac java/LongestPalindromicSubstring.java tests/LongestPalindromicSubstringTest.java -d tests/out
java -cp tests/out LongestPalindromicSubstringTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
