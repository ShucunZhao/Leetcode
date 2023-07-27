class Solution {
public:
    int path = 1;
    int ans = 1;
    class myCmp{
    public:
        bool const operator()(const vector<int> & a, const vector<int> & b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        }
    };
    void backtracking(int start, vector<vector<int>>& envelopes){
        if(start==envelopes.size()){
            return;
        }
        // cout<<envelopes[start][0]<<","<<envelopes[start][1]<<endl;
        for(int i=start;i<envelopes.size();i++){
            if(envelopes[start][0]<envelopes[i][0]&&envelopes[start][1]<envelopes[i][1]){
                path++;
                ans = max(ans, path);
                backtracking(i, envelopes);
                path--;
            }
        }
        return;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /*
            envelopes = [[46,89],[50,53],[52,68],[72,45],[77,81]]
                         [46,89],[50,53],[52,68],[72,45],[77,81] 
        */
        sort(envelopes.begin(), envelopes.end(), myCmp());
        /*
        for(vector<int> x : envelopes){
            for(int i : x) cout<<i<<",";
            cout<<endl;
        }
        cout<<endl;
        */
        for(int i=0;i<envelopes.size();i++){
            path = 1;
            backtracking(i, envelopes);
        }
        
        return ans;
    }
};