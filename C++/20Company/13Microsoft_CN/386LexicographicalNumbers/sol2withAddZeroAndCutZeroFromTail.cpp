class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.push_back(1);
        int i = 1;
        while(ans.size()<n){
            if(i*10<=n){
                i*=10;
                ans.push_back(i);
            }
            else{
                while(i%10==9||i+1>n){
                    i/=10;
                }
                i+=1;
                ans.push_back(i);
            }
        }
        return ans;
    }
};