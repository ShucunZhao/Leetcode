package lc239SlidingWindowMaximum;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class SolWithMonoDeque {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter nums with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            System.out.println("Enter k: ");
            String K = scan.nextLine();
            if(K.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] nums = new int[InSet.length];
            for(int i=0;i<nums.length;++i) nums[i] = Integer.parseInt(InSet[i]);
            int k = Integer.parseInt(K);
            int[] res = S1.maxSlidingWindow(nums,k);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] maxSlidingWindow(int[] nums, int k) {
            /*
                                     i
                Input: nums = [1,3,1,2,0,5], k = 3, Output: [3,3,2,5]
                               0 1 2 3 4 5

               Out ______ In
                   1,2
                   3,1
                   ______
                ans:3,
             */
            Deque<Integer> Q = new LinkedList<>();
            List<Integer> ans = new ArrayList<>();
            for(int i=0;i<k;++i){
                while(!Q.isEmpty()&&nums[i]>nums[Q.getLast()]){
                    Q.pollLast();
                }
                Q.add(i);
            }
            ans.add(nums[Q.getFirst()]);//3,
            for(int i=k;i<nums.length;++i){
                if(i-Q.getFirst()>=k){
                    Q.pop();
                }
                while(!Q.isEmpty()&&nums[i]>nums[Q.getLast()]){
                    Q.pollLast();
                }
                Q.add(i);
                ans.add(nums[Q.getFirst()]);
            }
            int[] res = new int[ans.size()];
            int i=0;
            for(Integer I : ans){
                res[i++] = I;
            }
            return res;
        }
    }
}
