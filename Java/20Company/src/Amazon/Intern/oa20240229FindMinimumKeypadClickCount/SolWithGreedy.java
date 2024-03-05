package Amazon.Intern.oa20240229FindMinimumKeypadClickCount;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

/**
 * Find Minimum Keypad Click Count (AMZ CN)
 * 🤘 INTERN
 * A recently launched supplemental typing keypad gained significant popularity on Amazon Shopping due to its flexibility.
 *
 * This keypad can be connected to any electronic device and has 9 buttons, where each button can have up to 3 lowercase English letters. The buyer has the freedom to choose which letters to place on a button while ensuring that the arrangement is valid. A keypad design is said to be valid if:
 *
 * All 26 letters of the English alphabet exist on the keypad.
 * Each letter is mapped to exactly one button.
 * A button has at most 3 letters mapped to it.
 * Examples of some valid keypad designs are:
 *
 *  1   2   3
 * abc def ghi
 *  4   5   6
 * jkl mno pqr
 *  7   8   9
 * stu vwx yz
 *
 *  1   2   3
 * ajs bot cpu
 *  4   5   6
 * dkv hmz gl
 *  7   8   9
 * enw fqx iry
 *
 * In the left keypad, "hello" can be typed using the following button presses:
 *
 * [3] twice (prints 'h')
 * [2] twice (prints 'e')
 * [4] thrice (prints 'l')
 * [4] thrice (prints 'l')
 * [5] thrice (prints 'o')
 * Thus, total num of button presses = 2 + 2 + 3 + 3 + 3 = 13.
 *
 * In the right keypad, "hello" can be typed using the following button presses:
 *
 * [5] once (prints 'h')
 * [7] once (prints 'e')
 * [6] twice (prints 'l')
 * [6] twice (prints 'l')
 * [2] twice (prints 'o')
 * Thus, the total num of button presses = 1 + 1 + 2 + 2 + 2 = 8.
 *
 * The keypad click count is defined as the number of button presses required to print a given string. In order to send messages faster, customers tend to seek the keypad design in such a way that the keypad click count is minimized while maintaining its validity.
 *
 * Given a string letters consisting of lowercase English letters only, find the minimum Keypad click count.
 *
 * Example 1:
 * Input:  letters = "abacadefghibj"
 * Output: 14
 * Explanation:
 * One of the optimal keypad designs to minimize the keypad click count is:
 *  1   2   3
 * ajs bkt clu
 *  4   5   6
 * dmv enw fox
 *  7   8  9
 * gpy hqz ir
 *
 * Here, the keypad click count = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 2 = 14.
 */
public class SolWithGreedy {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        Solution S2 = new Solution();
        while(true){
            System.out.println("Enter letters:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            System.out.println("Res1: "+S1.findMinimumKeypadClickCount(In));
            System.out.println("Res2: "+S2.findMinimumKeypadClickCount(In));
        }
    }
    private static class Solution{
        public int findMinimumKeypadClickCount(String letters) {
            //Step1: count all character frequency
            int[] freq = new int[26];
            for(int i=0;i<letters.length();++i){
                freq[letters.charAt(i)-'a']++;
            }

            //Step2: sort the char sets array by frequency with a descending order
            Integer[] indexSet = new Integer[26];
            for(int i=0;i<26;++i) indexSet[i] = i;
            Arrays.sort(indexSet, (a, b) -> freq[b] - freq[a]);

            //Step3: arrange the char to key
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                int tmp = 1 + i / 9;
                ans += tmp * freq[indexSet[i]];
            }

            return ans;
        }
    }
    private static class Solution2{
        public int findMinimumKeypadClickCount(String letters) {
            //Step1: count all character frequency
            int[] freq = new int[26];
            for(int i=0;i<letters.length();++i){
                freq[letters.charAt(i)-'a']++;
            }

            //Step2: Use a priority queue(max heap) to save the most frequency char
            Queue<int[]> Q = new PriorityQueue<>((a,b)->b[1]-a[1]);
            for(int i=0;i<26;++i){
                if(freq[i]!=0){
                    Q.add(new int[]{i, freq[i]});
                }
            }

            /*
                Step3: arrange the char to key with three times, the first time use the first key(total 9),
                       the second time use the second key(total 9), the last use the third key(total 9).
             */
            int ans = 0;
            int size = Q.size();
            for(int i=0;i<9&&i<size;++i){
                ans += Q.poll()[1]*1;
            }
            size-=9;
            for(int i=0;i<9&&i<size;++i){
                ans += Q.poll()[1]*2;
            }
            size-=9;
            for(int i=0;i<9&&i<size;++i){
                ans += Q.poll()[1]*3;
            }
            return ans;
        }
    }
}
