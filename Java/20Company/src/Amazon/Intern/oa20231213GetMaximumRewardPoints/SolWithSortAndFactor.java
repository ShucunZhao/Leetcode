package Amazon.Intern.oa20231213GetMaximumRewardPoints;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description
 * Get Max Reward Points
 * 🤘 INTERN
 * Amazon shopping periodically has offers to attract more customer.
 *
 * It recently launched an offer for nitems in its inventory, where the ithitem offered reward[i]reward points to the customer purchasing the item. Every time an offer-bearing item is purchased, the customer gains the reward points associated with that item. Then the reward points of the remaining items are reduced by 1unless it will reduce the points below 0.
 *
 * Note: Each item can be purchased at most once, in other words, reward[i] becomes0after the ithitem is purchased.
 *
 * Function Description
 *
 * Complete the function getMaxRewardPointsin the editor.
 *
 * getMaxRewardPointshas the following parameter(s):
 *
 * int reward[n]: the reward points of each item
 * Returns
 *
 * long_int: the maximum reward points which can be collected
 * *** Credit to eva 👑 ***
 *
 * Example 1:
 * Input:  reward = [5, 2, 2, 3, 1]
 * Output: 7
 * Explanation:
 * Considering 0-based indexing, the items can be purchased in the following order:
 * 1. First, purchase item 2, points earned = reward[2] = 2. Points of remaining items after this purchase reward = [4, 1, 0, 2, 0].
 * 2. Next, purchase item 3, points earned = reward[3]= 2. Points of remaining items after this purchase reward = [3, 0, 0, 0, 0].
 * 3. Finally, purchase item 0, points earned = reward[0] = 3. Points of remainig items after this purchase reward = [0, 0, 0, 0, 0]
 * At this point, no items have reward points left. The maximum reward points is 2 + 2 + 3 = 7.
 *
 * Example 2:
 * Input:  reward = [5 ,5 ,5]
 * Output: 12
 * Explanation:
 * Using 0-based indexing, the items can be purchased in the following order:
 * 1. First, purchase item 0, points earned = reward[0] = 5. Points of remaining items after this purchase reward = [0, 4, 4].
 * 2. Next, purchase item 1, points earned to = reward [1] = 4. and reward = [0, 3, 3].
 * 3. Finally, purchase item 2, points earned = reward[2] = 3 and reward = [0, 0, 0].
 * The maximum reward points is (5 + 4 + 3 = 12).
 *
 * Constraints:
 * 1 <= n <= 105
 * 0 <= reward[i] <= 106
 */
public class SolWithSortAndFactor {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the reward: ");
            String R = scan.nextLine();
            if(R.equals("q")) break;
            R = R.substring(1, R.length()-1);
            String[] Rs = R.split(",");
            int[] reward = new int[Rs.length];
            for(int i=0;i<reward.length;++i) reward[i] = Integer.parseInt(Rs[i].trim());
            System.out.println("Res: "+S1.getMaxRewardPoints(reward));
        }
    }
    private static class Solution{
        public long getMaxRewardPoints(int[] reward) {
            /*
                Sol with sort then get and subtract.
                How to substract? We just need to maintain a factor to be substracted and increase it by 1 when get points each time,
                then use next element to subtract it to get the next time points
                Ex1：
                    Input:  reward = [5, 2, 2, 3, 1]    Output: 7
                            sorted = [5,3,2,2,1] factor: 2 ans:5,5+(3-1)=7,
                                          i
            */
            Arrays.sort(reward);
            reverse(reward);
            long ans = 0;
            int factor = 0;
            int l=0;
            while(l<reward.length&&(reward[l]-factor>0)){
                ans+=(long)(reward[l]-factor);
                factor++;
                l++;
            }
            return ans;
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
}
