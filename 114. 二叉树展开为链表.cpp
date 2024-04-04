/*
题目来源：
https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
解答：
https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/17274/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/
https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/218689/114-er-cha-shu-zhan-kai-wei-lian-biao-by-ming-zhi-/
*/

/*
先按先序遍历把节点放到队列中
然后按照队列顺序依次连接成链表的样子 
*/
class Solution {
public:
    queue<TreeNode*> que;
    void preOrd(TreeNode* root){
        if(!root) return;
        que.push(root);
        preOrd(root -> left);
        preOrd(root -> right);
    }
public:
    void flatten(TreeNode* root) {
        preOrd(root);
        TreeNode* DummyNode = new TreeNode(0), *cur = DummyNode;
        while(!que.empty()){
            cur -> right = que.front();
            cur -> left = NULL;
            que.pop(); 
            cur = cur -> right;
        }
            cur -> right = NULL;
            cur -> left = NULL;
    }
};

/*
超级顶的写法。 
*/
class Solution {
    public void flatten(TreeNode root) {
        while(root != null){
            if(root.left == null){
                root = root.right;
            }else{
                TreeNode pre = root.left;
                while(pre.right != null){
                    pre = pre.right;
                }
                pre.right = root.right;
                root.right = root.left;
                root.left = null;
                root = root.right;
            }
        }
    }
}

/*
顶级遍历 
后序遍历 
*/
class Solution {
    private TreeNode pre = null;
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        flatten(root.right);
        flatten(root.left);
        root.right = pre;
        root.left = null;
        pre = root;
    }
}

/*
很好的递归 
*/
class Solution {
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        flatten(root.left);
        flatten(root.right);
        TreeNode tmp = root.right;
        root.right = root.left;
        root.left = null;
        while(root.right != null){
            root = root.right;
        }
        root.right = tmp;
    }
}
