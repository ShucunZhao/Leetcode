package lc209MinimumSizeSubarraySum;
import java.util.Scanner;

public class SolWithSW {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter array with format [x,x,x]: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                System.out.println("Quit.");
                break;
            }
            System.out.println("Enter the target: ");
            int target;
            target = Integer.parseInt(scan.nextLine());
            String numsStr = numsIn.substring(numsIn.indexOf('[')+1, numsIn.indexOf(']'));
            String[] strS = numsStr.split(",");
            int[] nums = new int[strS.length];
            for(int i=0;i<strS.length;i++){
                nums[i] = Integer.parseInt(strS[i]);
            }
            System.out.println("Res: "+S1.minSubArrayLen(target,nums));
        }
    }
    private static class Solution{
        public int minSubArrayLen(int target, int[] nums) {
            /*
                                            l
                 Input: target = 7, nums = [2,3,1,2,4,3]  Output: 2
                                                  r
                      sum: 2,5,6,8,6,10,7,10,9,7
                      res: 3,2
                      ---------------------------------------
                       l
                      [1,2,3,4,5]       11
                       r
                      sum:1,3,6,10,15
                      res:
            */
            int l=0, r=0;
            int sum = 0;
            int len = 0;
            int res = Integer.MAX_VALUE;
            while(r<nums.length){
                sum+=nums[r];
                while(sum>=target&&l<nums.length){
                    len = r-l+1;
                    res = Math.min(res, len);
                    sum-=nums[l];
                    l++;
                }
                r++;
            }
            return res==Integer.MAX_VALUE?0:res;
        }
    }
}
