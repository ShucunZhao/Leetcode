/*
    sol with backtracking and use hash set to remove duplicate - TLE.
*/

class Solution {
public:
    unordered_set<string> Set;
    string itoString(vector<int> & In){
	    stringstream ss;
        for(int i : In){
            ss<<i<<",";
        }
	    return ss.str();
    }
    void backtracking(int start, vector<int> & path, vector<vector<int> > & ans, vector<int>& nums, int & sum){
        if(path.size()==3){
            if(sum==0){
                // cout<<itoString(path);
                string str = itoString(path);
                if(Set.count(str)==0){
                    Set.insert(str);
                    ans.push_back(path);
                }
            }
        }
        for(int i=start;i<nums.size();i++){
            // if(i>0&&(nums[i-1]=nums[i])&&used[i-1]==0){//Cannot use remove duplicate here, need to use hash set to do this step!
            //     continue;
            // }
            sum+=nums[i];
            path.push_back(nums[i]);
            backtracking(i+1,path,ans,nums,sum);
            sum-=nums[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            nums     = [-1,0,1,2,-1,-4]
            sorted   = [-4,-1,-1,0,1,2]
            used       [ 1, 0, 1,0,0,0]
                                                                        -4
                        -4,-1   
                      -4,-1,-1                                                  

        */
        vector<int> path;
        vector<vector<int> > ans;
        int sum = 0;
        // vector<bool> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtracking(0, path, ans, nums, sum);
        // for(auto x : Set){
        //     cout<<x<<endl;
        // }
        return ans;
    }
};