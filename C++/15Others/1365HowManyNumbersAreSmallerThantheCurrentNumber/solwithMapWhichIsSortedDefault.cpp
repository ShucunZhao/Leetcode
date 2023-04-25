class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> ms;
        for(int i : nums){
            ms[i]++;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            int cnt = 0;
            for(auto x : ms){
                if(x.first<nums[i]){
                    cnt+=x.second;
                }
                else{
                    break;
                }
            }
            ans[i] = cnt;
        }
        /*
        for(auto x : ms){
            cout<<x.first<<":"<<x.second<<endl;
        }
        */
        return ans;
    }
};