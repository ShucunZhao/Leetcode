class Solution {
public:
    unordered_map<int, string> ms;
    Solution(){
        ms[0] = "";
        for(int i=0;i<26;i++){
            ms[i+1] = 'A'+i;
        }
        /*
        for(auto x : ms){
            cout<<x.first<<":"<<x.second<<endl;
        }
        */
    }
    string convertToTitle(int columnNumber) {
        /*
            columnNumber = 701
            701/26 =  26
            701%26 =  25
            ans = (26)+(25)


        */  
        if(columnNumber<=26){
            return ms[columnNumber];
        }
        string ans = ""; 
        int mod = 0;
        mod = columnNumber%26;//2
        columnNumber = columnNumber/26;//1
        // cout<<"columnNumber:"<<columnNumber<<","<<"mod:"<<mod<<endl;
        if(mod==0){
            ans+=(convertToTitle(columnNumber-1))+ms[26];
        }
        else{
            ans+=(convertToTitle(columnNumber))+ms[mod];
        }
        return ans;
    }
};