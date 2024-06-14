#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        /*
                [1,2,4,7,11,15],15
                ms: 1: 1
                    
        */
        unordered_map<int, int> ms;
        for (int& i : array) ms[i]++;
        for (int& i : array) {
            if (ms.count(sum - i)) {
                if (i == (sum - i)) {
                    if(ms[i] > 1) return { i,i };
                }
                else return { i, sum - i };
            }
        }
        return {};
    }
    vector<int> FindNumbersWithSum2(vector<int> array, int sum) {
        /*
        *       l
                [1,2,4,7,11,15],15
                             r

        */
        int l = 0, r = array.size() - 1;
        while (l < r) {
            if (array[l] + array[r] > sum) r--;
            else if (array[l] + array[r] < sum) l++;
            else return { array[l] , array[r] };
        }
        return {};
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter array:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter sum:" << endl;
        string S;
        getline(cin, S);
        if (S == "q") break;
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
        int sum = stoi(S);
        vector<int> res1 = S1.FindNumbersWithSum(nums, sum);
        cout << "Res1: ";
        for (int& i : res1) cout << i << ",";
        cout << endl;
        vector<int> res2 = S1.FindNumbersWithSum2(nums, sum);
        cout << "Res2: ";
        for (int& i : res2) cout << i << ",";
        cout << endl;
    }
}