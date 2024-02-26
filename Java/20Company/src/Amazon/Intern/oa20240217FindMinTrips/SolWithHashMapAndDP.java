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
public class SolWithHashMapAndDP {
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
                Sol: Step1: we count each type of packages number in a hash map
                     Step2: traverse the value of hash map to determine the minimum trip times, which can
                            be convert to a climbing stair question and find the minimum steps.(One dimension DP)
                 packageweight = [1, 8, 5, 8, 5, 1, 1]
                 ms: 1:3 ->1
                     8:2 ->1
                     5:2 ->1
                ----------------------------------------------
                 In:   [7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7]   Out: 6
             */
            HashMap<Integer, Integer> ms = new HashMap<Integer, Integer>();
            for (int i : packageweight) {
                ms.put(i, ms.getOrDefault(i, 0) + 1);
            }
            int trip = 0;
            for (int cnt : ms.values()) {
                if(cnt<2) return -1;
                int step = getMinSteps(cnt);
                if(step==Integer.MIN_VALUE) return -1;
                trip+=step;
            }
            return trip;
        }
        public static int getMinSteps(int n){
            /*
        @Dsp: Same Problem with climb stair: each time you only climb 2 or 3, and find the minimum steps to get n stairs
        1. Meaning: dp[i]: the minimum steps to get stair i; index i: stair
        2. Formula: dp[i]: dp[i-4] dp[i-3] dp[i-2] dp[i-1] dp[i]; dp[i] = min(dp[i-2], dp[i-3])+1; each current index i will
                    come from dp[i-2] + 1 and dp[i-3]+1
        3. Initialize: dp[0] = MAX, dp[1] = MAX, dp[2] = 1, dp[3] = 1
        4. Traverse: From front to end.
             */
            if(n<2) return -1;
            if(n==2||n==3) return 1;
            int[] dp  = new int[n+1];
            Arrays.fill(dp, Integer.MAX_VALUE);
            dp[2] = 1;
            dp[3] = 1;
            for(int i=4;i<=n;++i){
                if(dp[i-2]==Integer.MAX_VALUE&&dp[i-3]==Integer.MAX_VALUE) continue;//Both dp[i-2] and dp[i-3] are no answer case.
                dp[i] = Math.min(dp[i-2], dp[i-3])+1;
            }
            return dp[n];
        }
    }
}
