class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        /*

            [4,5,1,2,3]
                  
            [2,2]
            
            [3,100,200,3]

            [3,100,0,0,2,3]

            [2,2,2,1,2]

            There three cases: 
                1.The mid element is larger than last element, move l to m+1
                2.The mid element is smaller than last element, move r to m-1
                3.(KeyPoint!)The mid element is equal to last elememt, we need to cut the last one than use
                             the second larger element as current last element to do the step continuously.
        */
        int n = rotateArray.size();
        //Corner case: the array is a sorted array whose minimum is first element.
        if(n==1||rotateArray[0]<rotateArray[n-1]) return rotateArray[0];
        int l=0,r=n-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(rotateArray[m]>rotateArray[n-1]){
                l = m+1;
            }
            else if(rotateArray[m]<rotateArray[n-1]){
                r = m-1;
            }
            else if(rotateArray[m]==rotateArray[n-1]){
                n = n-1;
                r = n;
            }
        }
        return rotateArray[l];
    }
};