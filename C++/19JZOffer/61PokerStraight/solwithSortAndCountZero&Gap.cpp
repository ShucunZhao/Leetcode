class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        /*
            sol with sort:
            numbers: [6,0,2,0,4]
            sort:    [0,0,2,4,6]
            gap: 2+2+2
        */
        sort(numbers.begin(), numbers.end());
        int cntZero = 0;
        for(int i=0;i<numbers.size();i++){//Need to traverse whole array rather than the first two because the 0 will appear more than twice.
            if(numbers[i]==0) cntZero++;
        }
        int gap = 0;
        for(int i=1;i<numbers.size();i++){
            if(numbers[i-1]==0||numbers[i]==0) continue;
            if(numbers[i]==numbers[i-1]) return false;
            gap+=(numbers[i]-numbers[i-1]-1);
        }
        //cout<<cntZero<<endl;
        //cout<<gap<<endl;
        return cntZero>=gap;
    }
};