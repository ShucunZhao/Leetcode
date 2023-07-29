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
    Node * head = NULL;
    Node * dum;
    MyHashMap() {
        dum = new Node();
        dum->next = head;
    }
    /*
         "put", "get", "remove", "get"
         [2, 1], [2], [2], [2]
    */
    void put(int key, int value) {
        Node * cur = dum->next;
        if(!cur){
            dum->next = new Node(key, value);
            return;
        }
        if(cur->key==key){
            cur->val = value;
            return;
        }
        while(cur->next){
            if(cur->next->key == key){
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new Node(key, value);
    }
    /*
        ,"put","get","get","put","get","remove","get"
        ,[2,2],[1],[3],[2,1],[2],[2],[2]
    */
    int get(int key) {
        Node * cur = dum->next;
        while(cur){
            if(cur->key==key){
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node * cur = dum->next;
        if(!cur) return;
        if(cur->key==key){
            Node * tmp = cur;
            dum->next = cur->next;
            delete tmp;
            return;
        }
        while(cur->next){
            if(cur->next->key==key){
                Node * tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }
            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */