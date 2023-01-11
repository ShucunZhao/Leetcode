class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int size = senate.size();
        for(int i=0;i<size;i++){
            if(senate[i]=='R') R.push(i);
            else D.push(i);
        }
        //R:  _
        //D:  _5_
        while(!R.empty()&&!D.empty()){
            int r = R.front();
            int d = D.front();
            if(r<d){
                R.push(size+r);
            }else{
                D.push(size+d);
            }
            D.pop();
            R.pop();
        }
        return R.empty()?"Dire":"Radiant";
    }
};