package lc707DesignLinkedList;
import java.util.Scanner;

public class SolWithDumHead {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        MyLinkedList list = new MyLinkedList();
        while(true){
            System.out.println("Enter the command with format \"Command\" , \"Value\": ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            String[] InSet = In.split(",");
            String cmd = InSet[0];
            if(cmd.equals("MyLinkedList")){
                list = new MyLinkedList();
            }
            else if(cmd.equals("addAtHead")){
                int val = Integer.parseInt(InSet[1]);
                list.addAtHead(val);
                printList(list);
            }
            else if(cmd.equals("addAtTail")){
                int val = Integer.parseInt(InSet[1]);
                list.addAtTail(val);
            }
            else if(cmd.equals("addAtIndex")){
                int index = Integer.parseInt(InSet[1]);
                int val = Integer.parseInt(InSet[2]);
                list.addAtIndex(index, val);
            }
            else if(cmd.equals("get")){
                int index = Integer.parseInt(InSet[1]);
                int val = list.get(index);
                System.out.println("Res: "+val);
            }
            else if(cmd.equals("deleteAtIndex")){
                int index = Integer.parseInt(InSet[1]);
                list.deleteAtIndex(index);
            }
            printList(list);
        }
    }
    private static void printList(MyLinkedList list){
        System.out.print("[");
        int size = list.size;
        Node cur = list.dum;
        while(size-->0){
            System.out.print(cur.next.val+",");
            cur = cur.next;
        }
        System.out.println("]");
    }
    private static class Node{
        public int val;
        public Node next;
        Node(){
            this.val = 0;
            next = null;
        }
        Node(int inVal){
            this.val = inVal;
            this.next = null;
        }
        Node(int inVal, Node inN){
            this.val = inVal;
            this.next = inN;
        }
    }
    private static class MyLinkedList {
        public Node head;
        public Node dum;
        int size;
        public MyLinkedList() {
            this.head = null;
            this.dum = new Node(0);
            dum.next = head;
            this.size = 0;
        }

        public int get(int index) {
            if(index<0||index>=this.size) return -1;
            /*
                  c
                     0 1 2 3 4
                  d  1-2-3-4-5
                     h
             */
            Node cur = dum;
            while(index-->0){
                cur = cur.next;
            }
            return cur.next.val;
        }

        public void addAtHead(int val) {
            Node newN = new Node(val);
            newN.next = head;
            dum.next = newN;
            head = dum.next;
            size++;
        }

        public void addAtTail(int val) {
            Node newN = new Node(val);
            Node cur = dum;
            while(cur.next!=null){
                cur = cur.next;
            }
            cur.next = newN;
            size++;
        }
        public void addAtIndex(int index, int val) {
            if(index>this.size||index<0) return;
            Node newN = new Node(val);
            Node cur = dum;
            while(index-->0){
                cur = cur.next;
            }
            newN.next = cur.next;
            cur.next = newN;
            head = dum.next;
            size++;
        }

        public void deleteAtIndex(int index) {
            if(index<0||index>=this.size) return;
            Node cur = dum;
            while(index-->0){
                cur = cur.next;
            }
            cur.next = cur.next.next;
            head = dum.next;
            size--;
        }
    }
}
