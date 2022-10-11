class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ms;
        while(1){
            int sum = getSum(n);
            if(sum==1){
                return 1;
            }
            if(ms.count(sum)!=0){
                return 0;
            }
            ms.insert(sum);
            n = sum;
        }
    }
    int getSum(int n){
        int sum = 0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
};