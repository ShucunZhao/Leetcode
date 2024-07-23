#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);//Record sun which lake in day i.
        set<int> sun;//Record No.i day
        unordered_map<int, int> ms;//Record the (No.lake, No.rain day) 
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                sun.insert(i); // 
            }
            else {
                ans[i] = -1;
                if (ms.count(rains[i])) {//Full before
                    int rainI = ms[rains[i]];
                    bool found = false;
                    for (auto j= sun.begin(); j != sun.end(); ++j) {
                        if (*j >= rainI) {
                            ans[*j] = rains[i];
                            sun.erase(j);
                            ms[rains[i]] = i;
                            found = true;
                            break;
                        }
                    }
                    if(!found) return {};
                }
                else {//First time to full
                    ms[rains[i]] = i;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    vector<int> ans;
    Solution S1;
    vector<int> rains = { 1,2,0,1,2 };
    vector<int> res = S1.avoidFlood(rains);
    cout << "Res: [";
    for (int& i : res) cout << i << ",";
    cout << "]" << endl;
}