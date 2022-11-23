class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();//If use this as right interval you need to use l<r as condition in while loop
                                  //because this is a [l,r) interval, l cannot be equal to r.
        int m;
        while(l<r){
            m = l+(r-l)/2;//KetPoint here: you cannot use this m = r+(l-r)/2 to calculate the middle index 
                         //because if (l-r) is negative will be ignore
            // cout<<"l:"<<l<<endl;
            // cout<<"r:"<<r<<endl;
            // cout<<"1:"<<r+(l-r)/2<<endl;
            // cout<<"2:"<<l+(r-l)/2<<endl;
            if(nums[m]>target){
                r = m;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};