/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length-1);
    }
    
    TreeNode construct(int [] nums, int s, int e){
        if(s>e){
            return null;
        }
        if(s==e){
            return new TreeNode(nums[s], null, null);
        }
        
        int idx = findMax(nums, s, e);
        TreeNode left = construct(nums, s, idx-1);
        TreeNode  right = construct(nums, idx+1, e);
        return new TreeNode(nums[idx], left, right);
        
        
    }
    
    int findMax(int [] nums, int s, int e){
        int max = nums[s];
        int st = s;
        
        for(int i=s;i<=e;i++){
            if(nums[i]>max){
                st = i;
                max = nums[i];
            }
        }
        return st;
        
    }
}
