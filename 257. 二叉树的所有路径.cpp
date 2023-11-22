/*
问题来源：
https://leetcode.cn/problems/binary-tree-paths/description/
解答：
https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html#%E6%80%9D%E8%B7%AF 
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
        void traversal(TreeNode* cur,vector<int>& path,vector<string>& result){
            path.push_back(cur->val);
            if(cur->left == NULL && cur->right == NULL){
                string sPath;
                for(int i = 0;i < path.size() - 1;i ++){
                    sPath += to_string(path[i]);
                    sPath += "->";
                }
                sPath += to_string(path[path.size() - 1]);
                result.push_back(sPath);
                return;
            }
            if(cur -> left){
                traversal(cur->left,path,result);
                path.pop_back();
            }
            if(cur -> right){
                traversal(cur->right,path,result);
                path.pop_back();
            }
        }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == NULL) return result;
        traversal(root,path,result);
        return result;
    }
};
