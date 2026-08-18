/**
 * ZigZag Conversion
 * ------------------
 * Given a string s and an integer numRows, write the string in a zigzag
 * pattern across numRows rows (down one column, then diagonally up to the
 * next column, repeating), then read the result row by row and concatenate.
 *
 * Example:
 *   Input:  s = "PAYPALISHIRING", numRows = 3
 *   Output: "PAHNAPLSIIGYIR"
 *
 *   Input:  s = "PAYPALISHIRING", numRows = 4
 *   Output: "PINALSIGYAHRPI"
 *
 *   Input:  s = "A", numRows = 1
 *   Output: "A"
 *
 * Approach: simulate the bounce
 *   Track a currentRow pointer and a direction (+1 or -1). Walk the string
 *   once, appending each character to the row it currently sits on. Every
 *   time the pointer touches the top row (0) or the bottom row
 *   (numRows - 1), flip the direction -- like a ball bouncing between two
 *   walls. Join the row buckets together at the end.
 *
 * Complexity:
 *   Time:  O(n) - one pass over the string
 *   Space: O(n) - the row buckets together hold every character once
 */

public class ZigzagConversion {

    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        int direction = -1;

        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = -direction;
            }
            currentRow += direction;
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        ZigzagConversion solver = new ZigzagConversion();
        System.out.println(solver.convert("PAYPALISHIRING", 3));  // PAHNAPLSIIGYIR
        System.out.println(solver.convert("PAYPALISHIRING", 4));  // PINALSIGYAHRPI
        System.out.println(solver.convert("A", 1));                // A
    }
}
