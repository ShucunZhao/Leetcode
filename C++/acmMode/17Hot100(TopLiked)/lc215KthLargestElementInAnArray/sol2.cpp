class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
                 l
            [1,2,1,5,6,4]
                 r
            p: 3
        */
        quickSort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
    void quickSort(vector<int> & nums, int l, int r, int k) {
        if (l >= r) return;
        int m = pivot(nums, l, r);
        if (m == k - 1) return;
        quickSort(nums, l, m - 1, k);
        quickSort(nums, m + 1, r, k);
        return;
    }
    int pivot(vector<int>& nums, int l, int r) {
        if (l >= r) return l;
        int p = nums[l];
        while (l < r) {
            while (l<r&&nums[r] < p) r--;
            if (l == r) break;
            nums[l++] = nums[r];
            while (l < r && nums[l] >= p) l++;
            if (l == r) break;
            nums[r--] = nums[l];
        }
        nums[l] = p;
        return l;
    }
};