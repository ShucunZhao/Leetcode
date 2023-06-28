class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1 = [1,3], nums2 = [2]
        //            l            r 
        // num3 = [1,2,3];
        //           l
        //           r
        //-----------------
        // nums1 = [1,2], nums2 = [3,4]
        //            l            r
        // num3 =  [1,2,3,4]
        //            l r 
        //
        int size = nums1.size()+nums2.size();
        vector<int> nums3(size);
        int i = 0, l = 0, r = 0;
        for(l,r;l<nums1.size()&&r<nums2.size();){
            // if()
            if(nums1[l]<nums2[r]){
                nums3[i++] = nums1[l++];
            }
            else{
                nums3[i++] = nums2[r++];
            }
            // nums3[i++]=(nums1[l]<nums2[r])?nums1[l++]:nums2[r++];
            //cout<<nums3[i-1]<<endl;
        }
        while(l<nums1.size()){
            nums3[i++] = nums1[l++];
        }
        while(r<nums2.size()){
            nums3[i++] = nums2[r++];
        }
        // for(int i : nums3) cout<<i<<",";
        // cout<<endl;
        if(size&1){
            return nums3[(size>>1)];
        }
        return ((double)nums3[(size>>1)-1]+(double)nums3[(size>>1)])/2;
        // return -1;
    }
};