class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str=="") return "";
        while(n>str.size()){
            n-=str.size();
        }
        string ans;
        for(int i=n;i<str.size();i++){
            ans+=str[i];
        }
        for(int j=0;j<n;j++){
            ans+=str[j];
        }
        return ans;
    }
};