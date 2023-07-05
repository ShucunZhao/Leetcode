class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merg(m+n);
        int l=0,r=0;
        int i = 0;
        while(l<m&&r<n){
            if(nums1[l]<nums2[r]){
                merg[i++] = nums1[l++];
            }
            else{
                merg[i++] = nums2[r++];
            }
        }
        while(l<m){
            merg[i++] = nums1[l++];
        }
        while(r<n){
            merg[i++] = nums2[r++];
        }
        nums1 = merg;
    }
};