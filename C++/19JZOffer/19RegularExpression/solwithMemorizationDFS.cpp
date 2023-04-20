class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    map<pair<string, string>, bool> ms;
    bool match(string str, string pattern) {
        // write code here
        /*
            There are three cases to matching str with regular pattern:
            Case1:
                Both of them have no regular symbol and just need to delete index
                by index and determine if they could be empty at last by dfs.
            Case2:
                There only "." symbol in pattern, in this case also need to delete
                both string current character and do the dfs.
            Case3:
                The current char is '*' in pattern, it also has two cases:
                    Case3.1: 
                        the previous char of current position of pattern isn't exist
                        in str, so we just delete the first two chars from current *
                        in pattern and keep str the same, then do the dfs.
                    Case3.2:
                        the previous char of current position is also the smae as the
                        str, so detele the previous char of str and keep the pattern
                        to next dfs.
        */
        if(pattern.empty()){
            return str.empty();
        }
        if(ms.count({str,pattern})) return ms[{str, pattern}];
        bool firstMatch = !str.empty()&&(str[0]==pattern[0]||pattern[0]=='.');
        if(pattern.size()>1&&pattern[1]=='*'){
            return ms[make_pair(str,pattern)] = match(str, pattern.substr(2))||(firstMatch&&match(str.substr(1), pattern));
        }
        return  ms[make_pair(str,pattern)] = firstMatch&&match(str.substr(1), pattern.substr(1));
    }
};