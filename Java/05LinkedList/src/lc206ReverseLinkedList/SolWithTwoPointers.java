package lc206ReverseLinkedList;
import java.util.Scanner;

public class SolWithTwoPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the linked list with format: [x,x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            ListNode head = null;
            if(InSet.length>1) {
                int[] nums = new int[InSet.length];
                for (int i = 0; i < nums.length; i++) {
                    nums[i] = Integer.parseInt(InSet[i]);
                }
                head = Array2List(nums);
            }
            head = S1.reverseList(head);
            printList(head);
        }
    }
    public static void printList(ListNode head){
        System.out.print("[");
        while(head!=null){
            System.out.print(head.val+",");
            head = head.next;
        }
        System.out.println("]");
    }
    public static ListNode Array2List(int[] nums){
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
            this.val = 0;
            this.next = null;
        }
        ListNode(int inVal){
            this.val = inVal;
            this.next = null;
        }
        ListNode(int inval, ListNode inN){
            this.val = inval;
            this.next = inN;
        }
    }
    private static class Solution{
        public ListNode reverseList(ListNode head) {
            /*
                           p
                    head = N [1,2,3,4,5]
                              c
             */
            ListNode pre = null, cur = head;
            while(cur!=null){
                ListNode tmp = cur.next;
                cur.next = pre;
                pre = cur;
                cur = tmp;
            }
            return pre;
        }
    }
}
