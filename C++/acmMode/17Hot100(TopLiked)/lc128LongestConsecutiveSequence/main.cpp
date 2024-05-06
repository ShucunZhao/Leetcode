#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
            Find the start position of each segment of array by
            checking if the start-1 element exist(with a hash set),
            then calculate the length of each consecutive segment.
        */
        unordered_set<int> hset;
        unordered_set<int> isVisited;
        int ans = 0;
        for (int& i : nums) hset.insert(i);
        for (int& i : nums) {
            if (isVisited.count(i)) {
                continue;
            }
            if (hset.count(i - 1) == 0) {
                int cnt = 1;
                isVisited.insert(i);
                while (hset.count(i + 1)) {
                    cnt++;
                    isVisited.insert(i+1);
                    i++;    
                }
                ans = max(ans, cnt);
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
        cout << "Res: " << S1.longestConsecutive(nums) << endl;
    }
}