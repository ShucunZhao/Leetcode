package Amazon.Intern.oa20231227CountGamesWonByGroup1_CN;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Description
 * Count Games Won By Group1 (AMZ China)
 * 🤘 INTERN
 * Amazon games is organizing a tournament of pair games where two teams of two players each compete against one another.
 *
 * There are two groups group1 and group2 of size neach. The skill levels of the ith players of the groups are group1[i] and group2[i]. Fro each pair of indices, (i, j)(0 <= i < j < n), the pair of players (group1[i]
 *   + group1[j]) compete in the pair game with (group2[i] + group2[j])
 *
 * Given group1 and group2, fine the number of games group1 will win. Since the answer can be large, report it modulo 109 + 7.
 *
 * Function Description
 *
 * Complete the function countGameWonByGroup1 in the editor.
 *
 * int group1[n]: The skills of the players of group1
 *
 * int group2[n]: The skills of the players of group2
 * Returns
 * int: The number of games won by group1 modulo 109 + 7.
 *
 * Example 1:
 * Input:  n = 3, group1 = [1, 2, 3], group2 = [3, 2, 1]
 * Output: 1
 * Explanation:
 * Explanation:
 * 1.Pair: (0,1), group1: [1,2], group2: [3,2], (1+2)<(3+2), so winner is group2
 * 2.Pair: (0,2), group1:[1, 3], group2: [3,1], (1+3)<(3+2), so tie
 * 3.Pair: (1,2), group1: [2,3], group2: [2,1], (2+3)>(2+1), so winner is group1
 * So the win times of group1 is 1.
 */
public class SolWithSortDiffAndTwoPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true) {
            System.out.println("Enter n:");
            String N = scan.nextLine();
            if (N.equals("q")) break;
            System.out.println("Enter group1:");
            String G1 = scan.nextLine();
            if (G1.equals("q")) break;
            System.out.println("Enter group2:");
            String G2 = scan.nextLine();
            if (G2.equals("q")) break;
            int n = Integer.parseInt(N);
            G1 = G1.substring(1, G1.length() - 1);
            G2 = G2.substring(1, G2.length() - 1);
            String[] G1s = G1.split(",");
            String[] G2s = G2.split(",");
            int[] group1 = new int[G1s.length];
            int[] group2 = new int[G2s.length];
            for(int i=0;i<group1.length;++i){
                group1[i] = Integer.parseInt(G1s[i].trim());
                group2[i] = Integer.parseInt(G2s[i].trim());
            }
            System.out.println("Res: " + S1.countGamesWonByGroup1(n, group1, group2));
        }
    }
    private static class Solution{
        public int countGamesWonByGroup1(int n, int[] group1, int[] group2) {
            /*
             Input:  n = 3, group1 = [1, 2, 3], group2 = [3, 2, 1]   Output: 1      sorted: [-2,0,2]
        Sol: Because the each pairs can be treated as one on one(1 v 1) twice,                l    r
         Step1: so we can find all the ability difference between group1 and group2 in the same index, get the g1[i]-g2[i]
         ability-difference array: diff: [-2,0,2]. Step2: we sort it by ascending order to get the corresponding ability of
         group1 members sorted: [-2,0,2].  Step3: we use two pointers method to calculate the group1 member win cases:
         Step3.1: fix the most-right pointer which represent the strongest member of group1
         Step3.2: Then we move left pointer from left-most to right-1 pos and if only diff[left]+diff[right] is larger than 0
              that means all the pairs (left,right) of the group1 from left to right-1 will win(cause diff is ascending order)
         Step3.3: If the diff[left]+diff[right]<=0 we need to move left to left+1 cause this case of pair (left,right) for
         group1 will lose. Step4: Each time the step3 finished, we move the right to right-1 to determine the next larger
          group1 member situations.
            */
            int mod = 1000000007;
            List<Integer> diff = new ArrayList<>();
            for(int i=0;i<n;++i) diff.add(group1[i]-group2[i]);
            int left = 0;
            int right = n-1;
            int ans = 0;
            while(left<right){
                if(diff.get(left)+diff.get(right)>0){
                    ans+=(right-left);
                    ans%=mod;
                    right--;
                }
                else{
                    left++;
                }
            }
            return ans;
        }
    }
}
