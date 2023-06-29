class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        /*
             deadends = ["0201","0101","0102","1212","2002"], target = "0202"
        */
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        string start = "0000";
        if(deadSet.count(start)) return -1;
        if(start==target) return 0;
        unordered_set<string> visited;
        visited.insert(start);
        queue<string> Q;//Queue for bread first searching.
        Q.push(start);
        int size;
        int step = 0;
        while(!Q.empty()){
            size = Q.size();
            step++;
            while(size--){
                string cur = Q.front();//0000
                Q.pop();
                for(int i=0;i<target.size();i++){
                    for(int j=-1;j<=1;j+=2){
                        // string next = cur;
                        char c = cur[i];//0,
                        cur[i] = ((cur[i]-'0'+j+10)%10)+'0';//9000,1000,0900,0100,0090,0010,0001,0009
                        /*
                        next[i] = ((next[i]-'0'+j+10)%10)+'0';
                        if(deadSet.count(next)||visited.count(next)){
                            continue;
                        }
                        if(next==target){
                            return step;
                        }
                        Q.push(next);//9000,1000,0900,0100,0090,0010,0001,0009
                        visited.insert(next);//0000,9000,1000,0900,0100,0090,0010,0001,0009
                        //cur[i] = c;//0000
                        */
                        if(deadSet.count(cur)||visited.count(cur)){
                            cur[i] = c;
                            continue;
                        }
                        if(cur==target){
                            return step;
                        }
                        Q.push(cur);//9000,1000,0900,0100,0090,0010,0001,0009
                        visited.insert(cur);//0000,9000,1000,0900,0100,0090,0010,0001,0009
                        cur[i] = c;//0000
                    }
                }
                // for(auto x : visited) cout<<"Set:"<<x<<",";
                // cout<<endl;
            }
        }
        return -1;
    }
};