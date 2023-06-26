class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
            Graph:
                        0  1  2  3
                    0      1  1 
                    1            1
                    2            1 
                    3          

            indegree:   0 1 2 3  
                        0 0 0 0
            path:
                0,1,2,3            
        */
        vector<vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int In = prerequisites[i][1];
            int Out = prerequisites[i][0];
            graph[In][Out] = true;
            indegree[Out]++;
        }
        vector<int> path;
        while(true){
            bool change = false;
            for(int i=0;i<indegree.size();i++){
                if(indegree[i]==0){
                    change = true;
                    indegree[i]=-1;
                    path.push_back(i);
                    for(int j=0;j<graph[0].size();j++){
                        if(graph[i][j]){
                            indegree[j]--;
                        }
                    }
                }
            }
            if(!change){
                break;
            }
        }
        /*
        for(int i : path) cout<<i<<",";
        cout<<endl;
        */
        for(int i : indegree){
            if(i>0) return {};
        }
        return path;
    }
};