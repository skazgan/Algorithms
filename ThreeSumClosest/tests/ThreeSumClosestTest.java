/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/ThreeSumClosest.java and run the main method.
 */
public class ThreeSumClosestTest {

    private static int failures = 0;

    public static void main(String[] args) {
        check("classic_example", new int[]{-1, 2, 1, -4}, 1, 2);
        check("exact_match_triggers_early_return", new int[]{1, 1, 1, 0}, 2, 2);
        check("all_zeros", new int[]{0, 0, 0}, 1, 0);
        check("exactly_three_elements", new int[]{1, 1, 1}, 0, 3);
        check("negative_numbers_exact_match", new int[]{1, 1, -1, -1, 3}, -1, -1);
        check("target_far_beyond_reach", new int[]{1, 1, 1, 1}, 100, 3);
        check("duplicates_with_exact_zero_sum", new int[]{-4, -1, -1, 0, 1, 2}, 0, 0);
        check("larger_array_no_exact_match", new int[]{1, 2, 4, 8, 16, 32, 64, 128}, 80, 81);

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void check(String name, int[] nums, int target, int expected) {
        ThreeSumClosest solver = new ThreeSumClosest();
        int actual = solver.threeSumClosest(nums, target);
        if (actual != expected) {
            System.out.println("FAILED: " + name + " expected=" + expected + " actual=" + actual);
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }
}
