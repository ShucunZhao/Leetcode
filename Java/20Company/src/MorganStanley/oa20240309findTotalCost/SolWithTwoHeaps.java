package MorganStanley.oa20240309findTotalCost;
import java.util.PriorityQueue;

/**
 * Array Reduction 3
 * Given an array arr of n integers, a sequence of n-1 operations must be performed on the array.
 *
 * In each operation,
 * ·Remove the minimum and maximum elements from the current array and add their sum back to the array.
 * .The cost of an operation, cost =
 * ceil((minimum_element + maximum_element) /(maximum_element-minimum_element +1)) .
 *
 * Find the total cost to reduce the array to a single element.
 *
 * Example：
 * Given arr = [2, 3, 4, 5,7].
 * The possible sequence of operations are:
 *
 * Choose 2 and 7, the cost = ceil[(2 +7) /(7- 2 +1)]= ceil[9 / 6] = 2，Remove 2 and 7, append 9, arr = [3, 4,5, 9], total_cost= 2.
 *
 * Choose 3 and 9, the cost = ceil[(3 + 9) / (9 - 3 + 1)] = ceil[12 / 7] = 2, arr = [4, 5, 12], total_cost= 2+2=4.
 *
 * Choose 4 and 12, the cost = ceil[(4 +12) /(12-4+1)]=ceil[16/9]= 2, arr = [5,16], total_cost=4+2=
 *
 * Choose 5 and 16, the cost = ceil[(5+16)/(16-5+1)] = ceil[21/ 12]= 2, arr= [21], total_cost=6+2=
 *
 * Return the total cost, 8.
 *
 * Function Description：
 *
 * Complete the function findTotalCost in the editor below.
 *
 * findTotalCost has the following parameter: int arr[n]: the array to be reduced
 *
 * Returns：
 * int: the total cost to reduce the array to 1 element
 *
 * Constraints：
 * 2≤n≤2*10^5
 * 1 ≤arr[i]≤10^6
 */
public class SolWithTwoHeaps {
}

class Solution {
    public int findTotalCost(int[] arr) {
        int n = arr.length;
        int totalCost = 0;

        // 创建两个优先队列，一个用于存储最小值，一个用于存储最大值
        PriorityQueue<Integer> minPQ = new PriorityQueue<>();
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>((a, b) -> b - a);

        // 将数组元素添加到优先队列中
        for (int num : arr) {
            minPQ.offer(num);
            maxPQ.offer(num);
        }

        while (n > 1) {
            int minElement = minPQ.poll();
            int maxElement = maxPQ.poll();

            // 计算当前操作的代价
            int cost = (int) Math.ceil((double) (minElement + maxElement) / (maxElement - minElement + 1));
            totalCost += cost;

            // 将最小值和最大值的和添加回优先队列
            int sum = minElement + maxElement;
            minPQ.offer(sum);
            maxPQ.offer(sum);

            n--;
        }

        return totalCost;
    }
}