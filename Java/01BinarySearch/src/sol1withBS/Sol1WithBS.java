package sol1withBS;

import java.util.Scanner;

public class Sol1WithBS {
    public static void main(String[] args){
        Solution S1 = new Solution();
        Scanner scan = new Scanner(System.in);
        while(true) {
            System.out.println("Enter esc to quit.");
            String userInput = scan.nextLine();
            if(userInput.equals("q")){
                break;
            }
            else{
                System.out.println("Please enter the array with format: \"nums = [x,x,x,x]\": ");
                String arrayIn = scan.nextLine();
                System.out.println("Please enter the target number: ");
                int target = scan.nextInt();
                int head = arrayIn.indexOf('[');
                int tail = arrayIn.indexOf(']');
//        System.out.println("Head: "+head+", tail: "+tail);
                String arrayStr = arrayIn.substring(head + 1, tail);
//        System.out.println(arrayStr);
                String[] arraySet = arrayStr.split(",");
                int[] array = new int[arraySet.length];
                for (int i = 0; i < arraySet.length; ++i) {
                    array[i] = Integer.parseInt(arraySet[i]);
//            System.out.println(array[i]);
                }
                System.out.println(S1.search(array, target));
            }
        }
    }
    private static class Solution{
        public int search(int[] nums, int target){
            int l=0, r = nums.length - 1;
            int m = 0;
            while(l<=r){
                m = l+(r-l)/2;
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
            return -1;
        }
    }
}
