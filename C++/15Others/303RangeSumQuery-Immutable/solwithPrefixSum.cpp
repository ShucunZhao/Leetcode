class NumArray {
public:
    /*
                0  1  2   3  4   5 
        nums: [-2, 0, 3, -5, 2, -1]

                l     r
        prefix:-2,-2, 1, -4,-2, -3

        ans[l,r] = prefix[r] - prefix[l-1](if l<0 prefix[l-1]=0);
    */
    vector<int> prefix; 
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = nums[i]+prefix[i-1];
        }
        // for(int i : prefix) cout<<i<<",";
        // cout<<endl;
    }
    
    int sumRange(int left, int right) {
        return left>0?(prefix[right]-prefix[left-1]):prefix[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */