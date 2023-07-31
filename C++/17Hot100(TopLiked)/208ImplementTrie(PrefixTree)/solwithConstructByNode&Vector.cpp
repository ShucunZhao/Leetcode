class Trie {
public:
    class Node{
    public:
        bool isWord;
        int size = 26;
        // vector<int> dp(2, 0);
        vector<Node*> children;
        Node():isWord(false){
            children.resize(26, NULL);
        }
    };
    Node * node;
    Trie():node(NULL) {
        
    }
    void insert(string word) {
        if(!node){
            node = new Node();
        }
        Node * cur = node;
        for(char c : word){
            int i = c-'a';
            // cout<<"i:"<<i<<endl;
            if(cur->children[i]==NULL){
                cur->children[i] = new Node();
            }
            cur = cur->children[i];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Node * cur = node;
        if(!cur) return false;
        for(char c : word){
            int i = c-'a';
            if(cur->children[i]==NULL){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Node * cur = node;
        if(!cur) return false;
        for(char c : prefix){
            int i = c-'a';
            if(cur->children[i]==NULL){
                return false;
            }
            cur = cur->children[i];
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */