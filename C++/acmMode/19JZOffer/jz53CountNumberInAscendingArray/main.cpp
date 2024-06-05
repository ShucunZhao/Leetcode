#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, bool findLeft, int k) {
        /*[1,2,3,3,3,3,4,5]*/
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > k) {
                r = m - 1;
            }
            else if(nums[m]<k){
                l = m + 1;
            }
            else {
                if (findLeft) {
                    if (m == l || nums[m - 1] < k) return m;
                    else r = m - 1;
                }
                else {
                    if (m == r || nums[m + 1] > k) return m;
                    else l = m + 1;
                }
            }
        }
        return -1;
    }
    int GetNumberOfK(vector<int>& nums, int k) {
        // write code here
        /*
            [1,2,3,3,3,3,4,5],3
        */
        int l = binarySearch(nums, true, k);
        int r = binarySearch(nums, false, k);
        if (l == -1 && r == -1) return 0;
        if (l == -1 || r == -1) return 1;
        return r - l + 1;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        cout << "Enter the k:" << endl;
        string K;
        getline(cin, K);
        if (K == "q") break;
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
        int k = stoi(K);
        cout << "Res: " << S1.GetNumberOfK(nums, k)<<endl;
    }
}