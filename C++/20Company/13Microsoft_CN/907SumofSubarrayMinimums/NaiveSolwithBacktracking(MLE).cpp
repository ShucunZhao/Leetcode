class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int mod = 1e9+7;
    /*
        [3,1,2,4]
        [1,2,3,4]
    */
    void dfs(int start, vector<int> & arr, vector<bool> & used){
        if(start==arr.size()){
            return;
        }
        for(int i=start;i<arr.size();i++){
            if(path.empty()){
                path.push_back(arr[i]%mod);
                ans.push_back(path);
                used[i]=true;
                dfs(i+1, arr, used);
                path.pop_back();
                used[i]=false;
            }
            else if(i>0&&used[i-1]){
                path.push_back(arr[i]);
                ans.push_back(path);
                used[i]=true;
                dfs(i+1, arr, used);
                path.pop_back();
                used[i]=false;   
            }
        }
        return;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // sort(arr.begin(), arr.end());
        vector<bool> used(arr.size());
        dfs(0, arr, used);
        /*
        for(int i=0;i<ans.size();i++){
            cout<<"[";
            for(int j=0;j<ans[i].size();j++){
               cout<<ans[i][j]<<",";
            }
            cout<<"]"<<endl;
        }
        */
        int res = 0;
        for(int i=0;i<ans.size();i++){
            auto minIt = min_element(ans[i].begin(), ans[i].end());
            res+=((*minIt)%mod);
        }
        return res;
    }
};