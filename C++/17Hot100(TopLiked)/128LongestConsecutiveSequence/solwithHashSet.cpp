class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        /*
            nums = [100,4,200,1, 3,  2]
            nums = [0,3,7,2,5,8,4,6,0,1]
            i:       0  1  2  3  4   5   
                                 i
            ser:    1   2  3  4 100 200
                                    i
                    0 0 1 2 3 4 5 6 7 8

        */
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int cnt = 1;
        int ans = 1;
        for(set<int>::iterator i=(st.begin());i!=st.end();i++){
            /*
            //Do the add operation in iterator to get next elem is invalid!
            cout<<*i<<",";
            i++;
            cout<<*i<<",";
            */
            int cur = *i;
            if(st.count(cur+1)!=0){
                cnt++;
            }
            else{
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        // cout<<endl;
        /*
        int ans = 1;
        int cnt = 1;
        for(int i=0;i<st.size()-1;i++){
            if(st[i]+1==st[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            ans = max(ans,cnt);
        }
        return ans;
        */
        return ans;
    }
};