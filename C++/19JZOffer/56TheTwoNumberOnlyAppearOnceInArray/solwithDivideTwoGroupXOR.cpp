class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        /*
            First, we need to find the XOR result of two appear once number.
            Second, find out which bit they different in binary form.
            Third, according to the bit position to do the XOR by two group,
                   one bit value is 1, another is 0.
        */
        int xorBoth = 0;
        for(int i : array){
            xorBoth^=i;
        }
        int bit = 0;
        while(((xorBoth>>bit)&1)!=1) bit++;
        int num1 = 0, num2 = 0;
        for(int i : array){
            if(((i>>bit)&1)==1){
                num1^=i;
            }
            else{
                num2^=i;
            }
        }
        if(num1>num2) return {num2,num1};
        return {num1,num2};
    }
};