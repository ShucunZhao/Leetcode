package Amazon.oa20240201MakePowerNonDecreasing;
import java.util.Scanner;

/**
 * @Description:
    Make Power Non-decreasing AWS provides scalable system. A set of n servers are used for horizontally scaling an application. The goal is to have the computational power of the servers in non-decreasing order. To do so, you can increase the computational power of each server in any contiguous segment by x. Choose the values of x such that after the computational powers are in non-decreasing order, the sum of the x values is minimum.

    Example 1:
    Input: power = [10, 13, 7, 8, 15, 5, 18]
    Output: 16
    Explanation: Add 6 units to the subarray [2, 3] so the power is [10, 13, 13, 14, 15, 5, 18], and then add 10 units to the subarray [5] so the power is [10, 13, 13, 14, 15, 15, 18].
    The final arrangement of the server is: [10, 13, 13, 14, 15, 15, 18]. The ans is 6 + 10 = 16.

    Example 2:
    Input:  power = [3, 4, 1, 6, 2]
    Output: 7
    Explanation:
    Add 3 units to the subarray [2, 4] so the power is [3, 4, 4, 9, 5], and then add 4 units to the subarray [4] so the power is [3, 4, 4, 9, 9]. The final arrangement of the server is: [3, 4, 4, 9, 9]. The ans is 3 + 4 = 7. (As shown in the image)

    Constraints: 1 <= n <= 105 1 <= power[i] <= 109
 */
public class SolWithGreedy {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter power with format [x,x,x]:" );
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] power = new int[InSet.length];
            for(int i=0;i<power.length;++i) power[i] = Integer.parseInt(InSet[i].trim());
            System.out.println("Res: "+S1.makePowerNonDescreasing(power));
        }
    }
    private static class Solution{
        public int makePowerNonDescreasing(int[] power) {
            /*
                Sol: we need find the max diff in the range, and each time meet the non-descending case add the max diff to ans.
                And if the last element is still descending, we need to add the result again at last to prevent else didn't execute.
                 power:     [10, 13, 7, 8, 15, 5, 18]
                 new power: [10, 13, 13, 13, 15, 15, 18]
                                                      i
                             diff: 10
                             res: 16
                -------------------------------------
                power:     [10, 13, 7,  8,  15, 5,  14]
                new power: [10, 13, 13, 13, 15, 15, 15]
                                                     i
                             diff: 10
                             res: 6

             */
            int maxDiff = 0;
            int ans = 0;
            for(int i=1;i<power.length;++i){
                if(power[i]<power[i-1]){
                    maxDiff = Math.max(maxDiff, power[i-1]-power[i]);
                    power[i] = power[i-1];
                }
                else{
                    ans+=maxDiff;
                    maxDiff = 0;
                }
            }
            ans+=maxDiff;//Handle the last element is descending case.
            return ans;
        }
    }
}
