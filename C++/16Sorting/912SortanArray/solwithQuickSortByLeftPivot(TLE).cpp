class Solution {
public:
    //Quick Sort:
    int partition(vector<int> & nums, int l, int r){
        int p = l+1;
        int V = nums[l];//Use the first left element as privot, it will run O(n^2) TC when nums is a sorted array(TLE). 
        //i:       0  1  2  3  4
        //nums =  [4, 3, 2, 5, 1]
        //-----------------------
        //nums =  [1, 3, 2, 4, 5]
        //         V        p 
        //                         c
        //--------------------------
        //nums =  [1, 3, 2, 4, 5]
        //         V        p 
        //                         c
        for(int i=l+1;i<=r;i++){
            if(nums[i]<V) swap(nums[p++], nums[i]);
        }
        swap(nums[l], nums[--p]);
        return p;
    }
    void quickSort(vector<int> & nums, int l, int r){
        if(l>=r) return;
        int m = partition(nums, l, r);
        quickSort(nums, l, m-1);
        quickSort(nums, m+1, r);
    }
    /* 
    //5.Merge sort(Divide and conquer)
    void merge(int l, int r, int mid, vector<int> & nums){
        //right:
        //tmp:    2  5 1  3
        //nums =  [5,2,3, 1]
        //i:       0 1 2  3
        //         l   m  r
        //         i   j
        //                p    
        int i = l, j = mid;
        vector<int> tmp(r-l+1);
        int p = 0;
        //vector<int> tmp;
        while(i<mid&&j<=r){
            // if(nums[i]<nums[j]) tmp.push_back(nums[i++]);
            // else tmp.push_back(nums[j++]);
            if(nums[i]<nums[j]) tmp[p++] = nums[i++];
            else tmp[p++] = nums[j++];         
        }
        while(i<mid) tmp[p++] = nums[i++];//tmp.push_back(nums[i++]);
        while(j<=r) tmp[p++] = nums[j++];//tmp.push_back(nums[j++]);        
        // cout<<"tmp:";
        // for(int i : tmp){
        //     cout<<i;
        // }
        // cout<<endl;
        for(int i=l, p=0;i<=r;i++,p++){
            nums[i] = tmp[p];//[5231]->[]
        }
        // cout<<"nums:";
        // for(int i : nums){
        //     cout<<i;
        // }
        // cout<<endl;
    }
    void divide(int l, int r, vector<int> & nums){
        if(l>=r){
            return;
        }
        int mid = l+(r-l)/2;
        divide(l, mid, nums);
        divide(mid+1, r, nums);
        // cout<<"l:"<<l<<","<<"r:"<<r<<","<<"mid:"<<mid<<endl;
        merge(l, r, mid+1, nums);
    }
    */
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
        //i:       0 1 2 3
        // nums = [5,2,3,1]
        /*
        //5.Merge sort(Divide and conquer)
        divide(0,nums.size()-1,nums);
        return nums;
        */
        /*
        //4.Hill sort:
        for ( int gap = nums.size() / 2; gap >=1; gap = gap / 2 ){
            // 每一组进行排序
            for ( int i = gap; i < nums.size(); ++i ){
                int temp = nums[i];
                int j = i - gap;
                while ( j >= 0 && nums[j] > temp ){
                    nums[j+gap] = nums[j];
                    j -= gap;
                }
                nums[j+gap] = temp;
            }
        }
        */
        /*
        //3.Insert sort:
        for(int i=0;i<nums.size();i++){
            int preI = i-1;
            int cur = nums[i];
            while(preI>=0&&nums[preI]>cur){
                nums[preI+1] = nums[preI];
                preI--;
            }
            nums[preI+1] = cur;
        }
        */
        /*
        //2.Select sort:
        for(int i=0;i<nums.size()-1;i++){
            int minI = i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[minI]) minI = j;
            }
            if(i!=minI){
                int tmp = nums[i];
                nums[i] = nums[minI];
                nums[minI] = tmp;
            }
        }
        */
        /*
        //1.Bubble sort:
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size()-i;j++){
                if(nums[j]<nums[j-1]){
                    int tmp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        */
    }
};