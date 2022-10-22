/*
 * Solution2: Use priority queue to do the sorting task which will reduce the time complexity to nlog(k),
              k is the number of elements in heap(priority queue).
 * Step1: Use unordered_map(HashMap) to store all frequency information.
 * Step2: Define a grater priority queue(small top heap) and keep it k nodes only.
 * Step3: Define the customize compare class by overload the '()' operator.
 * Step4: Get all k elements key in priority queue as ans.
 */
class Solution {
public:
    //Step3:
    class myCmp{
    public:
        bool operator()(const pair<int, int> & p1, const pair<int, int> & p2){
            return p1.second>p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Step1:
        unordered_map<int, int> ms;
        for(int i : nums){
            ms[i]++;
        }
        //Step2:
        priority_queue<pair<int,int>, vector<pair<int, int> >, myCmp> prq;
        for(auto x : ms){
            prq.push(x);
            if(prq.size()>k){
                prq.pop();
            }
        }
        //Step4:
        vector<int> ans;
        for(int j=0;j<k;j++){
            ans.push_back(prq.top().first);
            prq.pop();
         }
        return ans;
    }
};