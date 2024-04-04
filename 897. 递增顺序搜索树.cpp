/*
��Ŀ��Դ��
https://leetcode.cn/problems/increasing-order-search-tree/description/
���
https://leetcode.cn/problems/increasing-order-search-tree/solutions/742210/fu-xue-ming-zhu-fen-xiang-er-cha-shu-san-hljt/
*/

/*
�ҵ�д����
���� 
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
��������Ӷ�̬���� 
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
��̬����Ŀռ仹�Ǵ��˵�
����ֱ����pre������ǰһ�ڵ� 
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
