package Amazon.Intern.oa20240123GetPairsCount;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description
 * Get Pairs Count
 * 🤘 INTERN
 * Developers at Amazon are building a multi-process analysis tool to analyze the computational intensity of the processes. There are n processes and the ith process needs process[i] computation resources for completion.
 *
 * Two processes are considered to be computationally the same if their resource requirements differ by at most k.
 *
 * Given the array process and an integer k, find the number of pairs of processes that are computationally the same.
 *
 * Function Description
 *
 * Complete the function getPairsCount in the editor.
 *
 * getPairsCount takes the following arguments:
 *
 * int process[n]: the computational resource requirement of the processes
 * int k: the threshold for being computationally the same
 * Returns
 *
 * long integer: the number of pairs of processes that are computationally the same
 *
 * Example 1:
 * Input:  process = [100, 200, 300, 400], k = 250
 * Output: 5
 * Explanation:
 * The computationally-same processes are (100, 200), (100, 300), (200, 300), (200, 400), and (300, 400).
 * Example 2:
 * Input:  process = [10, 12, 11], k = 0
 * Output: 0
 * Explanation:
 * All the pairs of processes have differences between computational resource requirements greater than 0.
 * Example 3:
 * Input:  process = [7, 10, 13, 11], k = 3
 * Output: 4
 * Explanation:
 * The process pairs are shown in the above image. Hence the answer is 4.
 * Constraints:
 * 1 ≤ n ≤ 2 * 10^5
 * 1 ≤ process[i] ≤ 10^6
 * 0 ≤ k ≤ 10^6
 *
 */
public class SolWithSortTwoPointer {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true) {
            System.out.println("Enter process:");
            String In = scan.nextLine();
            if (In.equals("q")) break;
            System.out.println("Enter k:");
            String K = scan.nextLine();
            if (K.equals("q")) break;
            In = In.substring(1, In.length() - 1);
            String[] InSet = In.split(",");
            int[] process = new int[InSet.length];
            for (int i = 0; i < InSet.length; ++i) {
                process[i] = Integer.parseInt(InSet[i].trim());
            }
            int k = Integer.parseInt(K.trim());
            System.out.println("Res: " + S1.getPairsCount(process, k));
        }
    }
    private static class Solution{
        public long getPairsCount(int[] process, int k) {
            /*
                    Input:  process = [7, 10, 13, 11], k = 3  Output: 4
                                         l
                            sort = [7,10,15,16]
                                               r
                            tmp: r-l-1
                            ans+=tmp
            */
            Arrays.sort(process);
            int n = process.length;
            long ans = 0;
            for(int l=0,r=0;l<n;++l){
                while(r<n&&process[r]-process[l]<=k){
                    r++;
                }
                ans+=(long)(r-l-1);
            }
            return ans;
        }
    }
}
