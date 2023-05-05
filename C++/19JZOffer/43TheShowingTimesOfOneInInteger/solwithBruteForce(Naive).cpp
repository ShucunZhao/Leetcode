class Solution {
public:
    int countOne(int n){
        int cnt = 0;
        while(n){
            if(n%10==1) cnt++;
            n/=10;
        }   
        return cnt;
    }
    int NumberOf1Between1AndN_Solution(int n) {
        /*
              13
              1 2 3 4 5 6 7 8
        1: 1
        2: 10
        3: 11
        4: 100
        5: 101
        6: 110
        7: 111
        8: 1000
        9: 1001
        10: 1010
        11: 1011
        */
        //cout<<countOne(11)<<endl;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans+=countOne(i);
        }
        return ans;
    }
};