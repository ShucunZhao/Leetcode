class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i : input){
            pq.push(i);
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};