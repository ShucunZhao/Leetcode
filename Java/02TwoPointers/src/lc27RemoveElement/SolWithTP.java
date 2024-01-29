package lc27RemoveElement;
import java.util.Scanner;

public class SolWithTP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution2 S2 = new Solution2();
        while(true){
            System.out.println("Enter the array with [x,x,x,x] format: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                System.out.println("Quit");
                break;
            }
            System.out.println("Enter the val: ");
            int val;
            val = Integer.parseInt(scan.nextLine());
            String numsStr = numsIn.substring(numsIn.indexOf('[')+1, numsIn.indexOf(']'));
            String[] numsSet = numsStr.split(",");
            int[] nums = new int[numsSet.length];
            for(int i=0;i<numsSet.length;++i){
                nums[i] = Integer.parseInt(numsSet[i]);
            }
            System.out.println("Res: "+S2.removeElement(nums, val));
        }

    }
    private static class Solution2{
        public int removeElement(int[] nums, int val){
                /*               s
                Input: nums = [0,1,2,2,3,0,4,2], val = 2
                               f
                 */
            int s=0,f=0;
            for(;f<nums.length;++f){
                if(nums[f]!=val){
                    swap(nums, f, s);
                    ++s;
                }
            }
            return s;
        }
    }
    public static void swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    private static class  Solution{
        public int removeElement(int[] nums, int val){
            /*
                                         j
                                     i
            Input: nums = [0,1,3,0,4,2,2,2], val = 2
            Output: 2, nums = [2,2,_,_]
         */
            int i=0,j=0;
            for(;j<nums.length;){
                if(nums[i]==val){
                    while(j<nums.length&&nums[j]==val){
                        ++j;
                    }
                    if(j>=nums.length){
                        break;
                    }
                    swap(nums, i, j);
                }
                ++i;
                ++j;
            }
            return i;
        }
    }
}
