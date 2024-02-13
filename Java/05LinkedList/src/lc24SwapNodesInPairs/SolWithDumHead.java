package lc24SwapNodesInPairs;
import java.util.Scanner;

public class SolWithDumHead {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the linked list with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            ListNode head = null;
            if(!InSet[0].equals("")){
                int[] nums = new int[InSet.length];
                for(int i=0;i<nums.length;++i){
                    nums[i] = Integer.parseInt(InSet[i]);
                }
                head = array2List(nums);
            }
            head = S1.swapPairs(head);
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
            this.val = 0;
            this.next = null;
        }
        ListNode(int inval){
            this.val = inval;
        }
        ListNode(int inval, ListNode inN){
            this.val = inval;
            this.next = inN;
        }
    }
    private static class Solution{
        public ListNode swapPairs(ListNode head) {
            /*

                                c
                   N dum [2,1,4,3,5]
                               t
                                4
             */
            ListNode dum = new ListNode(0);
            dum.next = head;
            ListNode cur = dum;
            while(cur!=null&&cur.next!=null&&cur.next.next!=null){
                ListNode tmp = cur.next.next;
                cur.next.next = cur.next.next.next;
                tmp.next = cur.next;
                cur.next = tmp;
                cur = cur.next.next;
            }
            return dum.next;
        }
    }
}
