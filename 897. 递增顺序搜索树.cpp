/*
题目来源：
https://leetcode.cn/problems/increasing-order-search-tree/description/
解答：
https://leetcode.cn/problems/increasing-order-search-tree/solutions/742210/fu-xue-ming-zhu-fen-xiang-er-cha-shu-san-hljt/
*/

/*
我的写法：
队列 
*/
class Solution {
private:
    queue<TreeNode*> que;
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }
        inOrder(root -> left);
        que.push(root);
        inOrder(root -> right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        TreeNode* DummyNode = new TreeNode(0,NULL,NULL), *cur = DummyNode;
        while(!que.empty()){
            cur -> right = que.front();
            cur -> left = NULL;
            cur = cur -> right;
            que.pop();
        }
        cur -> right = NULL;
        cur -> left = NULL;
        return DummyNode -> right;
    }
};
/*
中序遍历加动态数组 
*/
class Solution {
private:
    vector<TreeNode*> ret;
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }
        inOrder(root -> left);
        ret.push_back(root);
        inOrder(root -> right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        TreeNode* DummyNode = new TreeNode(0,NULL,NULL), *cur = DummyNode;
        for(TreeNode* node : ret){
           node -> left = NULL;
           node -> right = NULL;
           cur -> right= node;
           cur = node;
        }
        return DummyNode -> right;
    }
};

/*
动态数组的空间还是大了点
这里直接用pre来保存前一节点 
*/

class Solution {
    TreeNode* dummy = new TreeNode(0);
    TreeNode* pre = dummy;
public:
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        return dummy -> right;
    }
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root -> left);
        root -> left = NULL;
        pre -> right = root;
        pre = root;
        traverse(root -> right);
    }
};
