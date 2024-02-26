package Amazon.Intern.oa20230831GetMeanRankCount;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @Description
 * Get Mean Rank Count
 * 🤘 INTERN
 * Amazon Academy recently organized a scholaship test on its platform.
 * There are nstudents with roll numbers 1, 2, ..., n who appeared for the test, where the rank secured by the ithstudent is denoted by rank[i]. Thus, the array rank is a permutation of length n. Groups can only be formed with students having consecutive roll numbers, in other words, a subarray of the original array. For each value x (1 <= x <= n), find the number of groups that can be formed such that they have a mean rank equal to x.
 * More formally, given a permutaion of length n, find the number of subarrays of the given array having a mean value equal to x, for each xin the range [1, n].
 *
 * Notes
 * 1. The mean value of an array of kelements is defined as the sum of elements divided by k.
 * 2. A permutation of leangth nis a sequence where each number from qtonappears exactly once.
 * 3. A subarray of an array is a contiguous section of the array.
 * Function Description
 * Complete the function getMeanRankCount in the editor. getMeanRankCount has the following parameter: int rank[n]: the ranks of the students.
 *
 * Returns
 * int[n]: the ith integer (where 1 <= i <= n) denotes the number of groups with a mean rank of i.
 *
 * Example 1:
 * Input:  rank = [1, 2, 3, 4, 5]
 * Output: [1, 2, 3, 2, 1]
 * Explanation:
 * Read the above as 'For the mean x = 1, the group [1] has mean value 1. There is 1 group'. and so on. The full answer is [1, 2, 3, 2, 1].
 *
 * Example 2:
 * Input:  rank = [4, 3, 2, 1]
 * Output: [1, 2, 2, 1]
 * Explanation:
 *  x = 1 -> [1]
 *  x = 2 -> [3, 2, 1], [2]
 *  x = 3 -> [3], [4, 3, 2]
 *  x = 4 -> [4]
 *
 *  Example 3:
 *  Input:  rank = [4, 7, 3, 6, 5, 2, 1]
 * Output: [1, 1, 1, 4, 4, 1, 1]
 * Explanation:
 *  x = 1 -> [1]
 *  x = 2 -> [2]
 *  x = 3 -> [3]
 *  x = 4 -> [4], [3, 6, 5, 2], [7, 3, 6, 5, 2, 1], [4, 7, 3, 6, 5, 2 ,1]
 *  x = 5 -> [5], [7, 3], [4, 7, 3, 6] and [4, 7, 3, 6, 5]
 *  x = 6 -> [6]
 *  x = 7 -> [7]
 *
 *  Constraints:
 * 1 <= n <= 103
 * 1 <= rank[i] <= n
 * The array rank contains all distinct elemens, and thus, is a permutation of {1..n}.
 */
public class SolWithPrefixSum {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the rank: ");
            String R = scan.nextLine();
            if(R.equals("q")) break;
            R = R.substring(1, R.length()-1);
            String[] Rs = R.split(",");
            int[] rank = new int[Rs.length];
            for(int i=0;i<rank.length;++i) rank[i] = Integer.parseInt(Rs[i].trim());
            int[] res = S1.getMeanRankCount(rank);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] getMeanRankCount(int[] rank) {
            int n = rank.length;
            int[] count = new int[n];
            HashMap<Integer, Integer> averageCount;
            long sum;
            for (int i = 0; i < n; i++) {
                averageCount = new HashMap<>();
                sum = 0;
                for (int j = i; j < n; j++) {
                    sum += rank[j];
                    int length = j - i + 1;
                    // Only consider cases where the total sum is an integer multiple of the subarray length
                    if (sum % length == 0) {
                        int average = (int) (sum / length);
                        // Only consider averages that are within the possible range
                        if (average > 0 && average <= n) {
                            averageCount.put(average, averageCount.getOrDefault(average, 0) + 1);
                            // This average is valid, we found another subarray for it
                            count[average - 1]++;
                        }
                    }
                }
            }
            return count;
        }
    }
}
