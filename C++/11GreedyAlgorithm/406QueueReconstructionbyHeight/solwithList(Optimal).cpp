class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b){
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        // vector<vector<int> > ans;
        list<vector<int> > list;
        for(int i=0;i<people.size();i++){
            int pos = people[i][1];
            std::list<vector<int> >::const_iterator it = list.begin();
            while(pos--){
                ++it;
            }
            list.insert(it, people[i]);
            // ans.insert(ans.begin()+pos, people[i]);
        }
        vector<vector<int> > ans(list.begin(), list.end());
        return ans;
    }
};