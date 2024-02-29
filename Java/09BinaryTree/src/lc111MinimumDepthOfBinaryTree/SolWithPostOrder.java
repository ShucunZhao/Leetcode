package lc111MinimumDepthOfBinaryTree;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPostOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter tree nodes:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            TreeNode root = null;
            if(!In.equals("")){
                String[] Ins = In.split(",");
                int[] nums = new int[Ins.length];
                for(int i=0;i<nums.length;++i){
                    if(Ins[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(Ins[i].trim());
                }
                root = construct(nums);
            }
            System.out.println("Res: "+S1.minDepth(root));
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
            if(childI<nodes.size()&&nodes.get(childI)!=null) cur.left = nodes.get(childI++);
            if(childI<nodes.size()&&nodes.get(childI)!=null) cur.right = nodes.get(childI++);
        }
        return root;
    }
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){}
        TreeNode(int val){this.val=val;}
        TreeNode(int val,TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static class Solution{
        public int minDepth(TreeNode root) {
            if(root==null) return 0;
            if(root.left!=null&&root.right!=null){
                return Math.min(minDepth(root.left), minDepth(root.right))+1;
            }
            else if(root.left==null&&root.right!=null){
                return minDepth(root.right)+1;
            }
            else if(root.left!=null&&root.right==null){
                return minDepth(root.left)+1;
            }
            else{
                return 1;
            }
        }
    }
}
