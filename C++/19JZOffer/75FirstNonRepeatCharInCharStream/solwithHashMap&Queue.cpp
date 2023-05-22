class Solution
{
public:
  //Insert one char from stringstream
    unordered_map<char, int> ms;
    queue<char> Q;
    void Insert(char ch) {
        ms[ch]++;
        Q.push(ch); 
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while(!Q.empty()){
            if(ms[Q.front()]==1){
                return Q.front();
            }
            Q.pop();
        }
        return '#';
    }
    /*
        "google"
    */
};
