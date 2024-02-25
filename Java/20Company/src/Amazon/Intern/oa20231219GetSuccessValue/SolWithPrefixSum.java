package Amazon.Intern.oa20231219GetSuccessValue;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description
 * Get Success Value
 * 🔥 FULLTIME🤘 INTERN
 * Amazon Prime Video has recently released an exclusive series on its platform. They collected the number of viewers from n different regions across the world and stored the data in the array num_viewers.
 *
 * The success value of the release is defined as the sum of viewership in the top k regions, those with the highest viewers. For example, if num_viewers = [3, 2, 1, 4, 5] and k = 3, then the success value of the release is 3 + 4 + 5 = 12 as [3, 4, 5] are the top 3 values.
 *
 * Given a number of k values, calculate the success value for each query.
 *
 * Function Description
 *
 * Complete the function getSuccessValue in the editor.
 *
 * getSuccessValue has the following parameters:
 *
 * int num_viewers[n]: viewership from n different regions
 * int queries[q]: an array of k values
 * Returns
 *
 * int[q]: the maximum possible success values for each query
 * Example 1:
 * Input:  num_viewers = [2, 5, 6, 3, 5], queries = [2, 3, 5]
 * Output: [11, 16, 21]
 * Explanation:
 * The viewership in 5 regions is num_viewers = [2, 5, 6, 3, 5], and we want to find the success value for 3 queries that are queries = [2, 3, 5].
 * For the first query, k = 2, the viewership of the top 2 regions is [6, 5]. The success value is 6 + 5 = 11.
 * For the second query, k = 3, the viewership of the top 3 regions is [6, 5, 5] and 6 + 5 + 5 = 16.
 * For the third query, k = 5, all the 5 regions are used for the success value and 6 + 5 + 5 + 3 + 2 = 21.
 * Return [11, 16, 21].
 *
 * Example 2:
 * Input:  num_viewers = [7, 3, 5, 2], queries = [1, 4]
 * Output: [7, 17]
 * Explanation:
 * For the first query, k = 1, only the top region is used for the success value.
 * For the second query, k = 4, all 4 regions are used.
 * Return [7, 17].
 *
 * Example 3:
 * Input:  num_viewers = [7, 5, 6], queries = [1, 2, 3]
 * Output: [7, 13, 18]
 * Explanation:
 * For the first query, k = 1, only the top region is used for the success value.
 * For the second query, k = 2, only the top 2 regions are used.
 * For the third query, k = 3, all 3 regions are used.
 * Return [7, 13, 18].
 *
 * Constraints:
 * 1 <= n <= 105
 * 1 <= q <= 105
 * 1 <= num_viewers[i] <= 109
 * 1 <= queries[i] <= n
 */
public class SolWithPrefixSum {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the queries: ");
            String Q = scan.nextLine();
            if(Q.equals("q")) break;
            System.out.println("Enter the num_viewers:");
            String V = scan.nextLine();
            if(V.equals("q")) break;
            Q = Q.substring(1, Q.length()-1);
            V = V.substring(1, V.length()-1);
            String[] Qs = Q.split(",");
            String[] Vs = V.split(",");
            int[] queries = new int[Qs.length];
            int[] num_viewers = new int[Vs.length];
            for(int i=0;i<queries.length;++i) queries[i] = Integer.parseInt(Qs[i].trim());
            for(int i=0;i<num_viewers.length;++i) num_viewers[i] = Integer.parseInt(Vs[i].trim());
            int[] res = S1.getSuccessValue(queries, num_viewers);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] getSuccessValue(int[] queries, int[] num_viewers){
            /*
                Sol with prefix sum array:
                Input:  num_viewers = [7, 3, 5, 2], queries = [1, 4], Output: [7, 17]
                        sorted = [2,3,5,7]
                        prefix = []
            */
            Arrays.sort(num_viewers);
            reverse(num_viewers);
            for(int i=1;i<num_viewers.length;++i){
                num_viewers[i] = num_viewers[i-1]+num_viewers[i];
            }
            int[] ans = new int[queries.length];
            for(int i=0;i<queries.length;++i){
                ans[i] = num_viewers[queries[i]-1];
            }
            return ans;
        }
    }
    private static void reverse(int[] nums){
        int l=0,r=nums.length-1;
        while(l<r){
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
}
