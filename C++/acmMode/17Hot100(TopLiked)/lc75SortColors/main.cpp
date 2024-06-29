#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            Sol with merge sort
        */
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;
        divide(l, r, ans, nums);
    }

    void sortColors2(vector<int>& nums) {
        /*
          Sol with two pointers
                      l 
            nums = [0,2,1]
                      r
        */
        int target = 0;
        int l = 0, r = 0;
        while (l < nums.size()) {
            while (r < nums.size()) {
                if (nums[r] == target) swap(nums[l++], nums[r++]);
                else r++;
            }
            target++;
            r = l;
        }
        return;
    }

    void divide(int l, int r, vector<int>& ans, vector<int>& nums) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        divide(l, m, ans, nums);
        divide(m + 1, r, ans, nums);
        merge(l, m, r, ans, nums);
    }
    //[9,5,2,7,12,4,3,1,11]
    void merge(int l, int m, int r, vector<int>& ans, vector<int> & nums) {
        int i = m + 1;
        int j = l;
        int k = l;
        while (l <= m && i <= r) {
            if (nums[l] < nums[i]) {
                ans[j++] = nums[l++];
            } 
            else {
                ans[j++] = nums[i++];
            } 
        }
        while(l<=m) ans[j++] = nums[l++];
        while(i<=r) ans[j++] = nums[i++];
        while (k <= r) {
            nums[k] = ans[k];
            k++;
        }
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
        S1.sortColors2(nums);
        cout << "Res: [";
        for (int& i : nums) cout << i << ",";
        cout << "]" << endl;
    }
}