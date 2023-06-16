class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /*
                r
             l
            "dog cat cat dog"
        */
        // if(find(s.begin(), s.end(), ' ')==s.end()){
        //     if(pattern.size()!=s.size()) return false;
        //     for(int i=0;i<pattern.size();i++){
        //         if(pattern[i]!=s[i]) return false;
        //     }
        //     return true;
        // }
        s.push_back(' ');
        unordered_map<string, char> mp;
        unordered_map<char, string> ms;
        int l=0, r = 0;
        while(find(s.begin(), s.end(), ' ')!=s.end()){
            auto x = find(s.begin(), s.end(), ' ');
            r = x-s.begin();
            // cout<<"r:"<<r<<endl;
            string tmp(s.begin(), s.begin()+r);
            if(ms.count(pattern[l])>0&&ms[pattern[l]]!=tmp){
                return false;
            }
            if(mp.count(tmp)>0&&mp[tmp]!=pattern[l]){
                return false;
            }
            ms[pattern[l]] = tmp;
            mp[tmp] = pattern[l];
            l++;
            // cout<<"tmp:"<<tmp<<endl;
            s = s.substr(r+1);
            // cout<<"s:"<<s<<endl;            
        }
        // cout<<"l:"<<l<<endl;
        return l==pattern.size()?true:false;
    }
};