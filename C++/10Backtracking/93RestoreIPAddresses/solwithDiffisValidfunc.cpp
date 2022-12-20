class Solution {
public:
    vector<string> ans;
    int dot = 0;
    bool isValid(string & s, int l, int r){
        // cout<<"l:"<<l<<"r:"<<r<<endl;
        if(l>r) return 0;
        if(r-l>0){
            if(s[l]=='0') return 0;
            else{
                string tmp(s.begin()+l, s.begin()+l+r-l+1);
                // cout<<"tmp:"<<tmp<<endl;
                stringstream ss;
                long long tar;
                ss<<tmp;
                ss>>tar;
                if(tar>255){
                    // cout<<"tar:"<<tar<<endl;
                    return 0;
                }
            }
        }
        // cout<<"substr:"<<s.substr(l,r-l+1)<<endl;
        return 1;
    }
    void backtracking(string & s, int start){
        if(start>s.size()) return;
        if(dot==3){
            if(isValid(s, start, s.size()-1)){
                ans.push_back(s);
            }
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isValid(s, start, i)){
                s.insert(s.begin()+i+1,'.');
                dot++;
                backtracking(s, i+2);
                s.erase(s.begin()+i+1);//Backtarcking: delete the dot we add in previous floor.
                dot--;
            }
            else{
                break;
            }
            // if(dot>3) break;
        }
        // path.clear();
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return ans;
    }
};