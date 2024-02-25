package Amazon.Intern.oa20230831FindMinimumInefficiency;

import java.util.Scanner;

public class SolWithJump {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the serverType: ");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            S = S.substring(1, S.length()-1);
            System.out.println("Res: "+S1.findMinimumInefficiency(S));
        }
    }
    private static class Solution{
        public int findMinimumInefficiency(String serverType) {
            /*
                serverType = "??011??0", Output: 2
                With analysis we can know, If the the '?' is in the middle of string 'serverType'.
                When left and right symbol are difference, no matter what symbol we place in the '?'
                to it, there at least has one pair of difference.
                At the same if the the '?' is in the head or tail of string, it can be placed the same
                symbol besides of it.
                In summary, we can ignore the ? directly and then find the total inefficiency.
            */
            StringBuilder sbd = new StringBuilder();
            for(int i=0;i<serverType.length();++i){
                if(serverType.charAt(i)!='?') sbd.append(serverType.charAt(i));
            }
            int ans = 0;
            for(int i=1;i<sbd.length();++i){
                if(sbd.charAt(i)!=sbd.charAt(i-1)) ans++;
            }
            return ans;
        }
    }
}
