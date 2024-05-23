#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    class cmp {
    public:
        bool operator()(int a, int b) {
            return a < b;
        }
    };
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // write code here
        priority_queue<int, vector<int>, cmp > pq;
        if (k == 0) return {};
        for (int i = 0; i < k; ++i) pq.push(input[i]);
        for (int i = k; i < input.size(); ++i) {
            if (input[i] < pq.top()) {
                pq.pop();
                pq.push(input[i]);
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

class Solution2 {
public:
    int target;
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        target = k;
        sort(input, 0, input.size() - 1);
        return vector<int>(input.begin(), input.begin()+k);
    }
    void sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = quickSort(nums, l, r);
        if (pivot == target) return;
        sort(nums, l, pivot - 1);
        sort(nums, pivot + 1, r);
    }
    int quickSort(vector<int> & nums, int l, int r) {
        /*
        *  l
        * [4,5,1,6,2,7,3,8]
        *                 r
        * ------------------
            pivot: 4
            l
                   l
            [3,2,1,4,6,7,5,8]
                   r
             -----------------
             left: quickSort(nums,l, pivot-1)
             right: quickSort(nums,pivot+1,r)
            pivot: 4
             l
            [3,2,1,4,6,7,5,8]
                   r
        */
        int pivot = nums[l];
        while (l < r) {
            while (l<r && nums[r] > pivot) r--;
            if (l == r) break;
            nums[l] = nums[r];
            l++;
            while (l < r && nums[l] <= pivot) l++;
            if (l == r) break;
            nums[r] = nums[l];
            r--;
        }
        nums[l] = pivot;
        return l;
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
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
        }
        int k = stoi(K);
        vector<int> res = S1.GetLeastNumbers_Solution(nums, k);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}