#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int ans = 0;
    int mod = 1e9 + 7;
    int InversePairs(vector<int>& nums) {
        // write code here
        vector<int> res = dfs(nums);
        //cout << "Res: [";
        //for (int i : res) cout << i << ",";
        //cout << endl;
        return ans;
    }

    vector<int> dfs(vector<int> nums) {
        if (nums.size() == 1) return nums;
        size_t mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        left = dfs(left);
        right = dfs(right);
        vector<int> tmp(nums.size());
        int l = 0, r = 0;
        int index = 0;
        // 1,2,3
        while (l < left.size() && r < right.size()) {
            if (left[l] > right[r]) {
                tmp[index++] = right[r++];//Magic here to count
                ans+=(left.size()-l); //Because all elements in current left parts is larger than right current element, so we need to count the total elements of left part
                ans %= mod;
            }
            else tmp[index++] = left[l++];
        }
        while(l<left.size()) tmp[index++] = left[l++];
        while(r<right.size()) tmp[index++] = right[r++];
        return tmp;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        N = N.substr(1, N.size() - 2); 
        vector<int> nums;
        if (!N.empty()) {
            stringstream ss(N);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.InversePairs(nums) << endl;
    }
}