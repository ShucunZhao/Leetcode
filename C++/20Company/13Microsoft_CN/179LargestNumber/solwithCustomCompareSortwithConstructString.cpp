class Solution {
public:
    class myCmp{
    public:
        bool operator()(int a, int b){
            string ans1 = to_string(a)+to_string(b);
            string ans2 = to_string(b)+to_string(b);
            return ans1>ans2;
        }
    };
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myCmp());
        string ans = "";
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        // for(int i : nums) cout<<i<<",";
        // cout<<endl;
        return ans[0]=='0'?"0":ans;
    }
};