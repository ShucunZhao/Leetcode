class Solution {
public:
    string path;
    vector<int> ans;
    void backtracking(int n, int num){
        if(num>n) return;
        for(char c='0';c<='9';c++){
            path.push_back(c);//100
            int tmp = stoi(path);//
            if(tmp<=n){
                ans.push_back(tmp);
            }
            backtracking(n, tmp);
            path.pop_back();
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        /*
             n = 13
            Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
        */
        for(char c='1';c<='9';c++){
            path.push_back(c);
            int num = stoi(path);
            if(num<=n){
                ans.push_back(num);
            }
            backtracking(n, num);
            path.clear();
        }
        return ans;
    }
};