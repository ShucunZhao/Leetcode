class Solution {
public:
    int ans = 1;
    unordered_map<int, int> ms;
    class myCmp{
    public:
        bool const operator()(const vector<int> & a, const vector<int> & b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        }
    };
    int backtracking(int start, vector<vector<int>>& envelopes){
        if(ms.count(start)) return ms[start];
        // cout<<envelopes[start][0]<<","<<envelopes[start][1]<<endl;
        int maxPath = 1;
        for(int i=start;i<envelopes.size();i++){
            if(envelopes[start][0]<envelopes[i][0]&&envelopes[start][1]<envelopes[i][1]){
                int cur = 1+backtracking(i, envelopes);
                maxPath = max(maxPath, cur);
            }
        }
        ms[start] = maxPath;
        return ms[start];
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
            ans = max(ans, backtracking(i, envelopes));
        }
        return ans;
    }
};