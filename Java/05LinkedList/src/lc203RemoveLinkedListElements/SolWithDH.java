package lc203RemoveLinkedListElements;
import java.util.Scanner;

public class SolWithDH {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the head of a linked list with format [x,x,x]: ");
            String headIn = scan.nextLine();
            if(headIn.equals("q")){
                break;
            }
            System.out.println("Enter the val: ");
            String valIn = scan.nextLine();
            if(valIn.equals("q")){
                break;
            }
            headIn = headIn.substring(1, headIn.length()-1);
            ListNode head = null;
            String[] headSet = headIn.split(",");
            if(headSet.length!=1){//If input [] the headSet would be "", whose length is 1.
                int[] nums = new int[headSet.length];
                for(int i=0;i<nums.length;i++){
                    nums[i] = Integer.parseInt(headSet[i]);
                }
                head = convertArray2List(nums);
            }
            int val = Integer.parseInt(valIn);
            ListNode res = S1.removeElements(head, val);
            printList(res);
        }
    }
    private static void printList(ListNode In){
        ListNode cur = In;
        System.out.print("[");
        while(cur!=null){
            System.out.print(cur.val+",");
            cur = cur.next;
        }
        System.out.println("]");
    }
    private static ListNode convertArray2List(int[] nums){
        ListNode dum = new ListNode(0);
        ListNode cur = dum;
        for(int i=0;i<nums.length;i++){
            cur.next = new ListNode(nums[i]);
            cur = cur.next;
        }
        return dum.next;
    }
    private static class ListNode{
        public int val = 0;
        public ListNode next = null;
        ListNode(){}
        ListNode(int In){
            this.val = In;
        }
        ListNode(int InVal, ListNode InNode){
            this.val = InVal;
            this.next = InNode;
        }
    }
    private static class Solution{
        public ListNode removeElements(ListNode head, int val) {
            /*
                                                    c
                   Input: head = dum [1,2,6,3,4,5,6], val = 6
                   Output: [1,2,3,4,5]

                         c
                   In: dum [7,7,7]    val: 7
             */
            ListNode dum = new ListNode(0, head);
            ListNode cur = dum;
            while(cur!=null&&cur.next!=null){
                if(cur.next.val==val){
                    cur.next = cur.next.next;
                }
                else {
                    cur = cur.next;
                }
            }
            return dum.next;
        }
    }
}
