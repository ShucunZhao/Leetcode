package lc94BinaryTreeInorderTraversal;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithInorder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter tree node set with [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] nums = new int[InSet.length];
            for(int i=0;i<nums.length;++i){
                if(InSet[i].equals("null")) nums[i] = -1;
                else nums[i] = Integer.parseInt(InSet[i].trim());
            }
            TreeNode root = construct(nums);
            List<Integer> res = S1.inorderTraversal(root);
            System.out.print("Res: [");
            for(int i=0;i<res.size();++i) System.out.print(res.get(i)+",");
            System.out.println("]");
        }
    }
    private static TreeNode construct(int[] nums){
        List<TreeNode> nodes = new ArrayList<>();
        for(int i : nums){
            if(i!=-1) nodes.add(new TreeNode(i));
            else nodes.add(null);
        }
        TreeNode root = nodes.get(0);
        int childI = 1;
        for(int i=0;i<nodes.size();++i){
            TreeNode cur = nodes.get(i);
            if(cur!=null&&childI<nodes.size()){
                cur.left = nodes.get(childI);
                childI++;
            }
            if(cur!=null&&childI<nodes.size()){
                cur.right = nodes.get(childI);
                childI++;
            }
        }
        return root;
    }
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){};
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static class Solution{
        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList<>();
            inorder(root, ans);
            return ans;
        }
        public void inorder(TreeNode root, List<Integer> ans){
            if(root==null) return;
            inorder(root.left, ans);
            ans.add(root.val);
            inorder(root.right, ans);
        }
    }
}
