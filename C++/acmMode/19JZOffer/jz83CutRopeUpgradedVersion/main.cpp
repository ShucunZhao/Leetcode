#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    long long mod = 998244353;
    long long cutRope(long long number) {
        /*
            We need to use greedy to deal with: divide the rope into length is 3 as many as possible,
            there are only two remains cases:
            Case1: remains 2, we just multiply 2
            Case2: remains 1, if we just multiply 1 it would smaller, so we need to borrow a 3 from original to
            make up a 4 which is 2*2, then use 4 multiply the (original-3) quick power.
            We use quick power to calculate
            10
            3*3*3*1 = 27
            3*3*2*2 = 36
        */
        if (number == 2) return 1;
        if (number == 3) return 2;
        if (number == 4) return 4;
        if (number % 3 == 0) return myPow(3, number / 3);
        if (number % 3 == 1) {
            return (2 * 2 % mod * myPow(3, (number - 4) / 3)) % mod;
        }
        return (2 * myPow(3, number / 3)) % mod;
    }
    long long myPow(long long base, long long power) {
        long long ans = 1;
        base %= mod;
        while (power) {
            if (power & 1) {
                ans = (ans * base)%mod;
            }
            base = (base * base) % mod;;
            power >>= 1;
        }
        return ans;
    }
    long long cutRope2(long long number) {
        // write code here
        /* 
            long long mod = 998244353
            1.dp[i]: the max product when the length of rope if i
            2.for(int i=4;i<=number;++i){
                for(int j=0;j<i/2;++j){
                    dp[i] = max(dp[i], dp[j]*dp[i-j])%mod;
                           
                }
            }
                dp[i] = max(dp[i], dp[j]*dp[i-j])
            3.dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = max(dp[1]*dp[3],dp[2]*dp[2])
            !!! But in this quesion, the problem size is too larget to use the dynamic programming,
            so we need to use greedy to deal with: divide the rope into length is 3 as many as possible,
            if there remain something, keep it as 2 but not 1.
        */
        if (number == 2) return 1;
        if (number == 3) return 2;
        vector<long long> dp(number + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        long long mod = 998244353;
        for (long long i = 4; i <= number; ++i) {
            for (long long j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j] % mod);
            }
        }
        return dp[number];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enther the number:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        long long number = stoll(N);
        cout << "Res: " << S1.cutRope(number) << endl;
    }
}