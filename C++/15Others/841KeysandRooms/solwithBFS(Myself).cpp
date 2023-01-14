class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size()<2) return 1;
        queue<vector<int>*> Q;
        Q.push(&rooms[0]);
        // vector<int> tmp = *Q.front();
        // for(int i=0;i<tmp.size();i++){
        //     cout<<tmp[i]<<endl;                               
        // }
        vector<bool> ans(rooms.size(), 0);
        ans[0] = 1;
        while(!Q.empty()){
            vector<int> tmp = *Q.front();
            for(int i=0;i<tmp.size();i++){
                if(ans[tmp[i]]) continue;
                ans[tmp[i]] = 1;
                Q.push(&rooms[tmp[i]]);                                    
            }
            Q.pop();
        }
        for(bool a : ans){
            if(!a) return 0;
        }
        return 1;
        //i:        0      1      2   3
        //rooms = [[1,3],[3,0,1],[2],[0]]
        //size:   2
        //Q:      _[1,3]_
        //       
        //V:        1       1     0   1 
    }
};