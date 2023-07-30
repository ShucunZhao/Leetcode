class MyHashMap {
public:
    class Node{
    public:
        Node * next;
        int key;
        int val;
        Node():key(0),val(0),next(NULL){}
        Node(int k, int v):key(k),val(v),next(NULL){}    
    };
    static const int buckSize = 1024;
    vector<Node* > bucket;
    MyHashMap() {
        bucket.resize(1024);
    }
    int hashCode(int key){
        return key%buckSize;
    }
    /*
         "put", "get", "remove", "get"
         [2, 1], [2], [2], [2]
    */
    void put(int key, int value) {
        int hash = hashCode(key);
        if(bucket[hash]==NULL){
            Node * newN = new Node(key, value);
            bucket[hash] = newN;
            return;
        }
        Node * cur = bucket[hash];
        Node * pre;
        while(cur){
            if(cur->key==key){
                cur->val = value;
                return;
            }
            pre = cur;
            cur = cur->next;
        }
        pre->next = new Node(key, value);
    }
    /*
        ,"put","get","get","put","get","remove","get"
        ,[2,2],[1],[3],[2,1],[2],[2],[2]
    */
    int get(int key) {
        int hash = hashCode(key);
        Node * cur = bucket[hash];
        while(cur){
            if(cur->key==key) return cur->val;
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = hashCode(key);
        Node * cur = bucket[hash];
        if(cur!=NULL&&cur->key==key){
            Node * tmp = cur;
            bucket[hash] = cur->next;
            delete tmp;
            return;
        }
        Node * pre;
        while(cur){
            if(cur->key==key){
                Node * tmp = cur;
                pre->next = cur->next;
                delete tmp;
                return;
            }
            pre = cur;
            cur = cur->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */