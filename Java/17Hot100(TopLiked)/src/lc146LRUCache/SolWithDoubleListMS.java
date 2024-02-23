package lc146LRUCache;
import java.util.Scanner;
import java.util.HashMap;

public class SolWithDoubleListMS {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        LRUCache lru = new LRUCache();
        while(true){
            System.out.println("Enter the command with format cmd,val,key: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            String[] InSet = In.split(",");
            String cmd = InSet[0];
            String parm1 = InSet[1];
            String parm2 = InSet[2];
            if(cmd.equals("LRUCache")){
                int capacity = Integer.parseInt(parm1);
                lru = new LRUCache(capacity);
            }
            else if(cmd.equals("put")){
                lru.put(Integer.parseInt(parm1), Integer.parseInt(parm2));
            }
            else if(cmd.equals("get")){
                System.out.println("Res: "+lru.get(Integer.parseInt(parm1)));
            }
            else{
                continue;
            }
            printLru(lru);
        }
    }
    private static void printLru(LRUCache lru){
        System.out.print("[");
        Node cur = lru.dumH.next;
        int size = lru.size;
        while(size-->0){
            int key = cur.key;
            int val = cur.val;
            cur = cur.next;
            System.out.print("["+key+","+val+"]");
        }
        System.out.println("]");
    }
    static class Node{//We need to store key and value here, or if we do the delete operation we cannot find the pair in ms to remove it
        int key;
        int val;
        Node pre;
        Node next;
        Node(){}
        Node(int key, int val){
            this.key = key;
            this.val = val;
        }
        Node(int key, int val, Node pre, Node next){
            this.key = key;
            this.val = val;
            this.pre = pre;
            this.next = next;
        }
    }
    static class LRUCache {
        HashMap<Integer, Node> ms;
        int capacity;
        int size;
        Node dumH;
        Node dumT;
        LRUCache(){
            ms = new HashMap<>();
            dumH = new Node();
            dumT = new Node();
            dumH.next = dumT;
            dumT.pre = dumH;
        }
        LRUCache(int cap){
            this.capacity = cap;
            ms = new HashMap<>();
            dumH = new Node();
            dumT = new Node();
            dumH.next = dumT;
            dumT.pre = dumH;
        }
        public void remove(Node cur){
            cur.next.pre = cur.pre;
            cur.pre.next = cur.next;
        }
        public void addAtHead(Node cur){
            cur.next = dumH.next;
            dumH.next.pre = cur;
            dumH.next = cur;
            cur.pre = dumH;
        }
        public int get(int key){
            if(!ms.containsKey(key)) return -1;
            Node cur = ms.get(key);
            remove(cur);
            addAtHead(cur);
            return cur.val;
        }
        public void put(int key, int value){
            if(ms.containsKey(key)){
                Node cur = ms.get(key);
                cur.val = value;
                remove(cur);
                addAtHead(cur);
            }
            else{
                Node cur = new Node(key, value);
                ms.put(key, cur);
                addAtHead(cur);
                size++;
            }
            if(size>capacity){
                Node rm = dumT.pre;
                remove(rm);
                ms.remove(rm.key);
                size--;
            }
        }
    }
}
