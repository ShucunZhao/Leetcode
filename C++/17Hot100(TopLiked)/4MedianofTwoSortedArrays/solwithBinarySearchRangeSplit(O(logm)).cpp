class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Meg:    [1,2,3]
        //nums2 =[1|,3]   size:3, half:1
        //        m2
        //nums1 = -mx[|2]
        //        m1 
        if(nums1.size()>nums2.size()) swap(nums1, nums2);
        // for(int i:nums1) cout<<i<<endl;
        int m = nums1.size(), n = nums2.size();//m<n
        int half = (m+n)/2;
        // cout<<"half:"<<half<<endl;
        int l=0,r=0;
        int m1,m2;
        for(int l=0,r=nums1.size()-1;;){
            int m1 = r<0?-1:(l+r)/2;//KeyPoint 2: if the cutting line out of bound let the m1 be negative 1.
            // cout<<"m+1:"<<m+1<<endl;
            int m2 = half-(m1+1)-1;//-1
            // cout<<"m1:"<<m1<<endl;
            // cout<<"m2:"<<m2<<endl;
            // cout<<"nums2.size()-1:"<<nums2.size()-1<<endl;
            int lOne = m1>=0 ? nums1[m1] : -INT_MAX;//2 
            //KeyPoint 1: you need to use m and n represent nums.size() here because
            //the result of nums.size() is unsigned type which cannot use to cmpare with
            //a signed int(negative number), or will cause cmparison fault!
            int rOne = m1<m-1 ? nums1[m1+1] : INT_MAX;//MAx
            int lTwo = m2>=0 ? nums2[m2] : -INT_MAX;//-MAX
            int rTwo = (m2<n-1) ? nums2[m2+1] : INT_MAX;//1
            /*
            if(m2<nums2.size()-1) cout<<"m2<nums2.size()-1"<<endl;
            else cout<<"m2>=nums2.size()-1"<<endl;
            */
            // cout<<(bool)(m2<nums2.size()-1)<<endl;
            // cout<<"lOne:"<<lOne<<endl;//2
            // cout<<"lTwo:"<<lTwo<<endl;//-Max
            // cout<<"rOne:"<<rOne<<endl;//Max
            // cout<<"rTwo:"<<rTwo<<endl;//1
            if(lOne<=rTwo&&lTwo<=rOne){
                // cout<<"falg";
                if((m+n)%2==1){
                    return (double)min(rOne, rTwo);
                }
                else{
                    return ((double)max(lOne,lTwo)+(double)min(rOne,rTwo))/2;
                }
            }
            else if(lOne>rTwo){
                r = m1-1;
            }
            else{
                l = m1+1;
            }
            
        }
        return -1;
    }
};