class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        /*
            n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
                realI:          1  2  3  4  5
                i:              0  1  2  3  4    
            indegree:           3  0  0  0  1
            opt:                0  0  0  0  1
                    graph:  
                                1:    5,
                                2     1,
                                3     1,
                                4     1,
                                5     N
            ans: 2
            size: 0
            k: 1 
            Q: 1
         -------------------------------------------
            n = 5, relations = [[1,5],[1,3],[1,2],[4,2],[4,5],[2,5],[1,4],[4,3],[3,5],[3,2]],  k = 3
                realI:          1  2  3  4  5
                i:              0  1  2  3  4    
            indegree:           0  3  2  1  4
            opt:                0  0  0  0  0
                    graph:  
                                1:    5,3,2,
                                2     5,
                                3     5,
                                4     2,5,3
                                5     N
            ans: 0
            size: 0
            k: 3 
            Q: 
             1                      
        */
        vector<int> indegree(n);
        unordered_map<int, list<int> > ms;
        for(int i=0;i<relations.size();i++){
            int preV = relations[i][0];
            int nextV = relations[i][1];
            int nextI = relations[i][1] - 1;
            indegree[nextI]++;
            ms[preV].push_back(nextV);
        }
        queue<int> Q;//Save the value whose indegree is 0.
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                Q.push(i+1);
            }
        }
        int size;
        int ans = 0;
        while(!Q.empty()){
            size = Q.size();
            ans++;
            int tmpK = k;
            while(size--){
                int cur = Q.front();
                Q.pop();
                if(tmpK==0){//Even though the course has no pointing, it also need to study then tmpK--;
                    tmpK=k;
                    ans++;
                }
                tmpK--;
                if(ms.count(cur)){
                    int next = ms[cur].front();
                    ms[cur].pop_front();
                    indegree[next-1]--;
                    if(indegree[next-1]==0){
                        Q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};