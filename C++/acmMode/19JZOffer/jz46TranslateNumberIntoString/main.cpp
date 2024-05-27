#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int solve(string nums) {
        // write code here
        /*
                "100"
                    
            "123"
               i
            1.dp[i]: the cases of nums[0,i] can constrcut
            2.if(nums[i-1,i]<=26){
                dp[i] = dp[i-1]+dp[i-2]  
              }
              else{
                dp[i] = dp[i-1]
              }
            3.dp[0] = 0, dp[1] = 1, dp[2] = 
        */
        if (nums[0] == '0') return 0;
        if (nums == "10" || nums == "20") return 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == '0' && nums[i - 1] != '1' && nums[i - 1] != '2') return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = 1;
        if (stoi(nums.substr(0, 2))>26|| nums[1] == '0') {
            dp[1] = 1;
        }
        else {
            dp[1] = 2;
        }
        for (int i = 2; i < nums.size(); ++i) {
            int oneDigit = nums[i] - '0';
            int twoDigit = stoi(nums.substr(i-1, 2));
            if (oneDigit > 0) dp[i] += dp[i - 1];
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i - 2];   
        }
        return dp[nums.size() - 1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        cout << "Res: " << S1.solve(In) << endl;
    }
}