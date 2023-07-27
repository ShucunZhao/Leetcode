class Solution {
public:
    // int ans = 1;
    // unordered_map<int, int> ms;
    class myCmp{
    public:
        bool const operator()(const vector<int> & a, const vector<int> & b){
            if(a[0]==b[0]){
                // return a[1]<b[1];
                return a[1]>b[1];//If use oneD longest ascending subsequence we need the make the second element be larger when first two elements are same.
            }
            return a[0]<b[0];
        }
    };
    /*
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
    */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /*
            envelopes = [[46,89],[50,53],[52,68],[72,45],[77,81]]
                         [46,89],[50,53],[52,68],[72,45],[77,81] 
              dp:           1       1       1       1       1           
        */
        sort(envelopes.begin(), envelopes.end(), myCmp());
        /*
        for(vector<int> x : envelopes){
            for(int i : x) cout<<i<<",";
            cout<<endl;
        }
        cout<<endl;
        */
        /*
            [[5,4],[6,4],[6,7],[2,3]]
            [2,3],[5,4],[6,7],[6,4]

            3 4 7 5
            st: 3 4 7  5
        */
        vector<int> st;//Use another method to calculate the longest ascending subsequence by maintaining a 
                      //monotonic ascending stack and replace the element.
        for(int i=0;i<envelopes.size();i++){
            if(st.empty()||envelopes[i][1]>st.back()){
                st.push_back(envelopes[i][1]);
            }
            else{
                int l = 0, r = st.size()-1;
                int tar = envelopes[i][1];
                int index = -1;
                while(l<=r){//Binary search find the index of first larger or equal to tar element.
                    int m = l+(r-l)/2;
                    if(st[m]>=tar){
                        index = m;
                        r = m-1;
                    }
                    else{
                        l = m+1;
                    }
                }
                st[index] = tar;
            }
        }
        
        /*
        for(int i : st) cout<<i<<",";
        cout<<endl;
        */
        return st.empty()?1:st.size();
        // return -1;
    }
};