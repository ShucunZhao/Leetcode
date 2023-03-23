class Solution {
public:
        /*
            s = "3[a2[c]]"
        dfs1:     a2[c]
        dfs2:     a + cc
        dfs3:    3[acc]
        dfs4:    accaccacc     
        */
    string dfs(string & s, int & index){
        string str;
        while(index<s.size()){
            if(isdigit(s[index])){
                int num = 0;
                while(index<s.size()&&isdigit(s[index])){
                    num = num*10+(s[index]-'0');
                    index++;
                }
                index++;
                // cout<<"num:"<<num<<",index:"<<index<<endl;
                string tmp = dfs(s, index);
                while(num--){
                    str+=tmp;
                }
                // cout<<"str:"<<str<<endl;
            }
            else if(s[index]==']'){
                index++;
                return str;
            }
            else{
                str+=s[index];
                index++;
            }
        }
        return str;
    }
    string decodeString(string s) {
        int index = 0;
        return dfs(s, index);
    }
};