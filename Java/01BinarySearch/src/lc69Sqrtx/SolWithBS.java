package lc69Sqrtx;
import java.util.Scanner;

public class SolWithBS {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please input the integer x:");
            String In = scan.nextLine();
            if(In.equals("q")){
                System.out.println("Quit.");
                break;
            }
            int x;
            x = Integer.parseInt(In);
            System.out.println("Res: "+S1.mySqrt(x));
        }

    }
    public static class Solution{
        public int mySqrt(int x){
            /*
                    Input: x = 8, Output: 2
                    i: 0 1 2 3 4 5 6 7 8
                             l
                    x: 0,1,2,3,4,5,6,7,8
                           r
                             m
             */
            long l = 0, r = x;
            while(l<=r){
                long m = l + (r-l)/2;
                if(m*m>x){
                    r = m-1;
                }
                else if(m*m<x){
                    l = m+1;
                }
                else{
                    return (int)m;
                }
            }
            return (int)r;
        }
    }
}
