class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        if(n==0) return {};
        // write code here
        /*
        //Sol1:
        int maxN = 0;
        while(n--){
            maxN = maxN*10 + 9;
        }
        */
        //Sol2:
        int maxN = pow(10,n)-1;
        vector<int> ans;
        for(int i=1;i<=maxN;i++){
            ans.push_back(i);
        }
        return ans;
    }
};