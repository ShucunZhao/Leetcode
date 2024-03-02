package lc17LetterCombinationsOfAPhoneNumber;

import java.util.HashMap;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithBacktracking {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter digits:");
            String digits = scan.nextLine();
            digits = digits.substring(1, digits.length()-1);
            List<String> res = S1.letterCombinations(digits);
            System.out.print("Res: ");
            for(int i=0;i<res.size();++i){
                System.out.print(res.get(i)+",");
            }
            System.out.println("");
        }
    }

    private static class Solution{
        StringBuilder path = new StringBuilder();
        List<String> ans = new ArrayList<>();
        HashMap<Character, String> ms = new HashMap<>();
        public List<String> letterCombinations(String digits) {
            if(digits.equals("")) return new ArrayList<>();
            for(int i=0;i<digits.length();++i){
                char c = digits.charAt(i);
                if(c=='2') ms.put('2', "abc");
                else if(c=='3') ms.put('3', "def");
                else if(c=='4') ms.put('4', "ghi");
                else if(c=='5') ms.put('5', "jkl");
                else if(c=='6') ms.put('6', "mno");
                else if(c=='7') ms.put('7', "pqrs");
                else if(c=='8') ms.put('8', "tuv");
                else if(c=='9') ms.put('9', "wxyz");
            }
            backtracking(digits, 0);
            return ans;
        }
        public void backtracking(String digits, int start){
            if(start==digits.length()){
                ans.add(new String(path));
                return;
            }
            String s = ms.get(digits.charAt(start));
            for(int i=0;i<s.length();++i){
                path.append(s.charAt(i));
                backtracking(digits, start+1);
                path.deleteCharAt(path.length()-1);
            }
        }
    }
}
