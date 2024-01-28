package lc34FindFirstLastPosofEleminSortedArray;
import java.util.Scanner;

public class Sol1WithBS {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please input the array with [x,x,x,x,x] format: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                System.out.println("Quit.");
                break;
            }
            System.out.println("Please input the target: ");
            int target;
            target = Integer.parseInt(scan.nextLine());
            String numsStr = numsIn.substring(numsIn.indexOf('[')+1, numsIn.indexOf(']'));
            String[] strSet = numsStr.split(",");
            int[] nums = new int[strSet.length];
            for(int i=0;i<strSet.length;++i){
                nums[i] = Integer.parseInt(strSet[i]);
            }
            int[] res = S1.searchRange(nums, target);
            System.out.println("Result: ["+res[0]+","+res[1]+"]");
        }
    }
    public static class Solution{
        public int[] searchRange(int[] nums, int target){
            if(nums.length==0) return new int[]{-1, -1};
            return new int[]{findPos(nums, target, true), findPos(nums, target, false)};
        }
        public int findPos(int[] nums, int target, boolean first){
            /*
                        i  :   0 1 2 3 4  5
                               l
                Input: nums = [5,7,7,8,8,10], target = 8
                                          r
                Output: [3,4]
             */
            int l = 0, r = nums.length-1;
            while(l<=r){
                int m = l+(r-l)/2;
                if(nums[m]>target){
                    r = m-1;
                }
                else if(nums[m]<target){
                    l = m+1;
                }
                else{
                    if(first){
                        if(m==0||nums[m-1]<target){
                            return m;
                        }
                        else{
                            r = m-1;
                        }
                    }
                    else{
                        if(m==nums.length-1||nums[m+1]>target){
                            return m;
                        }
                        else{
                            l = m+1;
                        }
                    }
                }
            }
            return -1;
        }
    }
}
