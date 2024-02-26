package Amazon.Intern.oa20231215WarehouseDistribution;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @Description
 * Warehouse Distribution
 * 🤘 INTERN
 * Amazon has several warehouses that store piles of boxes containing goods to be shipped.
 * In one such warehouse, there are a total of n piles numbered 1, 2, ..... n, where the ith pile has boxes[i] number of boxes. To have an even distribution of boxes, the caretaker can do the following operation any number of times (possibly zero):
 * • Choose two distinct piles, i and j(1 <= i, j <= n), such that boxes[i]> 0.
 * • Remove one bcx from pile / and place it on pile j. More formally, increment boxes[j] by 1 and decrement boxes[i] by 1.
 * For even distribution, the caretaker wishes to minimize the difference between the maximum and the minimum number of boxes in the piles. Call the minimum difference achievable d. The goal is to find the minimum number of operations required to achieve the difference d.
 *
 * Example 1:
 * Input:  boxes = [5, 5, 8, 7]
 * Output: 2
 * Explanation:
 * Consider the number of piles to be n = 4 and the boxes in them are boxes = [5, 5, 8, 7]. The minimum possible difference that can be achieved is 1 by transforming the piles into [6, 6, 7, 6]. Hence the answer is 2.
 *
 * Example 2:
 * Input:  boxes = [2, 4, 1]
 * Output: 1
 *
 * Example 3:
 * Input:  boxes = [4, 4, 4, 4, 4]
 * Output: 0
 *
 * Constraints:
 * 1 <= n <= 105
 * 1 <= boxes[i] <= 109
 */
public class SolWithTwoHeaps {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the boxes: ");
            String B = scan.nextLine();
            if(B.equals("q")) break;
            B = B.substring(1, B.length()-1);
            String[] Bs = B.split(",");
            int[] boxes = new int[Bs.length];
            for(int i=0;i<boxes.length;++i) boxes[i] = Integer.parseInt(Bs[i].trim());
            System.out.println("Res: "+S1.findMinimumOperations(boxes));
        }
    }
    private static class Solution{
        class myCmp implements Comparator<Integer> {
            @Override
            public int compare(Integer a, Integer b){
                return Integer.compare(b, a);
            }
        }
        public long findMinimumOperations(int[] boxes) {
            /*
                Similar to leetcode 295, when the difference of max and min elements equal
                or smaller than one, the boxes is even distribution.
            */
            PriorityQueue<Integer> minHeap = new PriorityQueue<>();
            PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new myCmp());
            for(int i : boxes){
                minHeap.add(i);
                maxHeap.add(i);
            }
            long ans = 0;
            while(true){
                int minV = minHeap.poll();
                int maxV = maxHeap.poll();
                if(maxV-minV<=1){
                    break;
                }
                minHeap.add(minV+1);
                maxHeap.add(maxV-1);
                ans++;
            }
            return ans;
        }
    }
}
