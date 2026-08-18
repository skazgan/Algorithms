# ZigZag Conversion

A string-simulation problem, implemented in **Python**, **Java**, and **C++**.

## Problem

Given a string `s` and an integer `numRows`, write `s` in a zigzag pattern across `numRows` rows — straight down one column, then diagonally up to the next column, repeating — then read the result back out row by row and concatenate.

### Example

```
s = "PAYPALISHIRING", numRows = 3

P   A   H   N
A P L S I I G
Y   I   R

→ "PAHNAPLSIIGYIR"
```

```
s = "PAYPALISHIRING", numRows = 4

P     I    N
A   L S  I G
Y A   H R
P     I

→ "PINALSIGYAHRPI"
```

```
s = "A", numRows = 1
→ "A"
```

## Approach: simulate the bounce

You don't need to build an actual 2D grid — you only need to know, for each character in order, *which row it belongs to*. Track a `currentRow` pointer and a `direction` (`+1` or `-1`), and walk the string once:

1. Append the current character to `rows[currentRow]`.
2. If `currentRow` is on the top row (`0`) or the bottom row (`numRows - 1`), flip `direction`.
3. Move `currentRow` by `direction`.

Do that for every character, then join the row-buckets together in order (row `0`, row `1`, ... ) for the final answer.

```python
rows = ["" for _ in range(numRows)]
currentRow, direction = 0, -1

for char in s:
    rows[currentRow] += char
    if currentRow == 0 or currentRow == numRows - 1:
        direction = -direction
    currentRow += direction

return "".join(rows)
```

Starting `direction` at `-1` is a small trick: the first character always lands on row `0`, which immediately triggers the flip to `+1` — so the second character correctly moves down to row `1`, without needing a separate "first step" special case.

**Edge case:** if `numRows == 1`, row `0` and row `numRows - 1` are the same row, so the bounce logic would try to push `currentRow` to a row that doesn't exist. Handle it up front: with only one row, there's no zigzag at all, so the answer is just `s` unchanged.

**Complexity:** `O(n)` time — one pass over the string — and `O(n)` space for the row buckets, which together hold every character exactly once.

## Real-world analogy

Picture threading a ribbon of text between two horizontal rails, `numRows` apart, the way thread winds back and forth on a spool between two guide pins. The thread always keeps moving in the same direction — down, or up — until it touches a rail. The instant it touches one, it reverses and heads for the other rail. It never pauses, never skips a rail, and never crosses past one.

Each letter of the string gets laid down wherever the thread currently is when that letter comes up. Once you've laid down the whole string this way, snip the ribbon apart by rail (all the letters that touched rail `0`, then all the letters that touched rail `1`, and so on) and tape those strips together end to end — that's the zigzag reading.

## Files

| Language | File |
|----------|------|
| Python | [`python/zigzag_conversion.py`](python/zigzag_conversion.py) |
| Java   | [`java/ZigzagConversion.java`](java/ZigzagConversion.java) |
| C++    | [`cpp/zigzag_conversion.cpp`](cpp/zigzag_conversion.cpp) / [`cpp/zigzag_conversion.hpp`](cpp/zigzag_conversion.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/zigzag_conversion.py

# Java
javac java/ZigzagConversion.java -d java/out
java -cp java/out ZigzagConversion

# C++
g++ -std=c++17 cpp/zigzag_conversion.cpp -o cpp/zigzag_conversion
./cpp/zigzag_conversion
```

Each entry point runs the `numRows=3`, `numRows=4`, and `numRows=1` examples above.

## Tests

Seven cases per language: the classic 3-row and 4-row examples, a single row (no zigzag possible), a single row with a longer string, `numRows` at least as long as the string (degenerates to the original string, no bounce ever happens), the 2-row case (pure even/odd interleaving), and `numRows` exactly matching the string length (one straight pass down, no bounce back).

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/zigzag_conversion.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_zigzag_conversion.cpp -o tests/test_zigzag_conversion
./tests/test_zigzag_conversion

# Java (no JUnit dependency; compiles the solution and test together)
javac java/ZigzagConversion.java tests/ZigzagConversionTest.java -d tests/out
java -cp tests/out ZigzagConversionTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
