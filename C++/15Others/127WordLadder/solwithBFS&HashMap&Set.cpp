class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord)==0) return 0;
        queue<string> Q;
        unordered_map<string, int> ms;
        Q.push(beginWord);
        ms.insert(pair<string, int>(beginWord, 1));
        while(!Q.empty()){
            string curW = Q.front();
            Q.pop();
            int path = ms[curW];
            for(int i=0;i<curW.size();i++){
                string newW = curW;
                for(int j=0;j<26;j++){
                    newW[i] = j+'a';
                    if(newW==endWord) return path+1;
                    if(wordSet.count(newW)==1&&ms.count(newW)==0){
                        ms.insert(pair<string, int>(newW, path+1));
                        Q.push(newW);
                    }
                }
            }
        }
        return 0;
    }
};