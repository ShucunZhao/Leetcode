class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size()<2) return 1;
        // vector<int> hash(2001, 0);
        int hash[2001] = {0};
        for(int i : arr){
            hash[i+1000]++;
        }
        bool flag[1001] = {0};
        // sort(hash.begin(), hash.end());
        for(int i=0;i<2001;i++){
            if(hash[i]){
                if(!flag[hash[i]]) flag[hash[i]] = 1;
                else return 0;
            }
        }
        return 1;
    }
};