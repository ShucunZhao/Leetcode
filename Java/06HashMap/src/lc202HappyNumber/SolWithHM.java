package lc202HappyNumber;
import java.util.HashSet;
import java.util.Scanner;

public class SolWithHM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the number n: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            int n = Integer.parseInt(In);
            System.out.println("Res: "+S1.isHappy(n));
        }
    }
    private static class Solution{
        public boolean isHappy(int n) {
            /*
                    n = 2
                        4
                        16
                   1+36 37
                   9+49 58
                   25+64 89
                   64+81 145
                   1+16+25 42
                   16+4    20
                   2     4
             */
            HashSet<Integer>  hset = new HashSet<>();
            hset.add(n);
            while(n!=1){
                String s = Integer.toString(n);
                int tmp = 0;
                for(int i=0;i<s.length();++i){
                    int x = (s.charAt(i)-'0');
                    tmp+=x*x;
                }
                if(hset.contains(tmp)){
                    return false;
                }
                n = tmp;
                hset.add(n);
            }
            return true;
        }
    }
}
