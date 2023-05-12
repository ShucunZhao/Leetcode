class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0, r = array.size()-1;
        while(l<=r){
            int cur = array[l]+array[r];
            if(cur>sum){
                r--;
            }
            else if(cur<sum){
                l++;
            }
            else{
                return {array[l], array[r]};
            }
        }
        return {};
    }
};