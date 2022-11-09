class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(), points.end(), cmp);
        int ans = 1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[i-1][1]){
                ans++;
            }
            else{
                // points[i][1] = min(points[i][1], points[i-1][1]);
                points[i][1] = points[i][1]>points[i-1][1]?points[i-1][1]:points[i][1];
            }
        }
        return ans;
    }
};