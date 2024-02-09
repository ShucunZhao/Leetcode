package lc438FindAllAnagramsInaString;
import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Scanner;

public class SolWithSW {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please enter string s:");
            String  s = scan.nextLine();
            System.out.println("Please enter string p:");
            String p = scan.nextLine();
            if(s.equals("exit")&&p.equals("exit")){
                break;
            }
            List<Integer> ans = S1.findAnagrams(s,p);
            System.out.print("Res: [");
            for(int i=0;i<ans.size();i++){
                System.out.print(ans.get(i)+",");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public List<Integer> findAnagrams(String s, String p) {
            /*
                              l
                Input: s = "cbaebabacd", p = "abc"  Output: [0,6]
                                r
                  mapS:  c:1 b:1 a:1    curLen: 3
                  lenS:  2                     ans: 0,
                                              mapP:  a:1, b:1, c:1
                                               lenP:    3
                ----------------------------------------
                      l
                s = "baa"   p = "aa"
                       r
                   ms:  b:1 a:2 curLen:2
                   mp: a:2
             */
            HashMap<Character, Integer> mapP = new HashMap<>();
            HashMap<Character, Integer> mapS = new HashMap<>();
            for(int i=0;i<p.length();++i){
                char c = p.charAt(i);
                if(mapP.containsKey(c)){
                    mapP.put(c, mapP.get(c)+1);
                }
                else{
                    mapP.put(c, 1);
                }
            }
            int sizeP = p.length();
            int lenP = mapP.size();
            int lenS = 0;
            int curLen = 0;
            int l=0, r=0;
            List<Integer> ans = new ArrayList<>();
            while(r<s.length()){
                char cR = s.charAt(r);
                if (mapS.containsKey(cR)) {
                    mapS.put(cR, mapS.get(cR) + 1);
                } else {
                    mapS.put(cR, 1);
                }
                curLen++;
                if(mapS.get(cR).equals(mapP.get(cR))){
                    lenS++;
                }
                if(curLen==sizeP){
                    if(lenS==lenP) {
                        ans.add(l);
                    }
                    char cL = s.charAt(l);
                    if(mapP.containsKey(cL)&&mapS.get(cL).equals(mapP.get(cL))){
                        lenS--;
                    }
                    mapS.put(cL, mapS.get(cL)-1);
                    l++;
                    curLen--;
                }
                r++;
            }
            return ans;
        }
    }
}
