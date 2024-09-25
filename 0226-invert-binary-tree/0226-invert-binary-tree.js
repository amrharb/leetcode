/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    // Base case: if the root is null, return null
    if (root === null) {
        return null;
    }

    // Swap the left and right children
    [root.left, root.right] = [root.right, root.left];

    // Recursively invert the left and right subtrees
    invertTree(root.left);
    invertTree(root.right);

    return root; // Return the inverted tree
};