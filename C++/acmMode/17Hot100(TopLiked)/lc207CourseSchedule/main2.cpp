class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            numCourses = 2, prerequisites = [[1,0],[0,1]]

                  0   1
              0       1   
              1   1
                         0  1
            inDegree:   [1, 1]
        */
        vector<int> inDegree(numCourses, 0);
        vector<vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
        for (vector<int >& tmp : prerequisites) {
            int pre = tmp[1];//1
            int cur = tmp[0];//0
            inDegree[cur]++;
            graph[pre][cur] = true;
        }
        queue<int> Q;
        for (int i = 0; i < numCourses;++i) {
            if (inDegree[i] == 0) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int pre = Q.front();//1
            Q.pop();
            for (int j = 0; j < numCourses; ++j) {
                if (graph[pre][j]) {
                    inDegree[j]--;
                    if (inDegree[j] == 0) Q.push(j);
                }
            }
        }
        for (int& i : inDegree) {
            if (i > 0) return false;
        }
        return true;
    }
};