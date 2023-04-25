class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int peak = -1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                continue;
            }
            else{
                peak = i-1;
                break;
            }
        }
        if(peak==-1||peak==0) return false;
        for(int i=peak+1;i<arr.size();i++){
            if(arr[i]<arr[i-1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};