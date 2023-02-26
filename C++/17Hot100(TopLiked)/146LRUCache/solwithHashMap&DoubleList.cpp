class LRUCache {
private:
    class Node{
        public:
            int key,val;
            Node * pre, * next;
            Node():key(0),val(0),pre(NULL),next(NULL){}
            Node(int kIn, int vIn):key(kIn),val(vIn),pre(NULL),next(NULL){}
    };
    int cap;
    int size;
    Node * head, * tail;
    unordered_map<int, Node*> ms;
    // vector<Node*> delNset;
public:
    LRUCache(int capacity):cap(capacity),size(0){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        ms.clear();
    }
    ~LRUCache(){
        // for(Node * cur : delNset){
        //     delete cur;
        // }
        delete head;
        delete tail;
    }
    int get(int key) {
        if(ms.count(key)==0) return -1;
        Node * N = ms[key];
        remove(N);
        addFromHead(N);
        return N->val;
    }
    
    void put(int key, int value) {
        Node * N = new Node(key, value);
        if(ms.count(key)){
            Node * del = ms[key];
            remove(del);
            addFromHead(N);
        }
        else{
            if(size==cap){
                Node * del = tail->pre;
                ms.erase(del->key);
                remove(del);
                addFromHead(N);
                delete del;//Free memory!
            }
            else{
                addFromHead(N);
                size++;
            }
        }
        ms[key] = N;
    }

    void addFromHead(Node * N){
        N->pre = head;
        N->next = head->next;
        head->next->pre = N;
        head->next = N;
    }
    
    void remove(Node * N){
        // delNset.push_back(N);
        N->pre->next = N->next;
        N->next->pre = N->pre;
        // cout<<N->key<<","<<N->val<<endl;
        // delete tmp;
    }

    // void deleteSet(){
    //     for(Node * cur : delNset){
    //         delete cur;
    //     }
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */