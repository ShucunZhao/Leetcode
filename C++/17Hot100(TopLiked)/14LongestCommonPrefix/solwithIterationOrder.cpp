class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /* 
            strs = ["flower","flow","flight"]
        */
        int j = 0;
        // bool stop = false;
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        while(true){
            for(int i=1;i<strs.size();i++){
                if(j>=strs[i].size()||strs[i][j]!=strs[i-1][j]){
                    return strs[0].substr(0,j);
                    //stop = true;
                    //break;
                }
            }
            // if(stop){
            //     break;
            // }
            j++;
        }
        // cout<<"j:"<<j<<endl;
        // return j==0?"":;
        return "";
    }
};