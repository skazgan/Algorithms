"""
ZigZag Conversion
------------------
Given a string s and an integer numRows, write the string in a zigzag
pattern across numRows rows (down one column, then diagonally up to the
next column, repeating), then read the result row by row and concatenate.

Example:
    Input:  s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

    Input:  s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"

    Input:  s = "A", numRows = 1
    Output: "A"

Approach: simulate the bounce
    Track a currentRow pointer and a direction (+1 or -1). Walk the string
    once, appending each character to the row it currently sits on. Every
    time the pointer touches the top row (0) or the bottom row
    (numRows - 1), flip the direction -- like a ball bouncing between two
    walls. Join the row buckets together at the end.

Complexity:
    Time:  O(n) - one pass over the string
    Space: O(n) - the row buckets together hold every character once
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        rows = ["" for _ in range(numRows)]
        currentRow = 0
        direction = -1

        for char in s:
            rows[currentRow] += char
            if currentRow == 0 or currentRow == numRows - 1:
                direction = -direction
            currentRow += direction

        return "".join(rows)


if __name__ == "__main__":
    solver = Solution()
    print(solver.convert("PAYPALISHIRING", 3))  # PAHNAPLSIIGYIR
    print(solver.convert("PAYPALISHIRING", 4))  # PINALSIGYAHRPI
    print(solver.convert("A", 1))               # A
