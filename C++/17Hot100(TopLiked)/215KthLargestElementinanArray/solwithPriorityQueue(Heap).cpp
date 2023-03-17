class Solution {
public:
    static class cmp{
    public:
        bool operator()(int a, int b){
            return a<b;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int i : nums){
            pq.push(i);
        }
        /*
        while(!pq.empty()){
            cout<<pq.top()<<endl;
            pq.pop();
        }
        */
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};