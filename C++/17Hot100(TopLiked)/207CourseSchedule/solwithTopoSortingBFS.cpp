class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, list<int> > graph;
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_front(prerequisites[i][0]);
        }
        /*
             5, [[1,4],[2,4],[3,1],[3,2]]
              i:        0  1  2  3  4  
            indegree:   0  0  0  0  0

            graph:     0:  
                       1: 3
                       2: 3
                       3: 
                       4: 1,2
             ,3,3
            -------------------------------
                3, [[1,0],[1,2],[0,1]]
              i:        0  1  2  
            indegree:   1  1  0  

            graph:     0: 1, 
                       1: 0,
                       2: 1
                
                1
            
        */
        queue<int> Q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) Q.push(i);
        }
        while(!Q.empty()){
            int curVal = Q.front();
            Q.pop();
            list<int> curList = graph[curVal];
            while(!curList.empty()){
                int tar = curList.front();
                curList.pop_front();
                indegree[tar]--;
                if(indegree[tar]==0){
                    Q.push(tar);
                }
            }
            // graph.erase(curVal);
        }
        for(int i : indegree){
            if(i>0) return false;
        }
        return true;
    }
};