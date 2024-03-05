package Amazon.Intern.oa20240215SortProductCodes;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Sort Product Codes
 * Amazon has millions of products sold on its e-commerce website, and each product is identified by its product code.
 *
 * Given an array of n productCodes and order, a string that represents the precedence of characters, sort the productCodes in lexicographically increasing order per the precedence.
 *
 * Note: Lexicographical order is defined in the following way. When we compare strings s and t, first we find the leftmost position with differing characters: sl and tl. If there is no such position (i.e. s is a prefix of t or vice versa) the shortest string is less. Otherwise, we compare characters sl and t[i] according to their order in the given precedence order.
 *
 * Function Description
 *
 * Complete the function sortProductCodes in the editor below. sortProductCodes has the following parameter(s):
 *
 * string order: the new precedence order string
 * productCodes[n]: the array to sort
 * Returns
 *
 * string[n]: the productCodes array in sorted order
 * Example 1:
 * Input:  order = "abcdefghijklmnopqrstuvwxyz", productCodes = ["adc", "abc"]
 * Output: ["abc", "adc"]
 * Explanation:
 *  Consider the strings "adc" and "abc", the first point of difference is at position 1 (assuming start index is 0), and 'd'>'b' according to the given precedence order.
 *
 *  Constraints:
 * 1 ≤ n ≤ 5000
 * 1 ≤ length(productCodes[i]) ≤ 100
 * length(order) = 26
 * order and all productCodes[i] contain lowercase English letters only.
 */
public class SolWithCustomSort {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string order:");
            String order = scan.nextLine();
            if(order.equals("q")) break;
            order = order.substring(1, order.length()-1);
            System.out.println("Enter productCodes:");
            String PC = scan.nextLine();
            if(PC.equals("q")) break;
            PC = PC.substring(1, PC.length()-1);
            String[] productCodes = PC.split(",");
            for(int i=0;i<productCodes.length;++i){
                productCodes[i] = productCodes[i].replaceAll("\"", "");
                productCodes[i] = productCodes[i].trim();
            }
            String[] res = S1.sortProductCodes(order,productCodes);
            System.out.print("[");
            for(int i=0;i<res.length;++i){
                System.out.print(res[i]+",");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public String[] sortProductCodes(String order, String[] productCodes) {
            //Step1: create a mapper to map all char according to their order in string order:
            int[] indexMap = new int[26];
            for (int i = 0; i < order.length(); i++) {
                indexMap[order.charAt(i) - 'a'] = i;
            }
            //Step2: Create a comparator with the new priority level we define:
            Comparator<String> customComparator = new Comparator<String>() {
                @Override
                public int compare(String str1, String str2) {
                    int len = Math.min(str1.length(), str2.length());
                    for (int i = 0; i < len; i++) {
                        char ch1 = str1.charAt(i);
                        char ch2 = str2.charAt(i);
                        if (ch1 != ch2) {
                            return indexMap[ch1 - 'a'] - indexMap[ch2 - 'a'];
                        }
                    }
                    return str1.length() - str2.length();
                }
            };
            Arrays.sort(productCodes, customComparator);
            return  productCodes;
        }
    }
}
