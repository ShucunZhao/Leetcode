#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            sol with find the first ascending pair from back, and then fix the first element in pair 
            and find the smaller one which is greater then this element after it, then swap them 
            and sort the remains aftert the fixed position.
            [4,2,0,2,4,3,0]
                   x
             4 2 0 3 0 2 2
        */
        if (nums.size() == 1) return;
        int r = nums.size() - 2;
        bool found = false;
        while (r >= 0) {
            if (nums[r] < nums[r + 1]) {
                found = true;
                break;
            }
            r--;
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        } 
        int first = nums.size() - 1;
        while (nums[r] >= nums[first]) first--;
        swap(nums[r], nums[first]);
        sort(nums.begin() + r + 1, nums.end());
        return;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums:" << endl;
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
        S1.nextPermutation(nums);
        cout << "Res: [";
        for (int& i : nums) cout << i << ",";
        cout <<"]" << endl;
    }
}