/*
题目来源：
https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
解答：
*/

/*
利用depth变量来反转 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<vector<int>> ret;
        int depth = 0;
        while(!que.empty()){
            int length = que.size();
            vector<int> vec;
            for(int i = 0; i < length; i ++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node -> val);
                if(node -> left){
                    que.push(node -> left);
                }
                if(node -> right){
                    que.push(node -> right);
                } 
            }
            if(depth % 2 == 1){
                reverse(vec.begin(), vec.end());
            }
            ret.push_back(vec);
            depth ++;
        }
        return ret;
    }
};
