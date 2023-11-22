/*
问题来源：
https://leetcode.cn/problems/count-complete-tree-nodes/description/
解答：
https://programmercarl.com/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.html#%E6%80%9D%E8%B7%AF
*/
/*
递归遍历的顺序为后序(左右中) 
*/
class Solution {
private:
    int getNodesNum(TreeNode* cur){
        if(!cur)    return 0;
        int leftNum = getNodesNum(cur->left);
        int rightNum = getNodesNum(cur->right);
        int treeNum = leftNum + rightNum + 1;
        return treeNum; 
    }
public:
    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};
/*
精简版 
*/
class Solution{
public:
	int countNodes(TreeNode* root){
		if (!root) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	} 
}; 

/*
层序遍历 
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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!= NULL) que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i ++){
                TreeNode* node = que.front();
                que.pop();
                result ++;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};

/*
根据完全二叉树的特征 
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0,rightDepth = 0;
        while(left){
            left = left -> left;
            leftDepth ++;
        }
        while(right){
            right = right -> right;
            rightDepth ++;
        }
        if(leftDepth == rightDepth){
            return (2<<leftDepth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
