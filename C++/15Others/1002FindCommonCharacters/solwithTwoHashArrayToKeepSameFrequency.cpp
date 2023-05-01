class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*
            words = ["bella","label","roller"]
            1st:    b:1 e:1 l:2 a:1
            2nd:    l:2 a:1 b:1 e:1 
            3rd:    r:2 o:1 l:2 e:1 
        */
        vector<int> hash1(26, 0), hash2(26, 0);
        for(char c : words[0]){
            hash1[c-'a']++;
        }
        for(int i=1;i<words.size();i++){
            for(char c : words[i]){
                hash2[c-'a']++;
            }
            for(int i=0;i<26;i++){
                hash1[i] = min(hash1[i], hash2[i]);
                hash2[i] = 0;
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(hash1[i]--){
                string s;
                s+=(i+'a');
                ans.push_back(s);
            }
        }
        return ans;
    }
};