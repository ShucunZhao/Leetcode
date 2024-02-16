package lc49GroupAnagrams;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;

public class SolWithHM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the strings with format [\"xx\",\"xx\"]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
                In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            for(String str : InSet){
                str = str.substring(1, str.length()-1);
            }
            List<List<String> > res = S1.groupAnagrams(InSet);
            System.out.print("Res: [");
            for(List<String> listSet : res){
                System.out.print("[");
                for(String s : listSet){
                    System.out.print(s+",");
                }
                System.out.print("],");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public List<List<String>> groupAnagrams(String[] strs) {
            HashMap<String, List<String> > ms = new HashMap<>();
            for(String str : strs){
                char[] tmp = str.toCharArray();
                Arrays.sort(tmp);
                // We cannot use char[] as hash key because char[] with same permutation has different hash code which would be considered as different key.
                // And we cannot use null as default key which will make null.add error, we need to use new ArrayList<String> instead.
                //ms.getOrDefault(tmp,null).add(str);
                String sortedStr = new String(tmp);
                if(!ms.containsKey(sortedStr)){
                    ms.put(sortedStr, new ArrayList<String>());
                }
                ms.get(sortedStr).add(str);
            }
            List<List<String> > ans = new ArrayList<List<String> >();
            for(Map.Entry<String, List<String>> entry : ms.entrySet()){
                ans.add(entry.getValue());
            }
            return ans;
        }
    }
}
