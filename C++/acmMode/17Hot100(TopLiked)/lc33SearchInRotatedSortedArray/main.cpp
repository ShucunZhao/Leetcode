#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*          0 1 2 3 4 5 6
            nums = [4,5,6,7,8,0,1,2], target = 0
                          m
            Core thought: cut the array with left part and right part,
                          determine which part is a continouously-array 
                          or cycle-array, then to determin move mid to 
                          left part or right part.
        */
        int l = 0, r = nums.size() - 1;
        int size = nums.size();
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == target) return m;
            if (nums[m] > nums[r]) {//Means left is continously
                if (nums[m] > target) {
                    if (nums[l] <= target) {
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
                else {
                    l = m + 1;
                }
            }
            else {//Means right is continously
                if (nums[m] > target) {
                    r = m - 1;
                }
                else {
                    if (nums[r] < target) {
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        cout << "Enter target:" << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
        vector<int> nums;
        N = N.substr(1, N.size());
        if (!N.empty()) {
            stringstream ss(N);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        int target = stoi(T);
        cout << "Res: " << S1.search(nums, target) << endl;
    }
}