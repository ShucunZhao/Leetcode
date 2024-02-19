package lc454FourSumII;
import java.util.HashMap;
import java.util.Scanner;

public class SolWithHM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter nums1 with format [x,x,x]: ");
            String nums1In = scan.nextLine();
            if(nums1In.equals("q")){
                break;
            }
            System.out.println("Enter nums2 with format [x,x,x]: ");
            String nums2In = scan.nextLine();
            if(nums2In.equals("q")){
                break;
            }
            System.out.println("Enter nums3 with format [x,x,x]: ");
            String nums3In = scan.nextLine();
            if(nums3In.equals("q")){
                break;
            }
            System.out.println("Enter nums4 with format [x,x,x]: ");
            String nums4In = scan.nextLine();
            if(nums4In.equals("q")){
                break;
            }
            String[] strs = new String[4];
            strs[0] = nums1In;
            strs[1] = nums2In;
            strs[2] = nums3In;
            strs[3] = nums4In;
            String[][] numsSets = new String[4][];
            int[][] nums = new int[4][];
            for(int i=0;i<4;++i){
                strs[i] = strs[i].substring(1, strs[i].length()-1);
                numsSets[i] = strs[i].split(",");
                nums[i] = new int[numsSets[i].length];
                for(int j=0;j<nums[i].length;++j){
                    nums[i][j] = Integer.parseInt(numsSets[i][j]);
                }
            }
            System.out.println("Res: "+S1.fourSumCount(nums[0],nums[1],nums[2],nums[3]));
        }

    }
    private static class Solution{
        public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
            /*
                    0 <= i, j, k, l < n
                    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
                    nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
             */
//            HashMap<Long, Integer> ms = new HashMap<>();
//            for(int i=0;i<nums1.length;++i){
//                ms.put((long)nums1[i], ms.getOrDefault((long)nums1[i],0)+1);
//            }
            //One hashmap store one nums is not enough, we need to use a upgraded version that using hm to save sum of two arrays.
            HashMap<Long, Integer> ms = new HashMap<>();
            for(int i : nums1){
                for(int j : nums2){
                    ms.put((long)(i+j), ms.getOrDefault((long)(i+j), 0)+1);
                }
            }
            int ans = 0;
            for(int k=0;k<nums3.length;++k){
                for(int l=0;l<nums4.length;++l){
                    long tmp = -nums3[k]-nums4[l];
                    if(ms.containsKey(tmp)){
                        ans+=ms.get(tmp);
                    }
                }
            }
            return ans;
        }
    }
}
