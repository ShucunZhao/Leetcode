#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            nums =     [1,    1,    1], k = 2
            preSum:     1     2     3
            -----------------------------------
            sum[i,j] = k
            preSum[j] - preSum[i-1] = k
            preSum[j](on-right)-k = preSum[i-1](on-left)
        */
        unordered_map<int, int> ms;
        ms[0] = 1;
        int ans = 0;
        int preSum = 0;
        for (int& i : nums) {
            preSum += i;//(on-right, j)
            if (ms.count(preSum - k)) ans+=ms[preSum-k];
            ms[preSum]++;
        }
        return ans;
    }
};

class OnlyPreSumSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            nums =    [1,    1,    1], k = 2
            preSum:    1     2     3 
            -----------------------------------
                             i 
            nums =    [1,    2,    3], k = 3
                                   j
            preSum:    1     3     6
            for(int i=0;i<nums.size();++i){
                if(preSum[i]==k) ans++;
                for(int j=0;j<i;++j){
                    if((preSum[i]-preSum[j])==k) ans++;
                }
            }
        */
        vector<int> preSum(nums.size());
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (preSum[i] == k) ans++;
            for (int j = 0; j < i; ++j) {
                if ((preSum[i] - preSum[j]) == k) ans++;
            }
        }
        return ans;
    }
};

class BacktracingSolution {
public:
    int ans = 0;
    int cur = 0;
    int subarraySum(vector<int>& nums, int k) {
        /*
             [1,1,1] k:2
            1[1,1]  
            1,1[,1]   
            1,1,1[] 

            ans: 2
        */
        for (int i = 0; i < nums.size(); ++i) {
            cur = 0;
            backtracking(nums, i, k);
        }
        return ans;
    }
    void backtracking(vector<int>& nums, int start, int & k) {
        if (start == nums.size())  return;
        cur += nums[start];
        if (cur == k) ans++;
        backtracking(nums, start+1,k);
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
        cout << "Enter the k:" << endl;
        string K;
        getline(cin, K);
        if (K == "q") break;
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
        int k = stoi(K);
        cout << "Res: " << S1.subarraySum(nums, k) << endl;
    }
}