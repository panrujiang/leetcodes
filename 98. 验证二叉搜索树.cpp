/*
问题来源：
https://leetcode.cn/problems/validate-binary-search-tree/description/
解答：
https://programmercarl.com/0098.%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E6%80%9D%E8%B7%AF
*/

/*
搜索树中序遍历的特点 
*/
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == NULL) return ;
        traversal(root -> left);
        vec.push_back(root -> val);
        traversal(root -> right);
    }
public:
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i =0; i < vec.size() - 1; i++){
            if(vec[i] >= vec[i + 1])
             return false;
        }
        return true;
    }
};
