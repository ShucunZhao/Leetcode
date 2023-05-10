class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        /*  
            "google"
            g:2
            o:2
            l:1
            e:1
        */
        unordered_map<char, int> ms;
        for(char c : str){
            ms[c]++;
        }
        for(int i=0;i<str.size();i++){
            if(ms[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};