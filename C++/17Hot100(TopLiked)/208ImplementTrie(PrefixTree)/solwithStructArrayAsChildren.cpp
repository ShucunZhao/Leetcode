class Trie {
private:
    struct Node{
        bool isWord = 0;
        struct Node * children[26];
    };
    Node * node;
public:
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        Node * cur = node;
        for(char c : word){
            int index = c-'a';
            if(cur->children[index]==NULL){
                cur->children[index] = new Node();
            }
            cur = cur->children[index];
        }
        cur->isWord = 1;   
    }
    
    bool search(string word) {
        Node * cur = node;
        for(char c : word){
            int index = c-'a';
            if(cur->children[index]==NULL){
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Node * cur = node;
        for(char c : prefix){
            int index = c-'a';
            if(cur->children[index]==NULL){
                return 0;
            }
            cur = cur->children[index];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */