#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        // write code here
        /*
            Only 2,3,5 as the prime
            Example:
                6: 2*3
                8: 2*4
                14 is not: 2*7 because 7 is not
         1 2 3 4 5 6 7 8 9 10 11 12 13
         1,2,3,4,5,6,8,
         cur: 4
         minHeap:5,6,8,9,10,12,15,20
         hashSet:1,2,3,4,5,6,8,9,10,12,15,20
        */
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        unordered_set<long long> hset;
        pq.push(1);
        hset.insert(1);
        long long cur = 0;
        while (index--) {
            cur = pq.top();
            pq.pop();
            if (hset.count(2 * cur) == 0) {
                pq.push(2 * cur);
                hset.insert(2 * cur);
            }
            if (hset.count(3 * cur) == 0) {
                pq.push(3 * cur);
                hset.insert(3 * cur);
            }
            if (hset.count(5 * cur) == 0) {
                pq.push(5 * cur);
                hset.insert(5 * cur);
            }
        }
        return (int)cur;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string N;
        cout << "Enter number: " << endl;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        cout << "Res: " << S1.GetUglyNumber_Solution(n) << endl;
    }
}