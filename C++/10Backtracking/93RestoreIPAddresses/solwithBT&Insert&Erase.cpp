class Solution {
public:
    int cntDot = 0;
    vector<string> ans;
    bool isValid(string & s, int l, int r){
        if(r-l+1>1&&s[l]=='0') return false;
        if(r-l+1>3) return false;
        string tmp = s.substr(l, r-l+1);
        return stoi(tmp)<=255;
    }
    void backtracking(string & s, int start){
        /* 
             s
              i
            "2.5525511135"
        */
        if(cntDot==3){
            if(isValid(s, start, s.size()-1)){
                ans.push_back(s);
            }
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isValid(s, start, i)){
                if(i+1>=s.size()){
                    break;
                }
                s.insert(i+1, 1, '.');
                i++;
                cntDot++;
                backtracking(s, i+1);
                s.erase(i, 1);
                cntDot--;
                i--;
            }
        }
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        //s.insert(0, 1, '.');
        //cout<<s<<endl;
        backtracking(s, 0);
        return ans;
    }
};