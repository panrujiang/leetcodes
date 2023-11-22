/*
问题来源：
https://leetcode.cn/problems/sum-of-left-leaves/description/
解答：
https://programmercarl.com/0404.%E5%B7%A6%E5%8F%B6%E5%AD%90%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 0;

        int leftValue = sumOfLeftLeaves(root->left);
        if(root -> left && !root->left->left && !root -> left ->right){
            leftValue = root -> left->val;
        }
        int rightValue = sumOfLeftLeaves(root -> right);
        int sum = leftValue + rightValue;
        return sum;
    }
};
