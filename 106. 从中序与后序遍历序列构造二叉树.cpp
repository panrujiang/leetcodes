/*
问题来源：
https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
解答：
https://programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
*/

/*
递归法（recursion algorithm） 
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return NULL;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        if(postorder.size() == 1) return root;

        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex ++){
            if(inorder[delimiterIndex] == rootValue) break;
        }
        vector<int> leftInorder(inorder.begin(),inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder,leftPostorder);
        root -> right = traversal(rightInorder,rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& Postorder, vector<int>& postorder) {
        if(Postorder.size()==0 || postorder.size() ==0) return NULL;
        return traversal(Postorder,postorder);
    }
};
