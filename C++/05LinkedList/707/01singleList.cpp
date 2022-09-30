/*
 * Single linked list version with dummy head.
 */
class MyLinkedList {
public:
    class Node{
    public:
        int val;
        Node * next;
        Node():val(0),next(NULL){}
        Node(int in):val(in),next(NULL){}
    };
    Node * head;
    Node * dum;
    size_t size;
    MyLinkedList():head(NULL),size(0){
        dum = new Node();
        dum->next = head;
    }
    
    void addAtHead(int val) {
        Node * newNode = new Node(val);
        newNode->next = dum->next;
        dum->next = newNode;
        size++;
    }
    
    int get(int index) {//3
        if(index<0||index>size-1||dum->next==NULL){//Key point here: When the head is NULL means the list is empty:
                                                  //so you need to return -1 as well.
            return -1;
        }
        Node * cur = dum->next;
        while(index--){
            cur=cur->next;
        }
         return cur->val;
    }    
    void addAtTail(int val) {
        Node * newNode = new Node(val);
        Node * cur = dum;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index>size||index<0){// 1 2 3
            return;
        }
        Node * newNode = new Node(val);// 0 
        Node * cur = dum;// 0
        while(index--){
            cur=cur->next;// 1 2 3  
        }
        newNode->next = cur->next;//
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>size-1){
            return;
        }
        Node * cur = dum;// '0' 1 2 3
        while(index--){// 2(1) 1(0)// 0 
            cur=cur->next;//1 2 
        }
        Node * temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
        cout<<"size:"<<size<<endl;
    }
  
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
