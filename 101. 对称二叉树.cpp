/*
问题来源：
https://leetcode.cn/problems/symmetric-tree/description/
解答：
https://programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF 
*/

/*
递归法，后序 
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
    bool compare(TreeNode* left,TreeNode* right){
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left ->val != right ->val)  return false;

        bool outside = compare(left->left, right ->right);
        bool inside = compare(left->right, right ->left);
        bool isSame = outside && inside;
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compare(root->left,root->right);
    }
};

/*
迭代法 
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root -> left);
        que.push(root-> right);
        while(!que.empty()){
            TreeNode* leftNode = que.front();que.pop();
            TreeNode* rightNode = que.front();que.pop();
            if(!leftNode && !rightNode){
                continue;
            }
            if(!leftNode || !rightNode || (leftNode -> val != rightNode -> val)){
                return false;
            }
            que.push(leftNode -> left);
            que.push(rightNode -> right);
            que.push(leftNode -> right);
            que.push(rightNode -> left);
        }
        return true;
    }
};
