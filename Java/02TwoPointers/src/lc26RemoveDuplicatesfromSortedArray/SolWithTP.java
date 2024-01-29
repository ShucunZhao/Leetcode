package lc26RemoveDuplicatesfromSortedArray;

import java.util.HashSet;
import java.util.Scanner;

public class SolWithTP {
    public static void main(String[] args){
        Scanner scan  = new Scanner(System.in);
        Solution S1 = new Solution();
        Solution2 S2 = new Solution2();
        while(true){
            System.out.println("Enter the array with [x,x,x,x] format: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                System.out.println("Quit.");
                break;
            }
            String numsStr = In.substring(In.indexOf('[')+1, In.indexOf(']'));
            String[] numsSet = numsStr.split(",");
            int[] nums = new int[numsSet.length];
            int[] nums2 = new int[numsSet.length];
            for(int i=0;i<numsSet.length;++i){
                nums[i] = Integer.parseInt(numsSet[i]);
                nums2[i] = Integer.parseInt(numsSet[i]);
            }
            System.out.println("Res1: "+S1.removeDuplicates(nums));
            System.out.println("Res2: "+S2.removeDuplicates(nums2));
        }
    }
    private static class Solution2{
        public int removeDuplicates(int[] nums){
            /*           s
                [0,1,2,3,4,2,2,3,3,4]
                                    f
             */
            if(nums.length==1) return 1;
            int s=0,f=1;
            for(;f<nums.length;++f){
                if(nums[f]!=nums[f-1]){
                    nums[s+1] = nums[f];
                    ++s;
                }
            }
            return s+1;
        }
    }
    private static class Solution{
        public int removeDuplicates(int[] nums){
            /*

                                s
                    nums = [0,1,1,1,1,2,2,3,3,4]
                                      f
             */
            HashSet<Integer> hset = new HashSet<Integer>();
            int s=0,f=0;
            for(;f<nums.length;++f){
                if(hset.contains(nums[f])==false){
                    hset.add(nums[f]);
                    swap(nums, s, f);
                    s++;
                }
            }
            return s;
        }
        public void swap(int[] nums, int a, int b){
            int tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }
    }
}
