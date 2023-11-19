/*
问题来源：
https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
解答：
https://www.bilibili.com/video/BV1UD4y1Y769/?spm_id_from=333.788.top_right_bar_window_custom_collection.content.click&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/1323631/acm-xuan-shou-tu-jie-leetcode-er-cha-shu-ckf4/
*/

/*
递归法 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        return max(maxDepth(root->right),maxDepth(root->left)) + 1;
    }
};

/*
Python
*/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        leftHeight = self.maxDepth(root.left)
        rightHeight = self.maxDepth(root.right)

        return max(leftHeight,rightHeight) + 1
