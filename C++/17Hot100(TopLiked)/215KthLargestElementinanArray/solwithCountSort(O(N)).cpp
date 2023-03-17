class Solution {
public:
    void countSort(vector<int> & nums){
        const int N = 1e5+1;
        const int buff = 1e4;
        int cnt[N] = {0};
        for(int i : nums){
            cnt[i+buff]++;
        }
        int pos = 0;
        for(int i=0;i<N;i++){
            while(cnt[i]>0){
                cnt[i]--;
                nums[pos++] = i-buff; 
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end());
        countSort(nums);
        return nums[nums.size()-k];
    }
};