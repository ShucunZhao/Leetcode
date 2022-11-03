class Solution {
public:
    vector<string> ans;
    int dotCnt = 0;
    bool isValid(string & s, int l, int r){
        if(l>r){//When the dot arrive at last the l and r index will be invalid so need to return false here!
            // cout<<"(l,r): "<<l<<","<<r<<endl;
            return 0;
        }
        if(s[l]=='0'&&r>l) return 0;
        long long sum = 0;
        for(int i=l;i<=r;i++){
            sum = sum*10 + (s[i]-'0');
            if(sum>255) return 0;
        }
        return 1;
    }
    void backtracking(string & s, int start){
        // if(start>s.size()-1) return;
        if(dotCnt==3){
            if(!isValid(s,start,s.size()-1)){
                return;
            }
            ans.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(!isValid(s,start,i)){
                break;
            }
            s.insert(s.begin()+i+1, '.');
            dotCnt++;//1
            backtracking(s, i+2);
            s.erase(s.begin()+i+1);
            dotCnt--;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return ans;
    }
};