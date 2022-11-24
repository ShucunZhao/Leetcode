class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()==3){
            return 1;
        }
        int l = 0, r = arr.size()-1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m!=0&&arr[m-1]>arr[m]){
                r = m-1;
            }
            else if(m!=arr.size()-1&&arr[m]<arr[m+1]){
                l = m+1;
            }
            else if(m==0&&arr[m+1]>arr[m]){
                l = m+1;
            }
            else if(m==arr.size()-1&&arr[m-1]>arr[m]){
                r = m-1;
            }
            else if(arr[m-1]<arr[m]&&arr[m]>arr[m+1]){
                return m;
            }
        }
        return -1;
    }
};