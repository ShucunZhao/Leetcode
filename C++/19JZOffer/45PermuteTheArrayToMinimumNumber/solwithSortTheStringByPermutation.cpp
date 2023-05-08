class Solution {
public:
    static bool myCmp(string & s1, string & s2){
        // string cat1(s1+s2);
        // string cat2(s2+s1);
        return (s1+s2)<(s2+s1);
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(int i=0;i<numbers.size();i++){
            str.push_back(to_string(numbers[i]));
        }
        sort(str.begin(), str.end(), myCmp);
        string ans;
        for(string s : str){
            ans+=s;
        }
        return ans;
    }
};