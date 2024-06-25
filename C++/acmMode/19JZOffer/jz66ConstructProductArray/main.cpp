#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> multiply(vector<int>& A) {
        // write code here
        vector<int> prefix(A.size(), 1), suffix(A.size(), 1);
        for (int i = 1; i < A.size(); ++i) {
            prefix[i] = prefix[i-1]*A[i - 1];
            //[1,2,3,4,5]
            // 1 1 
        }
        for (int i = suffix.size() - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * A[i + 1];
        }
        for (int i = 0; i < A.size(); ++i) prefix[i] *= suffix[i];
        return prefix;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the array:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> A;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                A.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        vector<int> res = S1.multiply(A);
        cout << "Ans: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}