#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ms;
        for (int i = 0; i < nums.size(); ++i) {
            if (ms.count(target - nums[i])) {
                return { i, ms[target - nums[i]] };
            }
            ms[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout<<"Enter the target: " << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
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
        int target = stoi(T);
        vector<int> res = S1.twoSum(nums, target);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}