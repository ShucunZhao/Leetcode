#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*
                Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
                Output: 3 ([3,2,1])

                1,2,3,2,1
              3 0 0 1 0 0
              2 0 1 0 2 0
              1
              4
              y
              1.dp[i][j]: the longest subarray when in nums1[i] and nums2[j]
              2.if(nums1[i]==nums2[j]):
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    continue;(dp[i][j]=0)
              3.dp[x][0] = 1 if nums1[x]==nums2[0] else = 0
                dp[0][x] = 1 if nums1[0]==nums2[x] else = 0
        */
        vector<vector<int> > dp(nums1.size(), vector<int>(nums2.size()));
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums2[j] == nums1[0]){
                dp[0][j] = 1;
                ans = 1;
            }
        }
        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums1:" << endl;
        string N1;
        getline(cin, N1);
        if (N1 == "q") break;
        cout << "Enter the nums2:" << endl;
        string N2;
        getline(cin, N2);
        if (N2 == "q") break;
        vector<int> nums1;
        N1 = N1.substr(1, N1.size() - 2);
        if (!N1.empty()) {
            stringstream ss(N1);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums1.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        vector<int> nums2;
        N2 = N2.substr(1, N2.size() - 2);
        if (!N2.empty()) {
            stringstream ss(N2);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums2.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.findLength(nums1, nums2) << endl;
    }
}