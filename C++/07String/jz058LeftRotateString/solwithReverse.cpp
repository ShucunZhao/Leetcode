class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size()==0){//Key point1: Because the len of str can be 0,
                        //So if meet this condition return empty directly.
            return "";
        }
        while(n>str.size()){//Key point2: The size of given N can larger than
                            //size of str, which will cause invalid in next reverse
                            //step, so you need to increse the n by minus size because
                            //if n equal to size the string will reverse a circle that is 
                            //equivalent to original str. 
            n-=str.size();
        }
        //Last step: 
        //1.reverse previous n.
        //2.reverse the elements from n to last one.
        //3.reverse the whole string then get the answer.
        reverse(str.begin(), str.begin()+n);
        reverse(str.begin()+n, str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};