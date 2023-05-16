class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        /*
            Sol1: simulation.
        */
        vector<bool> visited(n,false);
        int find = 0;//Count the dequeue quantity.
        int cnt;//Count the recorded times in each round.
        int index = 0;//The current index. 
        while(find+1<n){
            cnt = 0;
            while(cnt<m){
                if(!visited[index]){
                    cnt++;
                }
                index = (index+1)%n;
            }
            visited[(index-1+n)%n] = true;
            find++;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return i;
            }
        }
        return -1;
    }
};