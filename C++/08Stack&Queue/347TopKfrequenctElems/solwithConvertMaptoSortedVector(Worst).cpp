/*
 * Solution1: The time complexity will be nlog(n) because sorting all n elements.
 * Step1: Use unordered_map(HashMap) to store all frequency information.
 * Step2: Convert map to pairs vector that used for sorting by the frequency in next step.
 * Step3: Define the customize compare function of sort function in vector.
 * Step4: Get the first k elements in the sorted pairs vector with descending frequent order.
 */
class Solution {
public:
    //Step3:
    static bool cmp(const pair<int, int> & v1, const pair<int, int> & v2){//KeyPoint here: You must define the compare funciton into static 
                                                                        //to keep the same with original cmp func format with sorting.
         return v1.second>v2.second;//From larger to smaller.
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Step1:
        unordered_map<int, int> ms;
        for(int i : nums){
            ms[i]++;
        }
        //Step2:
        vector<pair<int, int>> vs(ms.begin(), ms.end());
        sort(vs.begin(),vs.end(),cmp);//Key is to customize cmp function.
        //Step4:
        vector<int> ans;
        for(int j=0;j<k;j++){
            ans.push_back(vs[j].first);
        }
        return ans;
    }
};