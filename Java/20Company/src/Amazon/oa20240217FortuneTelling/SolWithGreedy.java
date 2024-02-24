//package Amazon.oa20240217FortuneTelling;
//
//import java.util.Arrays;
//import java.util.HashMap;
//import java.util.Map;
//
//public class SolWithGreedy {
//    public static void main(String[] args){
//
//    }
//
//    /**
//     * @Desciption
//     * Fortune Telling Problem:
//     *
//     * Given a collection of n cards. The i-th card (1 ≤ i ≤ n) has a number Ai on its front and a number Bi on its back. At the start, all the cards are facing upwards. He wants to minimize the range of numbers (i.e. the difference between the maximum and minimum values) on the face-up side. He is allowed to flip a maximum of m cards. Flipping a card will transition Bi to the face up side and Ai to the back. Help him find the minimum possible range after using at most m flips.
//     *
//     * Input:
//     *
//     * The first line of the input consists of 2 integers n and m. The next line contains n integers, i-th of which denotes Ai. The next line contains n integers, i-th of which denotes Bi.
//     *
//     * Output:
//     *
//     * Output a single integer, the minimum possible range.
//     *
//     * Example 1:
//     * Input: n = 5, m = 2, A = [1, 2, 17, 16, 9], B = [3, 4, 5, 6, 11]
//     * Output: 8
//     * Explanation:
//     * By flipping card 3 and 4, we get the face up numbers {1, 2, 5, 6, 9}. This makes range=9-1=8.
//     *
//     * Constraints:
//     * 1 <= m <= n
//     * 1 <= Ai, Bi <= 107
//     */
//    private static class Solution{
//        public int minimizeTheRange(int n, int m, int[] A, int[] B) {
//            /*
//                 Sol with greedy:
//                  Input: n = 5, m = 2, A = [1, 2, 17, 16, 9], B = [3, 4, 5, 6, 11]
//                                 absDiff = [2, 2, 12, 10, 2]
//                             sortAbyDiff = [17, 16, 1, 2, 9]
//                              then flip the first m elements to get ans.
//                                    flip = [5, 6, 1, 2, 9], ans = 9-1 = 8.
//             */
//            if (Arrays.compare(A, B) != 0) {
//                Map<Integer,Integer> valuesToChange = new HashMap<>();
//                for (int i = 0; i < n; i++) {
//                    int valueToChange = A[i] - B[i];
//                    valuesToChange.put(i, valueToChange);
//                }
//
//                for (int i = 0; i < m; i++) {
//                    int maxValue = Integer.MIN_VALUE;
//                    int indexToChange = 0;
//
//                    for (int j = 0; j < valuesToChange.size(); j++) {
//                        int value = valuesToChange.get(j);
//
//                        if (value == 0) {
//                            continue;
//                        }
//
//                        if (value == maxValue) {
//                            if (value > 0) {
//                                if (A[j] > A[indexToChange]) {
//                                    indexToChange = j;
//                                    maxValue = value;
//                                }
//                            } else {
//                                if (B[j] < B[indexToChange]) {
//                                    indexToChange = j;
//                                    maxValue = value;
//                                }
//                            }
//                        } else {
//                            maxValue = Math.max(maxValue, value);
//                            if (maxValue == value) {
//                                indexToChange = j;
//                            }
//                        }
//                    }
//
//                    valuesToChange.put(indexToChange, 0);
//                    A[indexToChange] = B[indexToChange];
//                }
//            }
//
//            Arrays.sort(A);
//
//            return A[n - 1] - A[0];
//        }
//    }
//}
