/*
问题来源：
https://leetcode.cn/problems/same-tree/description/
解答：
https://programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF 
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL)  return false;
        else if(p != NULL && q == NULL)  return false;
        else if(p == NULL && q == NULL) return true;
        else if(p -> val != q -> val)   return false;

        bool outside = isSameTree(p -> left,q -> left);
        bool inside = isSameTree(p -> right, q -> right);

        return outside && inside;
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode* leftNode = que.front();que.pop();
            TreeNode* rightNode = que.front();que.pop();
            if(!leftNode && !rightNode) {
                continue;
            }
            if(!leftNode || !rightNode || (leftNode -> val != rightNode -> val)){
                return false;
            }
            que.push(leftNode->left);
            que.push(rightNode->left);
            que.push(leftNode->right);
            que.push(rightNode->right);
        }
        return true;
    }
};
