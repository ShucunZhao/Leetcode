class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;
        queue<string> Q;
        Q.push(beginWord);
        int path = 1;
        int size;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                string cur = Q.front();
                Q.pop();
                for(int i=0;i<cur.size();i++){
                    string tmp(cur);
                    for(char c='a';c<='z';c++){
                        tmp[i] = c;
                        if(tmp==endWord) return path+1;
                        if(wordSet.count(tmp)){
                            Q.push(tmp);
                            wordSet.erase(tmp);
                        }
                    }
                }
            }
            path++;
        }
        return 0;
    }
};