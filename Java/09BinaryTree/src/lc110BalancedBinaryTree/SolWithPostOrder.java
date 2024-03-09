package lc110BalancedBinaryTree;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPostOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter nodes:");
            String M = scan.nextLine();
            if(M.equals("q")) break;
            M = M.substring(1, M.length()-1);
            TreeNode root = null;
            if(!M.equals("")){
                String[] Ms = M.split(",");
                int[] nums = new int[Ms.length];
                for(int i=0;i<nums.length;++i){
                    if(Ms[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(Ms[i].trim());
                }
                root = construct(nums);
            }
            System.out.println("Res: "+S1.isBalanced(root));
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
        public int getMaxD(TreeNode root){
            if(root==null) return 0;
            int L = getMaxD(root.left);
            int R = getMaxD(root.right);
            return Math.max(L,R)+1;
        }
        public boolean isBalanced(TreeNode root) {
            if(root==null) return true;
            boolean left = isBalanced(root.left);
            boolean right = isBalanced(root.right);
            if(left==false||right==false) return false;
            int L = getMaxD(root.left);
            int R = getMaxD(root.right);
            if(Math.abs(L-R)>1) return false;
            return true;
        }
    }
}

