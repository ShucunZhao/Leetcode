class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int key, vector<bool> & check){
        if(check[key]){
            return;
        }
        check[key] = true;
        vector<int> wait = rooms[key];
        for(int i : wait){
            dfs(rooms, i, check);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /*
           i:    0      1      2   3
           R:  [[1,3],[3,0,1],[2],[0]]
        */
        vector<bool> check(rooms.size(),false);
        dfs(rooms, 0, check);
        for(bool x : check){
            if(x==false) return false;
        }
        return true;
    }
};