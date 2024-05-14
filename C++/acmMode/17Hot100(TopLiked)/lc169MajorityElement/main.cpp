#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            Sol with Moore Voting

            cur: 1
            cnt: 1
            nums = [2,2,1,1,1,2,2]
                            i
        */
        int cur = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != cur) {
                if (cnt == 0) {
                    cur = nums[i];
                    cnt = 1;
                }
                else {
                    cnt--;
                }
            }
            else {
                cnt++;
            }
        }
        return cur;
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
        cout << "Res: " << S1.majorityElement(nums) << endl;
    }
}