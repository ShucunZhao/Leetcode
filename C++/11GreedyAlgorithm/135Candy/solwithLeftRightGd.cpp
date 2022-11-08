class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }
        // for(int i : candies){
        //     cout<<i<<endl;
        // }
        for(int j=ratings.size()-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                candies[j] = max(candies[j], candies[j+1]+1);
            }
        }
        // cout<<"...."<<endl;
        // for(int i : candies){
        //     cout<<i<<endl;
        // }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};