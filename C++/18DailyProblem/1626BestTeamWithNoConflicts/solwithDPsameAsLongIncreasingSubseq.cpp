class Solution {
public:
    static bool cmp(const pair<int,int> & a, const pair<int,int> & b){
        //KeyPoint:
        //The smaller age should be more front, if the age is same the
        //less scores should be front which prevent the conflict of different
        //age but larger score situation!
        return a.first<b.first||(a.first==b.first&&a.second<b.second);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        if(ages.size()<2) return scores[0];
        //scores = [5, 1, 2, 3], 
        //  ages = [1, 8, 9, 10]
        //    dp =  5  0  0  0         = if(s[i]>=s[i-1]) dp[i] += s[i]
        //           (5)1                else dp[i] = s[i]
        //                               ans = max(dp[i], ans);
        vector<pair<int, int> > pairs;
        for(int i=0;i<ages.size();i++){
            pairs.push_back({ages[i], scores[i]});
            // pairs.push_back(pair(ages[i], scores[i]));
        }
        sort(pairs.begin(), pairs.end(), cmp);
        // for(auto x : pairs){
        //     // cout<<"Age:"<<x.first<<"S:"<<x.second<<endl;
        //     cout<<x.second<<", ";
        // }
        // int pre = 0;
        vector<int> dp(ages.size(), 0);
        // for(int i=0;i<dp.size();i++){
           
        // }
        int ans = dp[0];
        // cout<<"pairs[0]:"<<"("<<pairs[0].first<<","<<pairs[0].second<<")"<<endl;
        //second = [3, 2, 7, 7, 4, 1, 10, 5, 3]
        //                             i
        //          j
        //first  = [1, 1, 1, 2, 2, 4, 4, 4, 5]
        //dp        3, 5, 12,19,23,1, 33, 0, 0
        //ans       3  5  12 19,23 23
        for(int i=0;i<pairs.size();i++){
            dp[i] = pairs[i].second;
            for(int j=0;j<i;j++){
                if(pairs[i].second>=pairs[j].second){
                    dp[i] = max(dp[i], dp[j]+pairs[i].second);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
    
};