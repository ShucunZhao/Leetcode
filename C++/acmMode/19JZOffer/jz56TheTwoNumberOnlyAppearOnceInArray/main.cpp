#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& nums) {
        // write code here
        /*
            We need to find a mask to divive these number into two groups,
            and the mask can be find by the XOR operation between unique number: a^b
            let say the unique number a = 2, b = 3
            Final XOR result: 2 ^ 3 = 1
                             10
                                 11
            So we can figure out which bit is one to determine start with where these
            two number can be devide by & 1, here is the first position from right,
            if not 1 here we can move it right to find the first '1' bit
        */
        int xorV = 0;
        for (int& i : nums) xorV ^= i;
        int pos = 0;
        while (!((xorV >> pos) & 1)) pos++;
        int a = 0, b = 0;
        for (int & i : nums) {
            if (((i >> pos) & 1) == 1) a ^= i;
            else b ^= i;
        }
        if (a > b) return { b,a };
        return { a,b };
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
        vector<int> res = S1.FindNumsAppearOnce(nums);
        cout << "Res: "<< endl;
        for (int& i : res) {
            cout << i << ",";
        }
        cout << endl;
    }
}