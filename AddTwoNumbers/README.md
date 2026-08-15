# Add Two Numbers

A classic linked-list problem, implemented in **Python**, **Java**, and **C++**.

## Problem

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order** (the ones digit comes first), and each node contains a single digit.

Add the two numbers and return the sum as a linked list, in the same reversed format.

You may assume the two numbers do not contain any leading zero, except the number `0` itself.

### Example

```
Input:  l1 = 2 -> 4 -> 3   (represents 342)
        l2 = 5 -> 6 -> 4   (represents 465)
Output: 7 -> 0 -> 8        (represents 807)
```

```
Input:  l1 = 9 -> 9   (represents 99)
        l2 = 1        (represents 1)
Output: 0 -> 0 -> 1   (represents 100)
```

## Approach

Walk both lists at the same time, one node per step — exactly like adding two numbers by hand, column by column, starting from the ones place:

1. Take the current digit from each list (or `0` if that list has already run out — it's the shorter one).
2. Add the two digits plus any carry left over from the previous column.
3. The digit you write down is `total % 10`; the leftover (`total // 10`, always 0 or 1) becomes the carry for the next column.
4. Advance both pointers.
5. Keep going while *either* list still has nodes, *or* there's a carry left over (e.g. `9 + 9 = 18` needs a final extra digit).

**Complexity:** `O(max(n, m))` time, `O(max(n, m))` space, where `n` and `m` are the lengths of the two lists.

## Why "reversed order" matters

Addition naturally works right-to-left: ones, then tens, then hundreds, and so on — because that's the direction carries flow. Storing the ones digit at the *head* of the list means the natural, one-way traversal direction of a singly linked list (head → tail) lines up exactly with the natural direction of addition. You can add and carry as you walk forward, never needing to backtrack.

If the digits were stored in normal reading order instead (most significant digit first), you'd need to start adding from the *tail* — which a singly linked list can't do directly. You'd have to reverse the lists first, use a stack, or use recursion to unwind from the tail back to the head.

## Real-world analogy

Think of each linked list as a strip of sticky notes, one digit per note — except stuck down starting from the **ones place** instead of how you'd normally write a number left to right. The strip itself is the linked list: each note "points to" the next one.

To add two such strips the way you'd add numbers on paper:

- Put a finger on the first note of each strip (the ones digits).
- Add those two digits together. If one strip already ran out of notes (it represents a shorter number), just treat that spot as blank, i.e. `0`.
- If the sum is 10 or more, write down only the last digit and jot yourself a small "+1" carry reminder — the same way you'd carry a 1 when adding `7 + 8` by hand.
- Slide both fingers to the next note and repeat, remembering to add in any carry from before.
- Stop once both fingers have run off the end of their strips **and** you have no carry left in hand.

Every digit you compute gets stuck onto a brand-new third strip — your result — rather than reusing either original strip. And if there's one carry left over after both strips end (like `99 + 1`), that becomes one final extra sticky note.

## Files

| Language | File |
|----------|------|
| Python | [`python/add_two_numbers.py`](python/add_two_numbers.py) |
| Java   | [`java/AddTwoNumbers.java`](java/AddTwoNumbers.java) |
| C++    | [`cpp/add_two_numbers.cpp`](cpp/add_two_numbers.cpp) / [`cpp/add_two_numbers.hpp`](cpp/add_two_numbers.hpp) |
| Tests  | [`tests/`](tests/) |

## Running

```bash
# Python
python3 python/add_two_numbers.py

# Java
javac java/AddTwoNumbers.java -d java/out
java -cp java/out AddTwoNumbers

# C++
g++ -std=c++17 cpp/add_two_numbers.cpp -o cpp/add_two_numbers
./cpp/add_two_numbers
```

Each entry point builds `342` and `465` from linked lists, adds them, and prints `7 -> 0 -> 8` (i.e. `807`).

## Tests

Each language has a small hand-rolled test suite in [`tests/`](tests/) covering: the basic example, a carry that creates a brand-new leading digit (`99 + 1`), both inputs being `0`, lists of different lengths, single digits with no carry, a carry that has to ripple past the end of the shorter list, and a larger multi-digit case.

```bash
# Python (stdlib unittest, no dependencies)
python3 -m unittest discover -s tests -v

# C++ (no test framework dependency; solution logic lives in cpp/add_two_numbers.hpp
# so both the demo and the tests link against the same code)
g++ -std=c++17 tests/test_add_two_numbers.cpp -o tests/test_add_two_numbers
./tests/test_add_two_numbers

# Java (no JUnit dependency; compiles the solution and test together)
javac java/AddTwoNumbers.java tests/AddTwoNumbersTest.java -d tests/out
java -cp tests/out AddTwoNumbersTest
```

All three test runners print `PASSED`/`FAILED` per case and exit non-zero if anything fails.
