#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubbleSort(nums);
        quickSort(nums);
        return nums;
    }

    void quickSort(vector<int>& nums) {
        /*
                   l
            [0,0,1,1,2,5]
                   r
             p
             pivot: 1
        */
        quick(nums, 0, nums.size() - 1);
        return;
    }
    void quick(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = pivot(nums, l, r);
        quick(nums, l, mid-1);
        quick(nums, mid + 1, r);
        return;
    }
    int pivot(vector<int>& nums, int l, int r) {
        if (l >= r) return l;
        int p = nums[l];
        while (l < r) {
            while (l<r && nums[r]>p) r--;
            if (l == r) break;
            nums[l++] = nums[r];
            while (l < r && nums[l] <= p) l++;
            if (l == r) break;
            nums[r--] = nums[l];
        }
        nums[l] = p;
        return l;
    }


    void mergeSort(vector<int>& nums) {
        vector<int> tmp(nums.size());
        divide(nums,tmp, 0, nums.size() - 1);
    }

    void divide(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        divide(nums, tmp, l, mid);
        divide(nums, tmp, mid + 1, r);
        merge(nums, tmp, l, mid, r);
    }

    void merge(vector<int>& nums, vector<int>& tmp, int l, int mid, int r) {
        int x = l;
        int left = l, right = mid+1;
        while (left <= mid && right <= r) {
            if (nums[left] < nums[right]) {
                tmp[x++] = nums[left++];
            }
            else {
                tmp[x++] = nums[right++];
            }
        }
        while (left <= mid) tmp[x++] = nums[left++];
        while (right <= r) tmp[x++] = nums[right++];
        for (int i = l; i <= r; ++i) nums[i] = tmp[i];
        return;
    }

    void bubbleSort(vector<int>& nums) {
        /*
        *    i
            [5,2,3,1]
                j
             2 3 1 5
        */
        for (int i = 0; i < nums.size(); ++i) {
            bool isSwap = false;
            for (int j = 0; j < nums.size() - i-1; ++j) {
                if (nums[j + 1] < nums[j]) {
                    swap(nums[j + 1], nums[j]);
                    isSwap = true;
                }
            }
            if (!isSwap) break;
        }
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
        vector<int> res = S1.sortArray(nums);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}