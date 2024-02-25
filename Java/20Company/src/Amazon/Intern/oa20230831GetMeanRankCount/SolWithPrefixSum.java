package Amazon.Intern.oa20230831GetMeanRankCount;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SolWithPrefixSum {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the rank: ");
            String R = scan.nextLine();
            if(R.equals("q")) break;
            R = R.substring(1, R.length()-1);
            String[] Rs = R.split(",");
            int[] rank = new int[Rs.length];
            for(int i=0;i<rank.length;++i) rank[i] = Integer.parseInt(Rs[i].trim());
            int[] res = S1.getMeanRankCount(rank);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] getMeanRankCount(int[] rank) {
            int n = rank.length;
            int[] count = new int[n];
            HashMap<Integer, Integer> averageCount;
            long sum;

            for (int i = 0; i < n; i++) {
                averageCount = new HashMap<>();
                sum = 0;

                for (int j = i; j < n; j++) {
                    sum += rank[j];
                    int length = j - i + 1;

                    // Only consider cases where the total sum is an integer multiple of the subarray length
                    if (sum % length == 0) {
                        int average = (int) (sum / length);

                        // Only consider averages that are within the possible range
                        if (average > 0 && average <= n) {
                            averageCount.put(average, averageCount.getOrDefault(average, 0) + 1);

                            // This average is valid, we found another subarray for it
                            count[average - 1]++;
                        }
                    }
                }
            }

            return count;
            /*
            int n = rank.length;
            int[] count = new int[n];
            long[] prefixSum = new long[n + 1];

            // Calculate prefix sums
            for (int i = 0; i < n; i++) {
                prefixSum[i + 1] = prefixSum[i] + rank[i];
            }

            // Iterate over all x from 1 to n
            for (int x = 1; x <= n; x++) {
                // Check for all subarray lengths
                for (int length = 1; length <= n; length++) {
                    long requiredSum = (long) x * length;
                    // Check for all subarrays of the current length
                    for (int start = 0; start <= n - length; start++) {
                        long subarraySum = prefixSum[start + length] - prefixSum[start];
                        if (subarraySum == requiredSum) {
                            count[x - 1]++;
                        }
                    }
                }
            }

            return count;
             */
        }
    }
}
