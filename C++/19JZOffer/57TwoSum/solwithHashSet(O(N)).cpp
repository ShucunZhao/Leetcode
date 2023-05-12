class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        unordered_set<int> mset;
        for(int i : array){
            mset.insert(i);
        }
        for(int i : array){
            if(mset.count(sum-i)){
                return {sum-i, i};
            }
        }
        return {};
    }
};