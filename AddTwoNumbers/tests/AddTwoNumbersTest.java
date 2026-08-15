import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/AddTwoNumbers.java and run the main method.
 */
public class AddTwoNumbersTest {

    private static int failures = 0;

    public static void main(String[] args) {
        check("basic_example", new int[]{2, 4, 3}, new int[]{5, 6, 4}, new int[]{7, 0, 8});
        check("carry_creates_new_digit", new int[]{9, 9}, new int[]{1}, new int[]{0, 0, 1});
        check("both_zero", new int[]{0}, new int[]{0}, new int[]{0});
        check("different_lengths", new int[]{9, 9, 9}, new int[]{1}, new int[]{0, 0, 0, 1});
        check("single_digits_no_carry", new int[]{2}, new int[]{3}, new int[]{5});
        check("carry_propagates_through_shorter_list", new int[]{1}, new int[]{9, 9}, new int[]{0, 0, 1});
        check("large_numbers",
                new int[]{9, 9, 9, 9, 9, 9, 8},
                new int[]{9, 9, 9, 9, 9, 9, 9},
                new int[]{8, 9, 9, 9, 9, 9, 8, 1});

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void check(String name, int[] l1Digits, int[] l2Digits, int[] expected) {
        AddTwoNumbers solver = new AddTwoNumbers();
        AddTwoNumbers.ListNode l1 = AddTwoNumbers.buildList(l1Digits);
        AddTwoNumbers.ListNode l2 = AddTwoNumbers.buildList(l2Digits);
        AddTwoNumbers.ListNode result = solver.addTwoNumbers(l1, l2);

        int[] actual = toArray(result);
        if (!Arrays.equals(actual, expected)) {
            System.out.println("FAILED: " + name
                    + " expected=" + Arrays.toString(expected)
                    + " actual=" + Arrays.toString(actual));
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }

    private static int[] toArray(AddTwoNumbers.ListNode node) {
        List<Integer> list = new ArrayList<>();
        while (node != null) {
            list.add(node.val);
            node = node.next;
        }
        int[] arr = new int[list.size()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i);
        }
        return arr;
    }
}
