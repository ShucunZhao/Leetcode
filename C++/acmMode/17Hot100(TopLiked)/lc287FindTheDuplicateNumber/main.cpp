#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int count(vector<int>& nums, int val) {
        int cnt = 0;
        for (int i = 0; i <nums.size(); ++i) {
            if (nums[i] <= val) cnt++;
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        /*
            Because the value x is in range [1,n] which nums.size() is n
            So the number of elements that <= x should be equal to x if
            there no duplicates exist, otherwise, there occur duplicate 
            and use binary search to determine the real value.
                        l: 2
            [1,3,4,2,2]
                        r: 2   
        */
        int l = 1, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (count(nums, m) <= m) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
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
        cout << "Res: " << S1.findDuplicate(nums) << endl;
    }
}