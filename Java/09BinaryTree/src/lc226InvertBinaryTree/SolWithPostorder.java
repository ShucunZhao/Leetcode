package lc226InvertBinaryTree;

import java.util.*;

public class SolWithPostorder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the tree nodes: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] Ins = In.split(",");
            TreeNode root = null;
            if(!In.equals("")){
                int[] nums = new int[Ins.length];
                for(int i=0;i<nums.length;++i){
                    if(Ins[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(Ins[i].trim());
                }
                root = construct(nums);
            }
            TreeNode res = S1.invertTree(root);
            System.out.println("Res: ");
            printTree(res);
        }
    }
    private static void printTree(TreeNode root){
        if(root==null) System.out.println("");
        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
        int size;
        while(!Q.isEmpty()){
            size = Q.size();
            while(size-->0){
                TreeNode cur = Q.poll();
                if(cur==null){
                    System.out.print(""+",");
                }
                else{
                    System.out.print(cur.val+",");
                    if(cur.left!=null) Q.add(cur.left);
                    if(cur.right!=null) Q.add(cur.right);
                }
            }
            System.out.println("");
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
        TreeNode(){};
        TreeNode(int val){this.val=val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static class Solution{
        public TreeNode invertTree(TreeNode root) {
            if(root==null) return null;
            TreeNode left = invertTree(root.left);
            TreeNode right = invertTree(root.right);
            root.left = right;
            root.right = left;
            return root;
        }
    }
}
