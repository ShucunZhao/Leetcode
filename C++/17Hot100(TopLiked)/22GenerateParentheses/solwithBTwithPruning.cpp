class Solution {
public:
    void backtracking(int l, int r, int n, string & path, vector<string> & ans){
        if(path.size()==2*n){
            ans.push_back(path);
            return;
        }
        if(l<n){
            path.push_back('(');
            l++;
            backtracking(l,r,n,path,ans);
            path.pop_back();
            l--;
        }
        if(l>r&&r<n){
            path.push_back(')');
            r++;
            backtracking(l,r,n,path,ans);
            path.pop_back();
            r--;
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        /*
                                        n = 3 : ()
                                                        (
                            get(:((                        |                                                        get):()
           get(:(((           |                 get):(()                                 ---                get(:()(   |   get):())X
get(:((((X  |    get):((()    |      get(:(()(      |     get):(())                               get(:()((            |     get):()()  
    get(:((()(X   | get):((())--get(:(()((X|get):(()()--      get(:(())(|get):(()))X       get(:()(((X|get):()(()  -- get(:()()(|get):()())X
          get(:((())(X|get):((()))O--get(:(()()(X|get):(()())O--get(:(())((X|get):(())()O--get(:()(()(X|get):()(())O-get(:()()((X|get):()()()O                   
        -------------------------------------------
        Ans: ((())),(()()),(())(),()(()),()()()
        KeyPoints: 1.The number of left and right parentheses should less than n.
                   2.Store path to ans when length of path is equal to 2*n.
                   3.When the number of left parentheses should > right can add an ")" to path .
                   4.When the number of left parentheses < n can add an "(" to path.
                    
        */
        vector<string> ans;
        string path;
        backtracking(0,0,n,path,ans);
        return ans;
    }
};