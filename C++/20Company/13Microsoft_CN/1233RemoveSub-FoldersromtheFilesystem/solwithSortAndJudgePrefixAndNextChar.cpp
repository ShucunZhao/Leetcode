class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        // for(string s : folder) cout<<s<<endl;
        
        for(int i=1;i<folder.size();i++){
            string pre = ans.back();
            int preLen = pre.size();
            string prefix = folder[i].substr(0, preLen);
            // char nextChar = folder[i][preLen];
        /*
            cout<<"pre:"<<pre;
            cout<<", prefix:"<<prefix;
            cout<<", nextChar:"<<folder[i][preLen]<<endl;
            */
            if(prefix==pre&&preLen<folder[i].size()&&folder[i][preLen]=='/'){
                continue;
            }
            ans.push_back(folder[i]);
        }
        
        return ans;
    }
};