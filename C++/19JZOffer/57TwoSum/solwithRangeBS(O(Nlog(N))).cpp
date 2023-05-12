class Solution {
public:
    int binarySearch(vector<int> & array, int l, int r, int tar){
        if(l<0||r>=array.size()){
            return -1;
        }
        while(l<=r){
            int m = l+(r-l)/2;
            if(array[m]>tar){
                r = m-1;
            }
            else if(array[m]<tar){
                l = m+1;
            }
            else{
                return array[m];
            }
        }
        return -1;
    }
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        for(int i=0;i<array.size();i++){
            int tar = sum-array[i];
            if(tar<=0||tar>array[array.size()-1]){
                continue;
            }
            if(binarySearch(array, 0,i-1,tar)!=-1){
                return {array[i], binarySearch(array, 0,i-1,tar)};
            }
            if(binarySearch(array, i+1,array.size()-1,tar)!=-1){
                return {array[i], binarySearch(array, i+1,array.size()-1,tar)};
            }
        }
        return {};
    }
};