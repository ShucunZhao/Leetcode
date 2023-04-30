class Solution {
public:
    string path;
    vector<string> ans;
    /*  
                    01
                    ab
          a

    */
    void backtracking(string str, vector<bool> & used1, vector<bool> & used2){
        if(path.size()==str.size()){//
            ans.push_back(path);
            return;
        }
        for(int i=0;i<str.size();i++){//i=0,
            if(i>0&&str[i]==str[i-1]&&!used2[i-1]) continue;
            if(used1[i]) continue;
            used1[i] = 1;//used[0]=1,
            used2[i] = 1;
            path.push_back(str[i]);
            backtracking(str, used1, used2);
            path.pop_back();
            used1[i]=0;
            used2[i]=0;
        }
        return;
    }
    vector<string> Permutation(string str) {
        vector<bool> used1(str.size(), false);
        vector<bool> used2(str.size(), false);
        sort(str.begin(), str.end());
        //cout<<str<<endl;
        backtracking(str, used1, used2);
        return ans;
    }
};