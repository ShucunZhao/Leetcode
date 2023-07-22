/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node * pre = NULL;
        Node * next = NULL;
        Node():key(0),val(0){}
        Node(int keyIn, int valIn):key(keyIn),val(valIn){}
    };
    unordered_map<int, Node*> ms;//<key, value node>
    int size = 0;
    int capacity = 0;
    Node * head = NULL;//This two ones are dummy head and tail nodes for adding and removing node.
    Node * tail = NULL;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    void showList(){
        cout<<"size: "<<size<<", head: ["<<head->key<<","<<head->val<<"]"<<", tail: ["<<tail->key<<","<<tail->val<<"]"<<endl;
        Node * cur = head;
        while(cur){
            cout<<"["<<cur->key<<","<<cur->val<<"]"<<endl;
            cur = cur->next;
        }
        return;
    }
    int get(int key) {
        if(ms.count(key)==0) return -1;
        put(key, ms[key]->val);
        return ms[key]->val;
    }
    /*
        ["LRUCache","get","put","get","put","put"]
        [[2],        [2], [2,6],[1],   [1,5],[1,2]]
    */
    void addFromHead(Node * newN){
        Node * cur = head->next;
        newN->next = cur;
        cur->pre = newN;
        head->next = newN;
        newN->pre = head;
    }
    void removeFromTail(){
        Node * tmp = tail->pre;
        // cout<<"tail->pre:"<<"["<<tail->pre->key<<","<<tail->pre->val<<"]"<<endl;
        // cout<<"tail->pre->pre:"<<"["<<tail->pre->pre->key<<","<<tail->pre->pre->val<<"]"<<endl;
        tail->pre = tail->pre->pre;
        tail->pre->next = tail;
        ms.erase(tmp->key);
        delete tmp;
        size--;
    }
    void put(int key, int value) {
        /*
                 New
            head    cur    tar
        */
        if(ms.count(key)>0){
            Node * tar = ms[key];
            tar->val = value;
            tar->pre->next = tar->next;
            tar->next->pre = tar->pre;
            addFromHead(tar);
            // showList();
            return;
        }
        Node * newN = new Node(key, value);
        addFromHead(newN);
        ms[key] = newN;
        size++;
        if(size>capacity){
            removeFromTail();
        }
        // showList();
    }
};

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */