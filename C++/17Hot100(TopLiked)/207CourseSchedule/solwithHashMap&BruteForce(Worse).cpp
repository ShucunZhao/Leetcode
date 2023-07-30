class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
           /*
                , 3: 2
                5,    [[1,4],[2,4],[3,1],[3,2]]
                     0 1 2 3 4 
                  0   
                  1          1
                  2          1 
                  3    1 1
                  4  
             -------------------------------------
             1: 1 0: 1
                2,  [1,0],[0,1]]
                     0 1
                  0    1 
                  1  1   
             -------------------------------------
                0: 1 , 
                3,  [[0,1],[0,2],[1,2]]
                     0 1 2
                  0    1 0   
                  1      0
                  2                 
           */
           unordered_map<int, int> ms;
           vector<vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
           for(int i=0;i<prerequisites.size();i++){
               ms[prerequisites[i][0]]++;
               graph[prerequisites[i][0]][prerequisites[i][1]] = true;
           }
           bool check = true;
           while(check){
            check = false;
            for(int i=0;i<prerequisites.size();){
                int pre = prerequisites[i][1];
                int cur = prerequisites[i][0];
                if(ms.count(pre)==0){
                    check = true;
                    ms[cur]--;
                    if(ms[cur]==0){
                        ms.erase(cur);
                    }
                    //nums.erase(nums.begin() + index);
                    prerequisites.erase(prerequisites.begin()+i);
                    continue;
                }
                i++;
            }
        }
        return ms.empty();
    }
};