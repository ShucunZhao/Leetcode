class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int N = 2001;
        int save[N] = {0};
        int buff = 1000;
        for(int i : arr){
            save[i+buff]++;
        }
        unordered_set<int> cntSet;
        for(int i=0;i<N;i++){
            if(save[i]){
                if(cntSet.count(save[i])){
                    return false;
                }
                cntSet.insert(save[i]);
            }
        }
        return true;
    }
};