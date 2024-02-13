package lc142LinkedListCycleII;
import java.util.Scanner;

public class SolWithFormula {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the linked list with format [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            System.out.println("Enter the entry position of linked list: ");
            String Pos = scan.nextLine();
            if(Pos.equals("q")){
                break;
            }
            int pos = Integer.parseInt(Pos);
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
            setCycle(head, pos);
            ListNode res = S1.detectCycle(head);
            if(res==null){
                System.out.println("No cycle.");
            }
            else{
                System.out.println("The entry of cycle is: "+res.val);
            }
        }
    }
    private static void setCycle(ListNode head, int pos){
        if(pos==-1){
            return;
        }
        ListNode cur = head, entry = head;
        while(pos-->0){
            cur = cur.next;
            entry = entry.next;
        }
        while(cur.next!=null){
            cur = cur.next;
        }
        cur.next = entry;
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
        public ListNode detectCycle(ListNode head) {
            /*                       s
                                     f
                                x
                                y
                    head =   [3,2,0,-4], pos = 1
                                |____|
             */
            if(head==null||head.next==null) return null;
            ListNode f = head, s = head;
            while(s!=null&&f!=null&&f.next!=null){
                f = f.next.next;
                s = s.next;
                if(f==s){
                    break;
                }
            }
            if(s==null||f==null||f.next==null) return null;
            s = head;
            while(s!=null&&f!=null){
                if(s==f) return s;
                s = s.next;
                f = f.next;
            }
            return null;
        }
    }
}
