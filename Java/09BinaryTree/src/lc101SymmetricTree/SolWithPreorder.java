package lc101SymmetricTree;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPreorder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter tree nodes: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            TreeNode root = null;
            if(!In.equals("")){
                String[] Ins = In.split(",");
                int[] nums = new int[Ins.length];
                for(int i=0;i<Ins.length;++i){
                    if(Ins[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(Ins[i].trim());
                }
                root = construct(nums);
            }
            System.out.println("Res: "+S1.isSymmetric(root));
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
        public boolean isSymmetric(TreeNode root) {
            if(root==null) return true;
            return cmpN(root.left, root.right);
        }
        public boolean cmpN(TreeNode left, TreeNode right){
            if(left==null&&right==null) return true;
            else if(left==null&&right!=null) return false;
            else if(left!=null&&right==null) return false;
            else if(left.val!=right.val) return false;
            return cmpN(left.left,right.right)&&cmpN(left.right, right.left);
        }
    }
}