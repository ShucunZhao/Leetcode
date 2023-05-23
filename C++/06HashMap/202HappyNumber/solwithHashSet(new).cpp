class Solution {
public:
    int sumDigits(int num){
        /*
            12
        */
        int sum = 0;
        while(num){
            sum+=pow((num%10),2);
            num/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        /*
            2
            4
            16
            1+36 = 37
            9+49 = 58
            25+64 = 89
            64+81 = 145
            1+16+25 = 42
            16+4 = 20
            4 
        */
        unordered_set<int> mset;
        while(n!=1){
            if(mset.count(n)) return false;
            mset.insert(n);
            n=sumDigits(n);
        }
        return true;
    }
};