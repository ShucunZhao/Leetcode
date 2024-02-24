package Amazon.Intern.oa20240217FindMinTrips;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * @Description
 * Find Minimum Trips
 * 🤘 INTERN
 * There were a large number of orders placed on Amazon Prime Day. The orders are packed and are at the warehouse ready to be delivered. The delivery agent needs to deliver them in as few trips as possible.
 *
 * In a single trip, the delivery agent can choose packages following either of two rules:
 *
 * Choose two packages with the same weight
 * Choose three packages with the same weight
 * Determine the minimum number of trips required to deliver the packages. If it is not possible to deliver all of them, return -1.
 *
 * Function Description
 *
 * Complete the function findMinTrips in the editor.
 *
 * findMinTrips has the following parameter:
 *
 * int packageweight[n]: the weights of each package
 * Returns
 *
 * int: the minimum number of trips required or -1 if it is not possible to deliver them all
 *
 * Constraints
 *
 * 1 ≤ n ≤ 10^5
 * 1 ≤ packageweight[i] ≤ 10^9
 *
 * Example 1:
 * Input:  packageweight = [1, 8, 5, 8, 5, 1, 1]
 * Output: 3
 * Explanation:
 *
 * It takes 3 trips to deliver all the packages.
 *
 * Example 2:
 *
 * Input:  packageweight = [3, 4, 4, 3, 1]
 * Output: -1
 * Explanation:
 *
 * Packages with weights 3 and 4 can be removed in groups of two. The package of weight 1 cannot be delivered as it cannot be chosen according to the rules.
 * Since it is not possible to deliver all packages, the answer is -1.
 */
public class SolWithPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the packageweight with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] packageweight = new int[InSet.length];
            for(int i=0;i<InSet.length;++i) packageweight[i] = Integer.parseInt(InSet[i].trim());
            System.out.println("Res: "+S1.findMinTrips(packageweight));
        }
    }
    private static class Solution {
        public int findMinTrips(int[] packageweight) {
            /*
                Sol: Step1: we count each type of packages number which is 'int cnt'
                     Step2: find the minimum times to subtract cnt by 2 or 3 each time:
                        Step2.1: Check if cnt can be divided by 3 cause it's the minumum times.
                        Step2.2: If cnt cannot be divided by 3, check if it can be divided by 2.
                        Step2.3: If cnt cannot be divided by 2 and 3, we try to divide cnt by 2 or 3 one time,
                                 and then check if the remain-cnt can be divided by another number(2 or 3). And
                                 we find the smaller as the ans.
                        Step2.4: If all cases cannot divide cnt to 0, should be return -1.

                 packageweight = [1, 8, 5, 8, 5, 1, 1]
                 ms: 1:3 ->1
                     8:2 ->1
                     5:2 ->1
             */
            HashMap<Integer, Integer> ms = new HashMap<Integer, Integer>();
            for (int i : packageweight) {
                ms.put(i, ms.getOrDefault(i, 0) + 1);
            }
            int trip = 0;
            for (int cnt : ms.values()) {
                if(cnt<2) return -1;
                int step = findMinSteps(cnt);
                if(step==-1) return -1;
                trip+=step;
                /* Math method: [7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7] this cannot pass
                    */
            }
            return trip;
        }
        public static int findMinSteps(int n) {
            if(n==0) return 0;
            //Special case when n<2 is impossible return -1
            if (n < 2) {
                return -1;
            }
            // Step1: Create a dp array to store minimum steps when the n is index i, we need to get answer of n should the size should be n+1.
            int[] dp = new int[n + 1];
            // Initial all results as -1
            Arrays.fill(dp, -1);// All the i = 1 should be -1 because it's impossible to subtract 2 or 3 to get 0.
            dp[0] = 0;
            // dp[1] = -1;
            // 遍历从1到n，填充dp数组
            for (int i = 2; i <= n; i++) {
                // 如果从i-2到i是可行的（即dp[i-2]不是-1），更新dp[i]
                if (i - 2 >= 0 && dp[i - 2] != -1) {
                    dp[i] = dp[i - 2] + 1;
                }
                // 如果从i-3到i是可行的，也更新dp[i]
                // 此时，如果dp[i]已经有值，取两种可能的最小值
                if (i - 3 >= 0 && dp[i - 3] != -1) {
                    dp[i] = dp[i] != -1 ? Math.min(dp[i], dp[i - 3] + 1) : dp[i - 3] + 1;
                }
            }

            // 返回到达数字n所需的最小步数
            // 如果dp[n]为-1，意味着无法通过减2或减3来达到n，因此返回-1
            return dp[n];
        }
    }
}
