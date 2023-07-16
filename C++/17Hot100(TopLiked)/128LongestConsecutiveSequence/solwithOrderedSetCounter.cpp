class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
             [0,3,7,2,5,8,4,6,0,1]
             l
                    r
             [1,2,3,4,100,200]
                l
                        r
             [0,0,1,2,3,4,4,5,6,7,8]             
        */
        if(nums.size()==0) return 0;
        set<int> mset;
        for(int i : nums){
            mset.insert(i);
        }
        /*
        for(int i : mset){
            cout<<i<<",";
        }
        cout<<endl;
        */
        int cnt = 1;
        int ans = 1;
        for(auto it=mset.begin();it!=mset.end();++it){
            int cur = *it;
            if(mset.count(cur+1)){
                cnt++;
            }
            else{
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};