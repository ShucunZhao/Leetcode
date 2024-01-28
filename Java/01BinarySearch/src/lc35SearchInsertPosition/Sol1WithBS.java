package lc35SearchInsertPosition;
import java.util.Scanner;

public class Sol1WithBS {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please input the array with [x,x,x,x,x] format: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                break;
            }
            System.out.println("Please input the target: ");
            int target;
            target = Integer.parseInt(scan.nextLine());
            String numsStr = numsIn.substring(numsIn.indexOf('[')+1, numsIn.indexOf(']'));
            String[] strSet = numsStr.split(",");//This parameter should be a string used for regular expression string.
            int[] nums = new int[strSet.length];
            for(int i=0;i<strSet.length;++i){
                nums[i] = Integer.parseInt(strSet[i]);
            }
            System.out.println(S1.searchInsert(nums, target));
        }

    }
    public static class Solution{
        public int searchInsert(int[] nums, int target){
            int l = 0, r = nums.length - 1;
            while(l<=r){
                int m = l+(r-l)/2;
                if(nums[m]>target){
                    r = m-1;
                }
                else if(nums[m]<target){
                    l = m+1;
                }
                else{
                    return m;
                }
            }
            /*
                    t: 2
                   i:0 1 2 3 4
                       l
                     1,3,5,7,9
                      r
                       m
             */
            return l;
        }
    }
}
