package MorganStanley.Intern.oa20240309findSimilar;
import java.util.*;

/**
 * Similar Numbers
 * Two numbers, without leading zeros, are similar if rearranging the digits gives matching numbers, i.e., numbers with the equal frequency of each digit.
 *
 * For example, the numbers 1100 and 1001 are similar, but 1100 and 0110 are not similar because 0110 has a leading zero.
 *
 * Given two strings that represent long integers a and b, check their similarity. Based on the finding, determine one of the following:
 *
 * lf a and bare similar, find the total number of similar numbers to a.
 *
 * lf a and b are not similar, find the total number of similar numbers to b.
 *
 * Example:
 * if a = 112 and b = 121, they are similar. Count the 3 numbers similar to a: {112, 121,211}.
 * lf a = 11 and b = 223, they are not similar. Count the3 numbers similar to b: {223,232,322}.
 *
 * Function Description:
 * Complete the function findSimilar in the editor below.
 *
 * findSimilar has the following parameter(s):
 * string a: a string representing a long integer
 * string b: a string representing a long integer
 *
 * Returns:
 * int: long integer, the number of integers similar to a or b as required.
 *
 * Constraints
 * 1 ≤ numeric values of a and b ≤ 10^15·
 *
 * The inputs do not contain ambiguous values.Specifically, there will be no leading zeros such as a=002,b=200.
 *
 * public static long findSimilar(String a, String b)
 *
 * Explanation 0:
 * Given a = 1234 and b = 2341, they are similar(equal frequency of all digits). Count the numbers similar to a:
 * {1234,1243,1324,1342,1423,1432,2134,2143,2314,2341,2413,2431,3124,3142,3214,3241,3412,3421,4123,4132,4213,4231,4312,4321} The total number of similar numbers is 24.
 *
 * Explanation 1:
 * Given a = 1100 and b = 1001, they are similar numbers. Count the numbers similar to a:{1100,1010,1001}
 * The total number of similar numbers is 3.
 *
 * Explanation 2:
 * Given a = 1234 and b = 1213, they are not similar numbers. Count the numbers similar to b:
 * {1123, 1132, 1213, 1231,1312,1321,2113,2131,2311,3112,3121,3211}
 * The total number of similar numbers is 12.
 */
public class UnSolve {
}

public class SimilarNumbers {
    public static long findSimilar(String a, String b) {
        if (isSimilar(a, b)) {
            return countSimilar(a);
        } else {
            return countSimilar(b);
        }
    }

    private static boolean isSimilar(String a, String b) {
        int[] freqA = getFrequency(a);
        int[] freqB = getFrequency(b);
        return Arrays.equals(freqA, freqB);
    }

    private static int[] getFrequency(String num) {
        int[] freq = new int[10];
        for (char c : num.toCharArray()) {
            freq[c - '0']++;
        }
        return freq;
    }

    private static long countSimilar(String num) {
        int[] freq = getFrequency(num);
        return factorial(num.length()) / factorialOfFrequencies(freq);
    }

    private static long factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    private static long factorialOfFrequencies(int[] freq) {
        long result = 1;
        for (int f : freq) {
            result *= factorial(f);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(findSimilar("1234", "2341")); // Output: 24
        System.out.println(findSimilar("1100", "1001")); // Output: 3
        System.out.println(findSimilar("1234", "1213")); // Output: 12
    }
}
