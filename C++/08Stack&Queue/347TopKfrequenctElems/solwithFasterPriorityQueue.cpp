class Solution {
public:
    class cmp{
        public:
            bool operator() (const pair<int,int> & A, const pair<int,int> & B){
                return A.second<B.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
            nums = [1,1,1,2,2,3], k = 2
            ms = [1:3,2:2,3:1]
            heap = 【3:1,2:2,1:3
        */   
        unordered_map<int, int> ms;
        for(int i : nums){
            ms[i]++;
        }
        // vector<pair<int, int> > pairs(ms.begin(), ms.end());//You don't need to store hash map into vector because 
                                                            //the unordered_map can transform to vector<pair> form.
        /*
        for(auto x : pairs){
            cout<<x.first<<":"<<x.second<<endl;
        }
        */
        priority_queue<pair<int,int>, vector<pair<int, int> >, cmp> pq;
        for(auto x : ms){
            pq.push(x);
        }
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;        
    }
};