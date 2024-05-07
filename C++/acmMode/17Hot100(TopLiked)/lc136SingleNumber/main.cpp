#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            Input: nums = [4,1,2,1,2]
            Output: 4
        */
        int ans = 0;
        for (int& i : nums) ans ^= i;
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        vector<int> nums;
        In = In.substr(1, In.size() - 2);
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.singleNumber(nums) << endl;
    }
}