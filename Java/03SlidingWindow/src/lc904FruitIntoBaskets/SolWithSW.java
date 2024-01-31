package lc904FruitIntoBaskets;
import java.util.HashMap;
import java.util.Scanner;

public class SolWithSW {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the fruits array with [x,x,x] format: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                System.out.println("Quit.");
                break;
            }
            String numsStr = numsIn.substring(numsIn.indexOf('[')+1, numsIn.indexOf(']'));
            String[] strS = numsStr.split(",");
            int[] nums = new int [strS.length];
            for(int i=0;i<strS.length;++i) nums[i] = Integer.parseInt(strS[i]);
            System.out.println("Res: "+S1.totalFruit(nums));
        }
    }
    private static class Solution {
        public int totalFruit(int[] fruits) {
            /*
                                  l
                 Input: fruits = [0,1,2]     Output: 4
                                      r
                 map: (0,1),(1,1),(2,1)
                 res: 2
             */
            if(fruits.length<3) return fruits.length;
            int l=0, r=0;
            int res = 0;
            HashMap<Integer, Integer> hmap = new HashMap<>();
            while(r<fruits.length){
                if(hmap.containsKey(fruits[r])){
                    hmap.put(fruits[r], hmap.get(fruits[r])+1);
                }
                else{
                    hmap.put(fruits[r], 1);
                }
                if(hmap.size()<=2){
                    res = Math.max(res, r-l+1);
                }
                while(hmap.size()>2){
                    hmap.put(fruits[l], hmap.get(fruits[l])-1);
                    if(hmap.get(fruits[l])==0){
                        hmap.remove(fruits[l]);
                    }
                    l++;
                    if(hmap.size()<=2){
                        res = Math.max(res, r-l+1);
                    }

                }
                r++;
            }
            return res;
        }
    }
}
