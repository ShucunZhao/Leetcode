class Solution {
public:
    string multiply(string num1, string num2) {
        /*
            num1 = "123", num2 = "456"
                
                        012
                        123 j
                        456 i
        i  j
        2  2             18
        2  1            12
        2  0            6
        ----------------738-----------
        1  2            15
        1  1           10
        1  0           5
        ---------------615------------
        0  2           12  
        0  1           8
        0  0          4  
        --------------492------------------
        We know the multiple result of each two number will not surpass the sum of these two number, like:
        999*999 = 998,001 which size is 3+3.
        If the size of input num1 and num2 are m and n, the size of result should be (m+n)
        so we can assign a result vector which size is (m+n) to store:
             i: 0 1 2 3 4
              [ 0 0 0 0 0 ]
              [ 0 0 0 0 0 ]
              [ 0 0 0 0 0 ]
        */
        if(num1=="0"||num2=="0") return "0";
        vector<int> res((num1.size()+num2.size()), 0);
        for(int i=num1.size()-1;i>=0;i--){
            int n1 = num1[i]-'0';
            for(int j=num2.size()-1;j>=0;j--){
                int n2 = num2[j]-'0';
                int sum = (res[i+j+1]+n1*n2);
                res[i+j+1] = sum%10;
                res[i+j] += sum/10;
                /*
                for(int i : res) cout<<i<<",";
                cout<<endl;
                */
            }
        }
        string ans;
        for(int i : res){
            ans+=to_string(i);
        }
        int i = 0;
        while(i<ans.size()&&ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
    }
};