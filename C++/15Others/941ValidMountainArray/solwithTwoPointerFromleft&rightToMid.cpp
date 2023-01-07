class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int l = 0, r = arr.size()-1;
        while(l<arr.size()-1&&arr[l+1]>arr[l]) l++;
        while(r>=1&&arr[r-1]>arr[r]) r--;
        return l==r&&l!=0&&r!=arr.size()-1;
    }
};