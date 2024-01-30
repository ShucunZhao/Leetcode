package lc283MoveZeroes;
import java.util.Scanner;

public class SolWithTP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the array with format [x,x,x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                System.out.println("Quit.");
                break;
            }
            String numsStr = In.substring(In.indexOf('[')+1, In.indexOf(']'));
            String[] strS = numsStr.split(",");
            int[] nums = new int[strS.length];
            for(int i=0;i<nums.length;++i) nums[i] = Integer.parseInt(strS[i]);
            S1.moveZeroes(nums);
            System.out.println("Res: ");
            System.out.print("[");
            for(int i : nums) System.out.print(i+",");
            System.out.println("]");
        }
    }
    public static void swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
        return;
    }
    private static class Solution {
        public void moveZeroes(int[] nums) {
            /*
                                   s
                Input: nums = [1,3,12,0,0]
                                        f
                Output: [1,3,12,0,0]
             */
            int s = 0, f = 0;
            for(;f<nums.length;++f,++s){
                if(nums[s]==0){
                    while(f<nums.length&&nums[f]==0) ++f;
                    if(f>=nums.length){
                        break;
                    }
                    swap(nums, s, f);
                }
            }
        }
    }
}
