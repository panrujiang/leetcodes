/*
问题来源：
https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
解答：
https://programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
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
        TreeNode* traversal(vector<int>& preorder,vector<int>& inorder){
            if(preorder.size() == 0) return NULL;
            int rootValue = preorder[0];
            TreeNode* root = new TreeNode(rootValue);

            if(preorder.size() == 1) return root;
            int delimiterIndex;
            for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex ++){
                if(inorder[delimiterIndex] == rootValue) break;
            }
            vector<int> leftInorder(inorder.begin(),inorder.begin() + delimiterIndex);
            vector<int> rightInorder(inorder.begin() + delimiterIndex+ 1, inorder.end());

            reverse(preorder.begin(),preorder.end());
            preorder.resize(preorder.size() - 1);
            reverse(preorder.begin(),preorder.end());

            vector<int> leftpreorder(preorder.begin(),preorder.begin() + leftInorder.size());
            vector<int> rightpreorder(preorder.begin() + leftInorder.size(), preorder.end());

            root -> left = traversal(leftpreorder,leftInorder);
            root -> right = traversal(rightpreorder,rightInorder);
            return root;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        return traversal(preorder,inorder);
    }
};
