#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            SOl: graph represent relationship, inDegree array represent indegree
                 queue for topo-sort
            Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
            Output: false

               0  1 
            0  x  1 
            1  1  x 
            -----------------------------------------------------
            Input: numCourses = 2, prerequisites = [[1,0]]
            Output: true
        */
        vector<vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
        vector<int> inDegree(numCourses);
        for (vector<int>& tmp : prerequisites) {
            int row = tmp[1], col = tmp[0];
            graph[row][col] = true;
            inDegree[col]++;
        }
        queue<int> Q;
        for (int i = 0; i < inDegree.size();++i) {
            if (inDegree[i] == 0) Q.push(i);
        }
        //Maybe something here?
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                int cur = Q.front();
                Q.pop();
                for (int j = 0; j < numCourses; ++j) {
                    if (graph[cur][j]) {
                        inDegree[j]--;
                        if (inDegree[j] <= 0) {
                            Q.push(j);
                        }
                    }
                }
            }
        }
        for (int& i : inDegree) {
            if (i > 0) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter numCourses: " << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int numCourses = stoi(N);
        cout << "Enter prerequisites: " << endl;
        string P;
        getline(cin, P);
        if (P == "q") break; 
        P = P.substr(2, P.size() - 4);
        size_t pos;
        vector<vector<int> > prerequisites;
        while ((pos = P.find("],[")) != string::npos) {
            string token = P.substr(0, pos);
            P = P.substr(pos + 3);
            stringstream ss(token);
            string token2;
            vector<int> tmp;
            while (getline(ss, token2, ',')) {
                size_t l = token2.find_first_not_of(" ");
                size_t r = token2.find_last_not_of(" ");
                tmp.push_back(stoi(token2.substr(l, r - l + 1)));
            }
            prerequisites.push_back(tmp);
        }
        stringstream ss(P);
        string token2;
        vector<int> tmp;
        while (getline(ss, token2, ',')) {
            size_t l = token2.find_first_not_of(" ");
            size_t r = token2.find_last_not_of(" ");
            tmp.push_back(stoi(token2.substr(l, r - l + 1)));
        }
        prerequisites.push_back(tmp);
        cout << "Res: " << S1.canFinish(numCourses, prerequisites) << endl;
    }
}