/*
问题来源：
https://leetcode.cn/problems/subtree-of-another-tree/description/
解答：
https://leetcode.cn/problems/subtree-of-another-tree/solutions/1993010/by-8hasefu1-ek0y/
https://leetcode.cn/problems/subtree-of-another-tree/solutions/235634/dui-cheng-mei-pan-duan-zi-shu-vs-pan-duan-xiang-de/
https://leetcode.cn/problems/subtree-of-another-tree/solutions/791035/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-sd29/
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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q)    return true;
        if(p && q && p -> val == q -> val){
            return isSameTree(p->left,q->left) && isSameTree(p -> right, q -> right);
        }
        else 
            return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(isSameTree(root,subRoot))
            return true;
        
        return isSubtree(root -> left,subRoot) || isSubtree(root -> right,subRoot);
    }
};

