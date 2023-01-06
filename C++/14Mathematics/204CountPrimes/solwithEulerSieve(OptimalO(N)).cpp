class Solution {
public:
    // bool isPrime(int n){
    //     int sq = sqrt(n);
    //     for(int i=2;i<=sq;i++){
    //         if(n%i==0) return 0;
    //     }
    //     return 1;
    // }
    // int solOne(int n, int cnt){
    //     for(int i=2;i<=n;i++){
    //         if(isPrime(i)) cnt++;
    //     }
    //     return cnt;
    // }
    // int solTwo(int n, int cnt){
    //     vector<bool> st(n+1, 0);
    //     // int sq = sqrt(n);
    //     // st[0] = 1;
    //     // st[1] = 1;
    //     for(long i=2;i<=n;i++){
    //         if(!st[i]){
    //             cnt++;
    //             for(long j=i*i;j<=n;j+=i){
    //                 st[j] = 1;
    //             }
    //         }
    //     }
    //     // for(int i=2;i<=n;i++){
    //     //     if(!st[i]) cnt++;
    //     // }
    //     return cnt;
    // }
    int solThree(int n, int cnt){
        vector<bool> flag(n+1, 0);
        vector<int> prSet(n+1);
        // int sq = sqrt(n);
        for(int i=2;i<=n;i++){
            if(!flag[i]){
                prSet[cnt] = i;
                cnt++; 
            }
            for(int j=0;prSet[j]<=n/i;j++){
                flag[i*prSet[j]] = 1;
                if(i%prSet[j]==0) break;
            }
        }
        return cnt;
    }
    int countPrimes(int n) {
        if(n<3) return 0;
        // return solOne(n-1, 0);
        // return solTwo(n-1, 0);
        return solThree(n-1, 0);
    }
};