class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        /*
                    [6,2,3,4,5]
            we draw the representation table, 
            A is the nums array and B is result array:
            We set each position B to 1 that can meet the require of answer,

                    A0  A1  A2  A3  A4
               B0   1   2   3   4   5
               B1   6   1   3   4   5
               B2   6   2   1   4   5
               B3   6   2   3   1   5   
               B4   6   2   3   4   1
            left-down:
                    A0  A1  A2  A3  A4
               B0   1   x   x   x   1*5*4*3*2
               B1   2   1   x   x   2*5*4*3
               B2   12  x   1   x   12*5*4
               B3   36  x   x   1   36*5   
               B4   144 x   x   x   1
            calculate right-top:


            So the table is divide by the coner line 1 into right-top part and
            left-down part, so we just need to calculate the left-down part then
            use the right-top part to multiply together to get the final answer.   
        */
        vector<int> B(A.size(), 1);
        for(int i=1;i<B.size();i++){
            B[i] = B[i-1]*A[i-1];
        }
        int tmp = 1;
        for(int j=B.size()-2;j>=0;j--){
            tmp *= A[j+1];
            B[j]*=tmp;
        }
        return B;
    }
};