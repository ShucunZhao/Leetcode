#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            [1,8,6,2,5,4,8,3,7]
             
        */
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int curW = r - l;
            if (height[l] > height[r]) {
                ans = max(ans, curW * height[r]);
                r--;
            }
            else {
                ans = max(ans, curW * height[l]);
                l++;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the height: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> height;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while(getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                height.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.maxArea(height) << endl;
    }
}