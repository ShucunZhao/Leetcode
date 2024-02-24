package Amazon.Intern.oa20240127RemoveAnagrams;


import java.util.*;

public class SolWithHashSet {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter text list:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            for(int i=0;i<InSet.length;++i){
                InSet[i] = InSet[i].replaceAll("\"", "").trim();
            }
            String[] res = S1.removeAnagram(InSet);
            System.out.print("Res: [");
            for(String s : res) System.out.print(s+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public String[] removeAnagram(String[] textList) {
            HashSet<String> mset = new HashSet<>();
            List<String> ans = new ArrayList<>();
            for(String s : textList){
                char[] chars = s.toCharArray();
                Arrays.sort(chars);
                String sorted = new String(chars);
                if(!mset.contains(sorted)){
                    mset.add(sorted);
                    ans.add(s);
                }
            }
            Collections.sort(ans);
            String[] sAns = new String[ans.size()];
            for(int i=0;i<sAns.length;++i) sAns[i] = ans.get(i);
            return sAns;
        }
    }
}
