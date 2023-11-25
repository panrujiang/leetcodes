/*
问题来源：
https://leetcode.cn/problems/search-in-a-binary-search-tree/description/
解答：
https://programmercarl.com/0700.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%90%9C%E7%B4%A2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
经典递归 
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root -> val == val) return root;
        TreeNode* result;
        if(val > root -> val) result = searchBST(root -> right,val);
        if(val < root -> val) result = searchBST(root -> left,val);
        return result;
    }
};

/*
迭代法 
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(val > root -> val)
            root = root -> right;
            else if(val < root -> val) 
                root = root ->left;
            else return root;
        }
        return NULL;
    }
};
