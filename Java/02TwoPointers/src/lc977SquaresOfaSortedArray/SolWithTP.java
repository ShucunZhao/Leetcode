package lc977SquaresOfaSortedArray;
import java.util.Scanner;

public class SolWithTP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the array with format [x,x,x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                System.out.println("Quit");
                break;
            }
            String numsStr = In.substring(In.indexOf('[')+1, In.indexOf(']'));
            String[] strS = numsStr.split(",");
            int[] nums = new int[strS.length];
            for(int i=0;i<strS.length;++i){
                nums[i] = Integer.parseInt(strS[i]);
            }
            int[] res = S1.sortedSquares(nums);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] sortedSquares(int[] nums){
            /*
            Solution: Something like merge sort
                                 h
                Input: nums =  [-4,-1,0,3,10]
                                           t
                Output: [0,1,9,16,100]
                        tmp: 1
                           h
                In:   [-5,-3,-2,-1]
                                 t
                      [x,x,x,x,25]
                               x
                Out:
             */
            int h=0,t=nums.length-1;
            int[] res = new int[nums.length];
            int x = t;
            for(;h<=t;){
                if(nums[h]*nums[h]>nums[t]*nums[t]){
                    res[x] = nums[h]*nums[h];
                    h++;
                }
                else{
                    res[x] = nums[t]*nums[t];
                    t--;
                }
                x--;
            }
            return res;
        }
    }
}
