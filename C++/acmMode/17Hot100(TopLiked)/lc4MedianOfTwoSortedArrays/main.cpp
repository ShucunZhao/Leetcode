#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
                              l               
            Input: nums1 = [1,2], nums2 = [3,4]
                                             r
            Output: 2.50000

            maxHeap(smaller value):   1,2
                              size:

            minHeap(larger value):    3,4
                             size:
        */
        priority_queue<double, vector<double>, greater<double> > minHeap;
        priority_queue<double, vector<double>, less<double> > maxHeap;
        int l = 0, r = 0;
        while (l < nums1.size() && r < nums2.size()) {
            int cur;
            if (nums1[l] < nums2[r]) cur = nums1[l++];
            else cur = nums2[r++];
            addElem(cur, minHeap, maxHeap);
        }
        while (l < nums1.size()) {
            addElem(nums1[l++], minHeap, maxHeap);
        }
        while (r < nums2.size()) {
            addElem(nums2[r++], minHeap, maxHeap);
        }
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        else if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2;
    }

    void addElem(int& cur, priority_queue<double, vector<double>, greater<double> >& minHeap, priority_queue<double, vector<double>, less<double> >& maxHeap) {
        if (minHeap.empty() && maxHeap.empty()) {
            minHeap.push(cur);
            return;
        }
        if (minHeap.size() <= maxHeap.size()) {
            if (!maxHeap.empty() && cur < maxHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(cur);
            }
            else {
                minHeap.push(cur);
            }
        }
        else {
            if (!minHeap.empty() && cur > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(cur);
;            }
            else {
                maxHeap.push(cur);
            }
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string N1;
        cout << "Enter the nums1:" << endl;
        getline(cin, N1);
        if (N1 == "q") break;
        string N2;
        cout << "Enter the nums2:" << endl;
        getline(cin, N2);
        if (N2 == "q") break;
        vector<int> nums1;
        vector<int> nums2;
        N1 = N1.substr(1, N1.size() - 2);
        N2 = N2.substr(1, N2.size() - 2);
        if (!N1.empty()) {
            stringstream ss(N1);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums1.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        if (!N2.empty()) {
            stringstream ss(N2);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums2.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.findMedianSortedArrays(nums1, nums2) << endl;
    }
}