package inv01Hetao;
import java.util.Arrays;
import java.util.Scanner;

public class Test {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the nums:");//[x,x,x], [2,3,15,14,2,3,4]
            String In = scan.nextLine();
            In = In.substring(1, In.length()-1);
            String[] Ins = In.split(",");
            int[] nums = new int[Ins.length];
            for(int i=0;i<Ins.length;++i){
                nums[i] = Integer.parseInt(Ins[i]);
            }
            System.out.println("Enter the target:");//x, 15
            String T = scan.nextLine();
            int target = Integer.parseInt(T);
            System.out.println(S1.binarySearch(nums, target));
        }
    }
    private static class Solution{
        public int binarySearch(int[] nums, int target){
            Arrays.sort(nums);
            int l = 0;
            int r = nums.length-1;
            while(l<=r){
                int m = (r-l)/2 +l;
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
