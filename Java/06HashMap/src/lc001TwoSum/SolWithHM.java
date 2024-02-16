package lc001TwoSum;
import java.util.HashMap;
import java.util.Scanner;

public class SolWithHM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the nums with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            System.out.println("Enter the target:");
            String t = scan.nextLine();
            if(t.equals("q")){
                break;
            }
            int target = Integer.parseInt(t);
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] nums = new int[InSet.length];
            for(int i=0;i<nums.length;++i){
                nums[i] = Integer.parseInt(InSet[i]);
            }
            int[] res = S1.twoSum(nums, target);
            System.out.print("Res: [");
            for(int i=0;i<res.length;++i){
                System.out.print(res[i]+",");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] twoSum(int[] nums, int target) {
            HashMap<Integer, Integer> ms = new HashMap<>();
            for(int i=0;i<nums.length;++i){
                int another = target - nums[i];
                if(ms.containsKey(another)){
                    int index = ms.get(another);
                    if(i!=index){
                        return new int[]{i, index};
                    }
                }
                ms.put(nums[i], i);
            }
            return new int[]{-1,-1};
        }
    }
}
