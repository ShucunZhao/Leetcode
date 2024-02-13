package lc19RemoveNthNodeFromEndOfList;
import java.util.Scanner;

public class SolWithFSPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the linked list with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            System.out.println("Enter the n: ");
            String N = scan.nextLine();
            if(N.equals("q")){
                break;
            }
            int n = Integer.parseInt(N);
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            ListNode head = null;
            if(!InSet.equals("")){
                int[] nums = new int[InSet.length];
                for(int i=0;i<InSet.length;++i){
                    nums[i] = Integer.parseInt(InSet[i]);
                }
                head = S1.removeNthFromEnd(array2List(nums), n);
            }
            printList(head);
        }
    }
    private static void printList(ListNode head){
        System.out.print("[");
        while(head!=null){
            System.out.print(head.val+",");
            head = head.next;
        }
        System.out.println("]");
    }
    private static ListNode array2List(int[] nums){
        ListNode head = new ListNode(nums[0]);
        ListNode cur = head;
        for(int i=1;i<nums.length;++i){
            cur.next = new ListNode(nums[i]);
            cur = cur.next;
        }
        return head;
    }
    private static class ListNode{
        public int val;
        public ListNode next;
        ListNode(){
            val = 0;
            next = null;
        }
        ListNode(int inVal){
            val = inVal;
            next = null;
        }
        ListNode(int inVal, ListNode inN){
            val = inVal;
            next = inN;
        }
    }
    private static class Solution{
        public ListNode removeNthFromEnd(ListNode head, int n) {
            /*             s
                    head = d [1], n = 1
                              f
             */
            ListNode dum = new ListNode(0);
            dum.next = head;
            ListNode f = dum, s = dum;
            while(n-->0){
                f = f.next;
            }
            while(f.next!=null){
                s=s.next;
                f=f.next;
            }
            s.next = s.next.next;
            return dum.next;
        }
    }
}
