class Solution {
public:
    //int slidingWindow(vector<int> & nums, int k, vector<int> & prefixSum){
    int slidingWindow(vector<int> & nums, int k){    
        unordered_map<int, int> ms;
        int l=0,r=0;
        int cnt = 0;
        /*
        SlidingWindow:
                   l
                      r
         i:  0 1 2 3 4
            [1,2,1,2,3]
        */
        while(r<nums.size()){
            ms[nums[r]]++;
            while(ms.size()>k){
                ms[nums[l]]--;
                if(ms[nums[l]]==0){
                    ms.erase(nums[l]);
                }
                l++;
            }
            cnt += (r-l+1);//We need to use the idea of prefix sum to accumulate each length of result.
            r++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k){
        /*
        prefixSum: length[0] = 1;
                   length[1] = 2+length[0] = 2+1 = 3
                   length[2] = 3+length[1] = 3+3 = 6
                   length[3] = 4+length[2] = 4+6 = 10
                   length[4] = 5+length[3] = 5+10 = 15
                   length[i] = {
                              1 when i == 0;
                              i+1 + length[i-1] when i > 0;
                        }
                   length[x, y] = length[y-x] when y-x > 0
                                  1  when x ==y .
        SlidingWindow:
             l
                 r
         i:  0 1 2 3 4
            [1,2,1,2,3]

        ms: 1: 0       k:sum[0,3]+sum[3,4]             k-1: sum[0,0]+sum[1,1]+sum[2,2]+sum[3,3]+sum[4,4]
            2: 0         =sum[3]+sum[1]                       
            3: 1         =10+3                            
                         =13                           
        */  
        // vector<int> prefixSum(nums.size());
        /*
        prefixSum[0] = 1;
        for(int i=1;i<nums.size();i++){
           prefixSum[i] = i+1 + prefixSum[i-1]; 
        }
        */
        /*
        for(int i : prefixSum) cout<<i<<",";
        cout<<endl;
        */
        //cout<<"k<=2: "<<slidingWindow(nums, k, prefixSum)<<endl;
        //cout<<"k<=1: "<<slidingWindow(nums, k-1, prefixSum)<<endl;
        /*
        if(k==1) return slidingWindow(nums, k, prefixSum); 
        return slidingWindow(nums, k, prefixSum)-slidingWindow(nums, k-1, prefixSum);
        */
        if(k==1) return slidingWindow(nums, k); 
        return slidingWindow(nums, k)-slidingWindow(nums, k-1);
    }
};