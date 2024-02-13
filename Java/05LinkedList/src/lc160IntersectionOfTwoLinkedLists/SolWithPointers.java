package lc160IntersectionOfTwoLinkedLists;
import java.util.Scanner;

public class SolWithPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter listA with format [x,x,x]:");
            String InA = scan.nextLine();
            InA = InA.substring(1, InA.length()-1);
            if(InA.equals("q")){
                break;
            }
            System.out.println("Enter listB with format [x,x,x]:");
            String InB = scan.nextLine();
            InB = InB.substring(1, InB.length()-1);
            if(InB.equals("q")){
                break;
            }
            String[] ASet = InA.split(",");
            String[] BSet = InB.split(",");
            ListNode headA = null, headB = null;
            if(!ASet[0].equals("")){
                int[] numsA = new int[ASet.length];
                for(int i=0;i<ASet.length;++i){
                    numsA[i] = Integer.parseInt(ASet[i]);
                }
                headA = array2List(numsA);
            }
            if(!BSet[0].equals("")){
                int[] numsB = new int[BSet.length];
                for(int i=0;i<BSet.length;++i){
                    numsB[i] = Integer.parseInt(BSet[i]);
                }
                headB = array2List(numsB);
            }
            printList(S1.getIntersectionNode(headA, headB));
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
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            /*
                          a
                 listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
                                               b
                   n = 1
             */
             ListNode A = headA;
             ListNode B = headB;
             while(A!=null&&B!=null){
                 A=A.next;
                 B=B.next;
             }
             int n = 0;
             boolean isA = false;
             if(B==null){
                 isA = true;
             }
             while(A==null&&B!=null){
                 B=B.next;
                 n++;
             }
             while(B==null&&A!=null){
                 A=A.next;
                 n++;
             }
             A = headA;
             B = headB;
             while(n-->0){
                 if(isA) {
                     A = A.next;
                 }
                 else{
                     B = B.next;
                 }
             }
             while(A!=null&&B!=null){
                 if(A==B){
                     return A;
                 }
                 A = A.next;
                 B = B.next;
             }
             return null;
        }
    }
}
