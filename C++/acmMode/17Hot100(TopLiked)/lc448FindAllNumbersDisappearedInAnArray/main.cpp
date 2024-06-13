#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
            [4,3,2,7,8,2,3,1]
             0 1 2 3 4 5 6 7
            [7,3,2,4,8,2,3,1]
            [1,2,3,4,3,2,7,8]
        */
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while ((nums[i] - 1) != i&& nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] - 1) != i) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q")  break;
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
        vector<int> res = S1.findDisappearedNumbers(nums);
        cout << "Res: ";
        for (int& i : res) cout << i << ",";
        cout << endl;
    }
}