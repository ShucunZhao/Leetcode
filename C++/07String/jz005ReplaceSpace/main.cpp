class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code 
        int cnt = 0;//Key point here: You must initial cnt to 0 at first!
        for(char c : s){
            if(c==' '){
                cnt++;
            }
        }
        int subSize = s.size();
        // cout<<"sub:"<<subSize<<endl;
        s.resize(subSize+cnt*2);
        // cout<<"new:"<<s.size()<<endl;
        for(int l=subSize-1,r=s.size()-1;l>=0;l--){
            if(s[l]==' '){
                s[r--]='0';
                s[r--]='2';
                s[r--]='%';
            }
            else{
                s[r--]=s[l];
            }
        }
        return s;
    }
};