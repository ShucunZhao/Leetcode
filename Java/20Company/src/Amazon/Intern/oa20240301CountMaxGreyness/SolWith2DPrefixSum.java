package Amazon.Intern.oa20240301CountMaxGreyness;

import java.util.Scanner;

public class SolWith2DPrefixSum {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter pixels with format [xx,xx,xx]:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] Ins = In.split(",");
            for(int i=0;i<Ins.length;++i){
                Ins[i] = Ins[i].replaceAll("\"", "");
                Ins[i] = Ins[i].trim();
            }
            System.out.println("Res: "+S1.getMaxGrayness(Ins));
        }
    }
    private static class Solution{
        public int getMaxGrayness(String[] pixels) {
            /*
                Sol with prefix sum in row and column to count the number of element '1'
                then we can use the length m and length n to minus the '1' number to get '0'.
             */
            int m = pixels.length;
            int n = pixels[0].length();
            int[] rowOnes = new int[m];
            int[] colOnes = new int[n];
            for(int i=0;i<pixels.length;++i){
                for(int j=0;j<pixels[i].length();++j){
                    rowOnes[i]+=pixels[i].charAt(j)-'0';
                    colOnes[j]+=pixels[i].charAt(j)-'0';
                }
            }
            int ans = 0;
            for(int i=0;i<pixels.length;++i){
                for(int j=0;j<pixels[i].length();++j){
                    int tmp = (rowOnes[i]+colOnes[j])-(m-rowOnes[i])-(n-colOnes[j]);
                    ans = Math.max(ans, tmp);
                }
            }
            return ans;
        }
    }
}
