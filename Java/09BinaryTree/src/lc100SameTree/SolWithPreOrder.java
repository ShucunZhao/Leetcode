package lc100SameTree;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPreOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter p tree nodes: ");
            String P = scan.nextLine();
            if(P.equals("q")) break;
            System.out.println("Enter q tree nodes: ");
            String Q = scan.nextLine();
            if(Q.equals("q")) break;
            P = P.substring(1, P.length()-1);
            Q = Q.substring(1, Q.length()-1);
            TreeNode p = null;
            TreeNode q = null;
            if(!P.equals("")){
                String[] Ps = P.split(",");
                int[] numsP = new int[Ps.length];
                for(int i=0;i<Ps.length;++i){
                    if(Ps[i].equals("null")) numsP[i] = -1;
                    else numsP[i] = Integer.parseInt(Ps[i].trim());
                }
                p = construct(numsP);
            }
            if(!Q.equals("")){
                String[] Qs = Q.split(",");
                int[] numsQ = new int[Qs.length];
                for(int i=0;i<Qs.length;++i){
                    if(Qs[i].equals("null")) numsQ[i] = -1;
                    else numsQ[i] = Integer.parseInt(Qs[i].trim());
                }
                q = construct(numsQ);
            }
            System.out.println("Res: "+S1.isSameTree(p,q));
        }
    }

    private static TreeNode construct(int[] nums){
        List<TreeNode> nodes = new ArrayList<>();
        for(int i : nums){
            if(i==-1) nodes.add(null);
            else nodes.add(new TreeNode(i));
        }
        TreeNode root = nodes.get(0);
        int childI = 1;
        for(int i=0;i<nodes.size();++i){
            TreeNode cur = nodes.get(i);
            if(childI<nodes.size()&&cur!=null) cur.left = nodes.get(childI++);
            if(childI<nodes.size()&&cur!=null) cur.right = nodes.get(childI++);
        }
        return root;
    }

    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){}
        TreeNode(int val){this.val=val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    private static class Solution{
        public boolean isSameTree(TreeNode p, TreeNode q) {
            return cmpN(p,q);
        }
        public boolean cmpN(TreeNode p, TreeNode q){
            if(p==null&&q==null) return true;
            else if(p==null&&q!=null) return false;
            else if(p!=null&&q==null) return false;
            else if(p.val!=q.val) return false;
            return cmpN(p.left,q.left)&&cmpN(p.right, q.right);
        }
    }
}
