package lc347TopKFrequentElements;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Scanner;

public class SolWithBigTopHeap {
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
            int k = Integer.parseInt(K);
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] nums = new int[InSet.length];
            for(int i=0;i<nums.length;++i) nums[i] = Integer.parseInt(InSet[i]);
            int[] res = S1.topKFrequent(nums, k);
            System.out.println("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        private class Cmp implements Comparator<Integer> {
            private final HashMap<Integer, Integer> ms;
            Cmp(HashMap<Integer, Integer> In){
                this.ms = In;
            }

            @Override
            public int compare(Integer k1, Integer k2) {
                Integer val1 = ms.get(k1);
                Integer val2 = ms.get(k2);
                return val2.compareTo(val1);
            }
        }
        public int[] topKFrequent(int[] nums, int k) {
            HashMap<Integer, Integer> ms = new HashMap<>();
            for(int i : nums){
                ms.put(i, ms.getOrDefault(i,0)+1);
            }
            Cmp cmp = new Cmp(ms);
            PriorityQueue<Integer> pq = new PriorityQueue<>(cmp);
            pq.addAll(ms.keySet());
            int[] ans = new int[k];
            int i=0;
            while(k-->0){
                ans[i++] = pq.poll();
            }
            return ans;
        }
    }
}
