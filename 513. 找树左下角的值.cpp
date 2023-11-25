/*
问题来源：
https://leetcode.cn/problems/find-bottom-left-tree-value/description/
解答：
https://programmercarl.com/0513.%E6%89%BE%E6%A0%91%E5%B7%A6%E4%B8%8B%E8%A7%92%E7%9A%84%E5%80%BC.html#%E6%80%9D%E8%B7%AF
*/

/*
递归法，最大深度，最左边 
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
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root,int depth){
        if(!root -> left && !root -> right){
            if(depth > maxDepth){
                maxDepth = depth;
                result = root -> val;
            }
            return;
        }
        if(root -> left){
            depth ++;
            traversal(root -> left,depth);
            depth --;
        }
        if(root -> right){
            depth ++;
            traversal(root -> right,depth);
            depth --;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return result;
    }
};

/*
层序遍历 ，迭代法最优 
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > que;
        if(root) que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i =0; i < size; i ++){
                TreeNode * node = que.front();
                que.pop();
                if (i == 0) result = node -> val;
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
        }
        return result;
    }
};
