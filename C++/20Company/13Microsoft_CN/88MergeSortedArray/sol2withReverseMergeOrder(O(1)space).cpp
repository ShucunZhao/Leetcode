class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*

                         l
                         t
            nums1 = [1,2,M,3,5,6], m = 3, nums2 = [2,5,6], n = 3
                                                   r

                       l
                       t
            nums1 = [1,2,X,5,6,9], m = 3, nums2 = [2,5,6], n = 3
                                                   r
        
                   l
                       t
            nums1 = [0,2], m = 3, nums2 = [1], n = 3
                                           r        

                  l
                         t
            nums1 = [1,2,3,4,5,6], m = 3, nums2 = [1,2,3,5,6], n = 3
                                                       r                                                   
        */
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        int l = m-1;
        int t = nums1.size()-1;
        int r = nums2.size()-1;

        while(l>=0&&r>=0){
            if(nums1[l]>nums2[r]){
                nums1[t--] = nums1[l--];
            }
            else{
                nums1[t--] = nums2[r--];
            }
        }
        while(l>=0){
            nums1[t--]=nums1[l--];
        }
        while(r>=0){
            nums1[t--]=nums2[r--];
        }
        return;
    }
};