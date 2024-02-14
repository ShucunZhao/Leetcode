package lc242ValidAnagram;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SolWithHM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            System.out.println("Enter string t: ");
            String t = scan.nextLine();
            if(s.equals("q")&&t.equals("q")){
                break;
            }
            System.out.println("Result: "+S1.isAnagram(s,t));
        }
    }
    private static class Solution{
        public boolean isAnagram(String s, String t) {
            if(s.length()!=t.length()) return false;
            HashMap<Character, Integer> ms = new HashMap<>();
            HashMap<Character, Integer> mt = new HashMap<>();
            for(int i=0;i<s.length();++i){
                ms.put(s.charAt(i), ms.getOrDefault(s.charAt(i), 0)+1);
                mt.put(t.charAt(i), mt.getOrDefault(t.charAt(i), 0)+1);
            }
            if(ms.size()!=mt.size()) return false;
            for(Map.Entry<Character, Integer> entry : ms.entrySet()){
                Character key = entry.getKey();
                if(!ms.getOrDefault(key, 0).equals(mt.getOrDefault(key,0))){
                    return false;
                }
            }
            return true;
        }
    }
}
