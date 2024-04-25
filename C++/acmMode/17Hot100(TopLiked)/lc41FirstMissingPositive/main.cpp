#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            We use the bucket sorted idea to deal with this question:
            The first missing positive integer must occur in the range
            of the nums length because if we put each position a "should be" 
            integer.
            nums = [3,4,-1,1]
                   [-1,4,3,1] 
                   [1,-1,3,4]
        */
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 1 && nums[i] - 1 < nums.size()) {
                if (i == nums[i] - 1) break;
                if (nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 0;
        for (i; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return i+1;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        N = N.substr(1, N.size() - 2);
        vector<int> nums;
        if (!N.empty()) {
            stringstream ss(N);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.firstMissingPositive(nums) << endl;
    }
}