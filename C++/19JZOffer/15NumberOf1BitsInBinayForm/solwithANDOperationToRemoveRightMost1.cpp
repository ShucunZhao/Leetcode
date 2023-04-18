class Solution {
public:
     int  NumberOf1(int n) {
         /*
            32 bits binary representation:
                The first position is signed, and negative's complementary code is the invert code plus 1.
            10:
               0000 0000 0000 0000 0000 0000 0000 1010(last four bits)
            -1:
               1111 1111 1111 1111 1111 1111 1111 1111(last four bits)
         */
         int ans = 0;
         while(n){
            ans++;
            n&=(n-1);
         }
         return ans;
     }
};