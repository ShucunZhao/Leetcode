class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> Q;
        vector<bool> check(rooms.size(), false);
        check[0] = true;
        Q.push(0);
        while(!Q.empty()){
            vector<int> wait = rooms[Q.front()];
            Q.pop();
            for(int i : wait){
                if(!check[i]){
                    check[i] = true;
                    Q.push(i);
                }
            }
        }
        for(bool x : check){
            if(!x) return false;
        }
        return true;
    }
};