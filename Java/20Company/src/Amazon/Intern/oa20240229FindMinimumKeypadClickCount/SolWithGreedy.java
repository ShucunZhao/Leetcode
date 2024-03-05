package Amazon.Intern.oa20240229FindMinimumKeypadClickCount;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

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
