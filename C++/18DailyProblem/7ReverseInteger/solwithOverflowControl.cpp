class Solution {
public:
    int reverse(int x) {
        bool neg = 0;
        if(x<0){
            neg = 1;
            //x = -1*x;
        } 
        int ans = 0;
        int bit = 10;
        int upper;
        if(neg) upper = pow(-2,31);
        else upper = pow(2,31)-1;
        //cout<<upper<<endl;
        //2147483647
        //96463243
        //964632435
        while(x!=0){
            int mod = x%10;
            if(!neg){
                if(ans>(upper/10)||ans==upper/10&&mod>7){
                    return 0;
                }
            }
            else{
                if(ans<upper/10||ans==upper/10&&mod<-8){
                    return 0;
                }
            }
            ans = ans*bit + mod;//3
            x/=10;//12
            // cout<<"ans:"<<ans<<endl;
            // cout<<"x:"<<x<<endl;
            // cout<<"bit:"<<bit<<endl;
        }
        //cout<<ans<<endl;
        return ans;
    }
};