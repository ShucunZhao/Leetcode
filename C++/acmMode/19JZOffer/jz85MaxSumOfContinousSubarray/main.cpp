#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        /*
            [1,-2,3,10,-4,7,2,-5]
                  l
                          r
             sum: 16
             ans: [3,10,-4]
        */
        vector<int> dp(array.size());
        dp[0] = array[0];
        int sum = dp[0];
        int l = 0, r = 0;
        int ansL = 0, ansR = 0;
        for (int i = 1; i < array.size(); ++i) {
            if (dp[i - 1] + array[i] < array[i]) {
                l = i;
                r = i;
                dp[i] = array[i];
            }
            else {
                dp[i] = dp[i - 1] + array[i];
                r = i;
            }
            if (dp[i] >= sum) {
                ansL = l;
                ansR = r;
                sum = dp[i];
            }
        }
        return vector<int>(array.begin() + ansL, array.begin() + ansR+1);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the array:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        vector<int> res = S1.FindGreatestSumOfSubArray(nums);
        cout << "Rss: [";
        for (int& i : res) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
}