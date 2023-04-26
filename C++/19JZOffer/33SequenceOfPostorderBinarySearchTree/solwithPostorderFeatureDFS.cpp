class Solution {
public:
    bool dfs(vector<int> & sequence, int l, int r){
        if(l>=r) return true;
        int rBegin;
        for(rBegin=0;rBegin<r;rBegin++){
            if(sequence[rBegin]>sequence[r]) break;
        }
        int lEnd = rBegin-1;
        int rEnd = rBegin;
        for(rEnd;rEnd<r;rEnd++){
            if(sequence[rEnd]<sequence[r]) break;
        }
        return rEnd==r&&dfs(sequence,l,lEnd)&&dfs(sequence,rBegin,rEnd-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()<1) return 0;
        return dfs(sequence, 0, sequence.size()-1);
        /*    
               i:    0 1 2 3  4 5  6                      
                    [5,7,6,9,11,10,8]
            1):   left:  [0,2]          mid: 6              right: [3,5]
                   |                                         |
            2):  left:[0,0] mid:1 right:[]            left:[0,0] mid:1 right:[]
                    (true)                                      (true)
        */

    }
};