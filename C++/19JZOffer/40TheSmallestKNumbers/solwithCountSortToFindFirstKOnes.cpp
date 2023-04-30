class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        const int N = 1e4+1;
        //cout<<N<<endl;
        int cnt[N] = {0};
        for(int i : input){
            cnt[i]++;
        }
        vector<int> ans;
        for(int i=0;i<N;i++){
            while(cnt[i]&&k){
                ans.push_back(i);
                cnt[i]--;  
                k--;  
            }
        }
        return ans;
    }
};