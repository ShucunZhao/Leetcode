class MyLinkedList {
public:
    class Node{
        public:
            int val;
            Node * next;
            Node(){
                val = 0;
                next = NULL;
            }
            Node(int In):val(In),next(NULL){}
    };
    Node * dum;
    Node * head;
    int sz = 0;
    MyLinkedList() {
        dum = new Node(0);
        head = NULL;
        dum->next = head;
        // cout<<"sz:"<<sz<<endl;
        // cout<<"val:"<<head->val<<endl;
    }
    
    int get(int index) {
        if(index<0||index>=sz) return -1;
        Node * cur = dum->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node * newN = new Node(val);
        newN->next = dum->next;
        dum->next = newN;
        sz++;
    }
    
    void addAtTail(int val) {
        Node * newN = new Node(val);
        Node * cur = dum;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = newN;
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        /*
             i: 2
                    c
             dum  1-2-2-3
        */
        if(index<0||index>sz) return;
        Node * newN = new Node(val);
        Node * cur = dum;
        while(index--){
            cur = cur->next;
        }
        newN->next = cur->next;
        cur->next = newN;
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=sz) return;
        Node * cur = dum;
        while(index--){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        sz--;
    }
};
/*
    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
      [[],[1],[3],[1,2],[1],[1],[1]]
*/
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */