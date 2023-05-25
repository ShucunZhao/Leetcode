class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        /*
            We cannot use greedy here beacuse we need to find the range of max rather than only the max value.
            dp[i]: the max subarray sum when in position i.
            dp[i] = max(dp[i-1]+array[i], array[i]);
            
                    l
                    r 
                       i
            [-2,-8,-1,-5,-9]
            dp[0]: -2
            dp[i-1]: -1    
            dp[i]:-1,

        max: -1
        */
        //if(array.size()==1) return array;
        /*
            There is a situation that all element is non-positive, so we deal with this first situation at first.
        */
        vector<int> tmp(array.begin(), array.end());
        sort(tmp.begin(), tmp.end());
        if(tmp[tmp.size()-1]<=0){
            int l=tmp.size()-1;
            while(l>0&&tmp[l-1]==tmp[l]) l--;
            return vector<int>(tmp.begin()+l, tmp.end());
        }
        /*
            Use dp to deal with the other cases:
        */
        vector<int> dp(array.size());
        dp[0] = array[0];
        int max = array[0];
        int l=0,r=0;
        for(int i=1;i<array.size();i++){
            if(dp[i-1]+array[i]<array[i]){
                l = i;
                r = i;
                max = array[i];
                dp[i] = array[i];
                continue;
            }
            dp[i] = dp[i-1]+array[i];
            if(max<=dp[i]){
                r = i;
                max = dp[i];
            }
        }
        /*
        cout<<"l:"<<l<<endl;
        cout<<"r:"<<r<<endl;
        */
        return vector<int>(array.begin()+l, array.begin()+r+1);
    }
};