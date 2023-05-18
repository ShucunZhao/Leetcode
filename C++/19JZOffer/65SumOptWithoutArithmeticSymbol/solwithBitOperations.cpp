class Solution {
public:
    int Add(int num1, int num2) {
        /*
                    num1       num2
                     3     +    5
                     11    +    101

              int n: 0^1 = 1
              int c: 0&1 then << 1

              so the sum = num1 + num2
                         =   n  +   c  
              we need to loop each bit from right to left
              until the result of c is 0, then return the n
              as answer.                      
        */
        //We let num1 as n and num2 as c.
        int sum = num1;//11
        int c = num2;//101
        while(c){//101,10,100,1000
            int tmp = sum^c;//110,100,000,1000
            c = (sum&c)<<1;//10,100,1000,0
            sum = tmp;//110,100,0,1000           
            //cout<<"c:"<<c<<endl;
            //cout<<"n:"<<sum<<endl;
        }
        return sum;
    }
};