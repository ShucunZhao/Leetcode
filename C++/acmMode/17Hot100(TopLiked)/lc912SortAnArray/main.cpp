#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        bubbleSort(nums);
        return nums;
    }

    void bubbleSort(vector<int>& nums) {
        /*
        *    i
            [5,2,3,1]
                j
             2 3 1 5
        */
        for (int i = 0; i < nums.size(); ++i) {
            bool isSwap = false;
            for (int j = 0; j < nums.size() - i-1; ++j) {
                if (nums[j + 1] < nums[j]) {
                    swap(nums[j + 1], nums[j]);
                    isSwap = true;
                }
            }
            if (!isSwap) break;
        }
        return;
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
        vector<int> res = S1.sortArray(nums);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}