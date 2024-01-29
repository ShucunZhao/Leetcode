package lc367ValidPerfectSquare;
import java.util.Scanner;

public class SolWithBS {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the integer: ");
            int num;
            String In = scan.nextLine();
            if(In.equals("q")){
                System.out.println("Quit.");
                break;
            }
            num = Integer.parseInt(In);
            System.out.println("Result: "+S1.isPerfectSquare(num));
        }
    }
    private static class Solution{
        public boolean isPerfectSquare(int num){
            int l=0, r=num;
            while(l<=r){
                long m = l+(r-l)/2;
                if(m*m>num){
                    r = (int)m-1;
                }
                else if(m*m<num){
                    l = (int)m+1;
                }
                else{
                    return true;
                }
            }
            return false;
        }
    }
}
