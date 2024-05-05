#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int duplicate(vector<int>& numbers) {
        // write code here
        /*
            [2,3,1,0,2,5,3]
            [0,1,2,3,2,5,3]
        */
        for (int i = 0; i < numbers.size(); ++i) {
            while (numbers[i] != i) {
                if (numbers[numbers[i]] == numbers[i]) return numbers[i];
                swap(numbers[numbers[i]], numbers[i]);
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter numbers:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> numbers;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                numbers.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.duplicate(numbers) << endl;
    }
}