class Solution {
public: 
    static int countBits(int n){
        int cnt = 0;
        while(n){
            if(n&1){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    static bool myCmp(int a, int b){
        if(countBits(a)==countBits(b)){
            return a<b;
        }
        return countBits(a) < countBits(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        /*
            0:       0
            1:       1
            2:      10
            3:      11
            4:     100
            5:     101
            6:     110
            7:     111
            8:    1000
        */   
        sort(arr.begin(), arr.end(), myCmp);
        return arr;
    }
};