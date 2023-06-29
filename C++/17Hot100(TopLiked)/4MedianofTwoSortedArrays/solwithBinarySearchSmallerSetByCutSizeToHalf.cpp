class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            size: 4, half:2
                      m
            nums1 = MIN[3,4]MAX
                         m  
            nums2 =MIN[0,0]MAX
        */
        if(nums1.size()>nums2.size()) swap(nums1, nums2);
        int size = nums1.size()+nums2.size();
        int half = size/2;
        bool odd = (size%2==1);
        int l=0, r=nums1.size()-1;
        while(true){
            //int m1 = r<0?-1:l + (r-l)/2;
            int m1 = r<0?-1:l + (r-l)/2;//KeyPoint here! The m1 must be -1 when r<0 or the index m1 will always be 0 in here. 
            int m2 = half-(m1+1)-1;
            int left1 = m1<0 ? INT_MIN : nums1[m1];
            int right1 = m1+1>=nums1.size() ? INT_MAX : nums1[m1+1];
            int left2 = m2<0? INT_MIN : nums2[m2];
            int right2 = m2+1>=nums2.size() ? INT_MAX : nums2[m2+1];
            if(left1<=right2&&left2<=right1){
                if(odd){
                    return min(right1, right2);
                }
                return ((double)max(left1, left2)+(double)min(right1,right2))/2;
            }
            else if(left1<=right2&&left2>right1){
            // else if(left2>right1){    
                l = m1+1;
            }
            else if(left1>right2&&left2<=right1){
            // else if(left1>right2){
                r = m1-1;
            }
        }
        return -1;
    }
};