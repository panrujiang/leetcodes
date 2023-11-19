/*
问题来源：
https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
解答：
https://programmercarl.com/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC 
*/
/*
后序递归 
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
    int getDepth(TreeNode* node){
        if(node == NULL) return 0;
        int leftDepth = getDepth(node -> left);
        int rightDepth = getDepth(node -> right);
        if(node -> left == NULL && node -> right != NULL){
            return 1 + rightDepth;
        }
        if(node -> left != NULL && node -> right == NULL){
            return 1 + leftDepth;
        }

        return min(leftDepth,rightDepth) + 1;

    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
/*
前序递归 
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
private:
    int result;
    void getdepth(TreeNode* node,int depth){
        if(node == nullptr){
            return;
        }
        if(!node->left && !node->right){
            result = min(result,depth);
        }
        if(node->left){
            getdepth(node->left,depth + 1);
        }
        if(node->right){
            getdepth(node->right,depth + 1);
        }
        return;
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        result = INT_MAX;
        getdepth(root,1);
        return result;
    }
};
