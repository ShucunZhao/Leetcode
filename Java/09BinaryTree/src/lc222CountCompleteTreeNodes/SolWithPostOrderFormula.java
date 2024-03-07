package lc222CountCompleteTreeNodes;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPostOrderFormula {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter tree nodes:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            TreeNode root = null;
            if(!In.equals("")){
                String[] Ins = In.split(",");
                int[] nums = new int[Ins.length];
                for(int i=0;i<Ins.length;++i){
                    if(Ins[i].equals("null")) nums[i]=-1;
                    else nums[i] = Integer.parseInt(Ins[i].trim());
                }
                root = construct(nums);
            }
            System.out.println("Res: "+S1.countNodes(root));
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
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static class Solution{
        public int getLD(TreeNode root){
            if(root==null) return 0;
            return getLD(root.left)+1;
        }
        public int getRD(TreeNode root){
            if(root==null) return 0;
            return getRD(root.right)+1;
        }
        public int countNodes(TreeNode root) {
            if(root==null) return 0;
            int L = getLD(root);
            int R = getRD(root);
            if(L==R) return (int)Math.pow(2, L)-1;
            int left = countNodes(root.left);
            int right = countNodes(root.right);
            return left+right+1;
        }
    }
}
