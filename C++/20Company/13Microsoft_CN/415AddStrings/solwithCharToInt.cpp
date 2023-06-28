class Solution {
public:
    string addStrings(string num1, string num2) {
        /*
                     l             r
            num1 = "11", num2 = "123"
        */
        int l = num1.size()-1, r = num2.size()-1;
        int bit = 0, curSum = 0, curVal = 0;
        string ans;
        while(l>=0&&r>=0){
            // string s1 = num1.substr(l,1);
            // string s2 = num2.substr(r,1);
            // curSum = stoi(s1)+stoi(s2)+bit;
            curSum = (num1[l]-'0')+(num2[r]-'0')+bit;
            bit = curSum/10;
            curVal = curSum%10;
            ans.push_back(curVal+'0');
            // ans.insert(ans.begin(), curVal+'0');
            // ans = to_string(curVal) + ans;
            l--;
            r--;
        }
        while(l>=0){
            // string s1 = num1.substr(l,1);
            // curSum = stoi(s1)+bit;
            curSum = (num1[l]-'0')+bit;
            bit = curSum/10;
            curVal = curSum%10;
            ans.push_back(curVal+'0');
            // ans = to_string(curVal) + ans;
            // ans.insert(ans.begin(), curVal+'0');
            l--;
        }
        while(r>=0){
            // string s2 = num2.substr(r,1);
            // curSum = stoi(s2)+bit;
            curSum =(num2[r]-'0')+bit;
            bit = curSum/10;
            curVal = curSum%10;
            ans.push_back(curVal+'0');
            // ans = to_string(curVal) + ans;
            // ans.insert(ans.begin(), curVal+'0');
            r--;
        }    
        if(bit!=0){
            ans.push_back(bit+'0');
            // ans = to_string(bit) + ans;
            // ans.insert(ans.begin(), bit+'0');
        }    
        //cout<<ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};