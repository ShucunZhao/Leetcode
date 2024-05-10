#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int>& nums) {
        // write code here
        /*
        *    l       
            [7,8,1,2,3,4,5,6]
               m r m       r   
            1.Find which half is continous and which part is reverse part
            2.The minimum is showed in the reverse part,
                and the minimum is the left-most element of the continous part 
                of this reverse part.
            3.So we need to check if meet the reverse part minimum by:
                Reverse part in Right of Mid:
                    nums[mid + 1] < nums[mid]
                Reverse part in Left of Mid:
                    nums[m - 1] > nums[m]
                     l
                    [1,0,1,1,1]
                         m   r
        */
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {//Means the continous part in the left
                if (m + 1 < nums.size() && nums[m + 1] < nums[m]) {
                    return nums[m + 1];
                }
                l = m + 1;
            }
            else {
                if (m >= 0 && nums[m - 1] > nums[m]) {
                    return nums[m];
                }
                r = m - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Eneter the nums:" << endl;
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
        cout << "Res: " << S1.minNumberInRotateArray(nums) << endl;
    }
}