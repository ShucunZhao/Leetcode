class Solution {
public:
    int getSquareSum(int n){
        int sum = 0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        /*
            n = 2
                4
                16
                1+36=37(first time)
                9+48=57
               25+49=74
               49+16=65
               36+25=61
               36+1=37(second time) then is not a happy number.
        */
        unordered_map<int, bool> ms;
        while(n!=1){
            ms[n] = 1;
            n = getSquareSum(n);
            if(ms[n]){
                return 0;
            } 
        }
        return 1;
    }
};