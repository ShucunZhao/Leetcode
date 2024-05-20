#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            we can maintain two arrays to represent the left and right part product in current position.
            left:   1  1  2  6
            nums = [1, 2, 3, 4]
            right: 12 12  4  1
        */
        vector<int> left(nums.size()), right(nums.size());
        left[0] = 1;
        right[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i-1]*nums[i-1];
        }
        for (int j = nums.size() - 2; j >= 0; --j) {
            right[j] = right[j + 1] * nums[j + 1];
        }
        for (int i = 0; i < nums.size(); ++i) nums[i] = left[i] * right[i];
        return nums;
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
        vector<int> res = S1.productExceptSelf(nums);
        cout <<"Res: [";
        for (int& i : nums) cout << i << ",";
        cout << "]"<<endl;
    }
}