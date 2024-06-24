#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        *  We fixed the width as 1(each position i of given array), and the maxHeight is the smaller one of
           the (leftHeighest and rightHeighest), the left-most and right-most height we can set as -1,
           if either side(left or right) height is smaller than current height that means it cannot trap
           rain here, and each time we need to use the maxHeight to subtract the curHeight(array[i]) to get
           the real valid height of current position.

           -1 [0,1,0,2,1,0,1,3,2,1,2,1] -1
                        i
           We can calculate the leftMost height and rightMost height in prior by conter and two arrays:
           st:2
           L:-1,0,1,1,2,2,2,2,3,3,3, 3
           R: 3,3,3,3,3,3,3,4,3,2,1,-1
              0 0 1 0 1 2 1 0 1 1 0  0 
          ans:1+

        */
        int curMaxH = -1;
        vector<int> L, R;
        L.push_back(-1);
        for (int i = 1; i < height.size(); ++i) {
            if (height[i - 1] > curMaxH) {
                curMaxH = height[i - 1];
            }
            L.push_back(curMaxH);
        }
        R.push_back(-1);
        curMaxH = -1;
        for (int i = height.size()-2; i >=0; --i) {
            if (height[i + 1] > curMaxH) {
                curMaxH = height[i + 1];
            }
            R.push_back(curMaxH);
;       }
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            int curH = height[i];
            int leftH = L[i];
            int rightH = R[height.size() - (i + 1)];
            if (leftH <= curH || curH >= rightH) {
                continue;
            }
            ans += (min(leftH, rightH) - curH);
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
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                height.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.trap(height) << endl;
    }
}