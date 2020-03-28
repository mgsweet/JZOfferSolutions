/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode constructTree(int [] pre, int [] in, 
                                  int preStart, int preEnd,
                                 int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return null;
        }
        TreeNode root = new TreeNode(pre[preStart]);
        for (int i = inStart; i <= inEnd; i++) {
            if (pre[preStart] == in[i]) {
                root.left = constructTree(pre, in,
                                           preStart + 1, preStart + i - inStart,
                                          inStart, i - 1);
                root.right = constructTree(pre, in,
                                           preStart + i - inStart + 1, preEnd,
                                           i + 1, inEnd);
                return root;
            }
        }
        return root;
    }
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        if (pre.length == 0 || in.length == 0 || pre.length != in.length) {
            return null;
        }
        
        return constructTree(pre, in, 0, pre.length - 1, 0, in.length - 1);
    }
}