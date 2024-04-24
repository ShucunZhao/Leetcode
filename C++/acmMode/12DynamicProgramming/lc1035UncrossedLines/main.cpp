#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /*
            nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
                    1 3 7 1 7 5
                1   1 0 0 1 0 0
                9   0 1 1 1 1 1
                2   0 1 1 1 1 1
                5   0 1 1 1 1 2
                1   1 1 1 2 2 2
            
               nums1 = [1,4,2], nums2 = [1,2,4]
                   1  1  4
                1  1  1  0
                4  0  0  
                2  0
        */
        vector<vector<int> > dp(nums1.size(), vector<int>(nums2.size()));
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0]) {
                while(i<nums1.size()) dp[i++][0] = 1;
            }
        }
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums1[0] == nums2[j]) {
                while(j<nums2.size()) dp[0][j++] = 1;
            }
        }
        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] =  dp[i - 1][j -1] + 1;
                }
                else {
                    dp[i][j] = dp[i-1][j-1];

                }
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
    }
};

void convert(string& s, vector<int> & nums) {
    s = s.substr(1, s.size() - 2);
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        size_t l = token.find_first_not_of(" ");
        size_t r = token.find_last_not_of(" ");
        nums.push_back(stoi(token.substr(l, r - l + 1)));
    }
    return;
}

int main(int argc, char * argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums1:" << endl;
        string N1;
        getline(cin, N1);
        if (N1 == "q") break;
        cout << "Enter nums2:" << endl;
        string N2;
        getline(cin, N2);
        if (N2 == "q") break;
        vector<int> nums1;
        vector<int> nums2;
        convert(N1, nums1);
        convert(N2, nums2);
        cout << "Res:" << S1.maxUncrossedLines(nums1, nums2) << endl;
    }
}