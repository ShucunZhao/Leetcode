package lc746MinCostClimbingStairs;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithDP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter cost:");
            String C = scan.nextLine();
            if(C.equals("q")) break;
            C = C.substring(1, C.length()-1);
            String[] Cs = C.split(",");
            int[] cost = new int[Cs.length];
            for(int i=0;i<cost.length;++i){
                cost[i] = Integer.parseInt(Cs[i].trim());
            }
            System.out.println("Res: "+S1.minCostClimbingStairs(cost));
        }
    }

    private static class Solution{
        public int minCostClimbingStairs(int[] cost) {
            /* We need to get to the stair cost.size().
               1.dp[i]: the min cost in stair i, i is the stair index
               2.dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
               3.dp[0] = 0, dp[1] = 0.
            */
            int[] dp = new int[cost.length+1];
            dp[0] = 0;
            dp[1] = 0;
            for(int i=2;i<=cost.length;++i){
                dp[i] = Math.min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
            }
            return dp[cost.length];
        }
    }
}
