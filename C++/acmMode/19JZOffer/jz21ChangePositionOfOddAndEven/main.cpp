#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        /*
            [2,4,6,5,7]
        */
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] % 2 == 0) {
                for (int j = i + 1; j < array.size(); ++j) {
                    if (array[j] % 2 == 1) {
                        int tmp = array[i];
                        array[i] = array[j];
                        for (int x = j; x > i + 1; x--) {
                            array[x] = array[x - 1];
                        }
                        array[i + 1] = tmp;
                        break;
                    }
                }
            }
        }
        return array;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter array: " << endl;
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
        vector<int> res = S1.reOrderArray(nums);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
;    }
}