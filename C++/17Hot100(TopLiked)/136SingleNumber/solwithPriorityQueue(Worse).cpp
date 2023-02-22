class Solution {
public:
    class cmp{
        public:
            bool operator()(const pair<int,int> & A, const pair<int,int> & B){
                return A.second>B.second;
            }
    };
    int singleNumber(vector<int>& nums) {
        /*
            nums = [2,2,1]
            nums = [1,2,2]
            nums = [4,1,2,1,2]
                             
             nums = [1,1,2,2,4]
        */
        /*
        //Sol1:
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                i++;
            }
            else{
                return nums[i];
            }
        }   
        return nums[nums.size()-1];
        */
        unordered_map<int, int> ms;
        priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
        for(int i : nums){
            ms[i]++;
        }
        for(auto x : ms){
            pq.push(x);
        }
        // while(!pq.empty()){
        //     cout<<pq.top().first<<",";
        //     pq.pop();
        // }
        // cout<<endl;
        return pq.top().first;
    }
};