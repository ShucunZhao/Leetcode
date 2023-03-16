class Trie {
private:
    struct Node{
        bool isWord = 0;
        unordered_map<char, Node*> children;
    };
    Node * node;
public:
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        Node * cur = node;
        for(char c : word){
            if(cur->children.count(c)==0){
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->isWord = 1;   
    }
    
    bool search(string word) {
        Node * cur = node;
        for(char c : word){
            if(cur->children.count(c)==0){
                return 0;
            }
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Node * cur = node;
        for(char c : prefix){
            if(cur->children.count(c)==0){
                return 0;
            }
            cur = cur->children[c];
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