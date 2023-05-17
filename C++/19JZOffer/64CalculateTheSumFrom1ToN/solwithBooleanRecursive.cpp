class Solution {
public:
    int Sum_Solution(int n) {
        /*
            Sol2 with recursive:
        */
        bool flag = (n>0)&&(n+=Sum_Solution(n-1));
        return n;        
    }
};