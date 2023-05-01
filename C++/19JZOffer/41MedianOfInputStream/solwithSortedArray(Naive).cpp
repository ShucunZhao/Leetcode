class Solution {
public:
    /*
        nums: [5,2,3,4,1,6,7,0,8]
        ans: 2,5,
    */
    vector<double> arr;
    void Insert(int num) {
        arr.push_back(num);
    }

    double GetMedian() { 
        sort(arr.begin(), arr.end());
        int size = arr.size();
        if(size%2==1){
            return arr[size/2];
        }
        return (arr[size/2]+arr[(size-1)/2])/2;
    }

};