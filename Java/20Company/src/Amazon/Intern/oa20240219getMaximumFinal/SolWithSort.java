package Amazon.Intern.oa20240219getMaximumFinal;


import java.util.Arrays;

/**
 * @Description
 * As part of your Day 1 orientation at Amazon, your new team is hosting a programming challenge. You've been asked to participate in completing the following task. Given an array of integers, perform certain operations in order to satisfy some constraints. The constraints are as follows:
 * The first array element must be 1.
 * For all other elements, the difference between adjacent integers must not be greater than 1. Inother words, for 1 <= i< n, arr[i] - arr[i-1]<=1.
 * To accomplish this, the following operations areavailable:
 * Rearrange the elements in any wayReduce any element to any number that is at least 1.
 *
 * What is the maximum value that can be achievedfor the fina/element of the array by followingthese operations and constraints?
 *
 * Example：
 * arr=[3, 1, 3, 4]
 *
 * Subtract 1 from the first element, making the array [2, 1, 3, 4].
 * Rearrange the array into [1, 2, 3, 4].
 * The final element's value is 4, the maximum valuethat can be achieved. Therefore, the answer is 4.
 * Function Description：
 * Complete the function maximumFinal in the editor below.
 * maximumFinal has the following parameter:
 * int arr[n]: an array of integers
 * Returns:
 * int: the maximum value that can be achieved forthe final element of the array given the conditions above.
 *
 * Constraints:
 * 1<=n<=10^5
 * 1 <= arr[n]< 10^9
 */
public class SolWithSort {
    public static int maximumFinal(int[] arr) {
        // First, sort the array
        Arrays.sort(arr);

        // Initialize the current value to be 1 because the first element must be 1
        int currentValue = 1;

        // Iterate over the array, starting from the second element
        for (int i = 1; i < arr.length; i++) {
            // If the current element is within 1 of the previous, increment currentValue
            if (arr[i] <= currentValue + 1) {
                currentValue = arr[i];
            } else {
                // If the difference is more than 1, we can only increment the currentValue by 1
                currentValue += 1;
            }
        }

        return currentValue;
    }

    public static void main(String[] args) {
        int[] arr = {3, 1, 3, 4};
        System.out.println(maximumFinal(arr)); // Output should be 4
    }
}
