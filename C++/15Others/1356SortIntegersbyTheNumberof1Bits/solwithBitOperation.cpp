class Solution {
public:
    static int bitCount(int n){
        int cnt = 0;
        //Method1: slowly.
        // while(n){
        //     if((n&1)==1) cnt++;
        //     n>>=1;
        // }
        //Method2: faster.
        while(n){
            n&=(n-1);//remove the bit of the lowest position.
            cnt++;
        }
        return cnt;
    }
    static bool cmp(int a, int b){
        int an = bitCount(a);
        int bn = bitCount(b);
        if(an==bn) return a<b;
        return an<bn;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};