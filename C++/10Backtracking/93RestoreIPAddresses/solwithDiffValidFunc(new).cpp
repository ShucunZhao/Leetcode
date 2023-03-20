class Solution {
public:
    int dot = 0;
    // string path; Use the original string as path directly!
    vector<string> ans;
    bool isValid(string s, int start, int i){
        string str = s.substr(start, i-start+1);
        // cout<<"str:"<<str<<endl;
        if(str.size()>1&&str[0]=='0'){
            return 0;
        }
        long long num = stoll(str);
        if(num>255){
            return 0;
        }
        return 1;
    }
    void backtracking(string s, int start){
        if(start==s.size()){
            return;
        }
        if(dot==3){
            if(isValid(s, start, s.size())){
                ans.push_back(s);
            }
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isValid(s, start, i)){
                s.insert(s.begin()+i+1, '.');//s = "1.0.1023."
                dot++;
            }
            else{
                break;
            }
            backtracking(s, i+2);
            s.erase(s.begin()+i+1);
            dot--;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return ans;
    }
};