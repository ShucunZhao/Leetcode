class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /* Topological sort:
            numCourses = 5, prerequisites = [[1,4],[2,4],[3,1],[3,2]]
            1.inDegree array:           Degree:     0  1  1  2  0
                                        i:          0  1  2  3  4 
            2.Topo Map:     key:        value(List):
                             4          2->1->NULL
                             1          3->NULL
                             2          3->NULL 
            3.Queue(BFS):
                _
                0,4                  
                _
        */
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, list<int> > topoMap;
        for(int i=0;i<prerequisites.size();i++){
            topoMap[prerequisites[i][1]].push_front(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> Q;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                Q.push(i);
            }
        }
        while(!Q.empty()){
            int curKey = Q.front();
            //cout<<"curKey:"<<curKey<<endl;
            Q.pop();
            list<int> cur = topoMap[curKey];
            //cout<<"cur:"<<cur.front()<<endl;
            while(!cur.empty()){//Cannot use cur.front()!=NULL here becasue the value maybe 0 to meet this case.
                int tar = cur.front();
                //cout<<"tar:"<<tar<<endl;
                cur.pop_front();
                inDegree[tar]--;
                if(inDegree[tar]==0){
                    Q.push(tar);
                }
            }
            topoMap.erase(curKey);
        }
        for(int i=0;i<inDegree.size();i++){
            //cout<<i<<":"<<inDegree[i]<<",";
            if(inDegree[i]!=0) return 0;
        }
        //cout<<endl;
        return 1;
    }
};