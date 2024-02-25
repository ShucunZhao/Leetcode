package Amazon.Intern.oa20240110GetMinCostData;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SolWithHashArray {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true) {
            System.out.println("Enter data:");
            String In = scan.nextLine();
            if (In.equals("q")) break;
            In = In.substring(1, In.length() - 1);
            System.out.println("Res: " + S1.getMinCostData(In));
        }
    }
    private static class Solution{
        public String getMinCostData(String data) {
            /*
                Sol: When meet the '?' char, we need to find the minChar and minCnt by:
                    Step1: Do the steps below from a to z because the optimal result will be around a-z:
                        if the cnt of current char c is smaller than minCnt: update the minChar into c and update the minCnt to count(c)
                           else if the cnt of the current char c is equal to minCnt,
                                    determine if the lexico-order of c is smaller than minChar:
                                            if yes: update the minChar to c and update the minCnt to count(c)
                    Step2: Replace the minChar to original data and add one to the HashMap counter.
                      i
                data: a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,?
            */
            HashMap<Character, Integer> ms = new HashMap<>();
            char[] chars = data.toCharArray();
            for(int i=0;i<chars.length;++i){
                if(chars[i]=='?'){
                    char minChar = 'a';
                    int minCnt = ms.getOrDefault(minChar, 0);
                    for(char c='a';c<='z';++c){
                        if(ms.getOrDefault(c,0)<minCnt||(ms.getOrDefault(c,0)==minCnt&&c<minChar)){
                            minChar = c;
                            minCnt = ms.getOrDefault(minChar, 0);
                        }
                    }
                    chars[i] = minChar;
                    ms.put(chars[i], ms.getOrDefault(chars[i], 0)+1);
                }
                else{
                    ms.put(chars[i], ms.getOrDefault(chars[i],0)+1);
                }
            }
            return new String(chars);
        }
    }
}
