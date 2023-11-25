/*
问题来源：
https://leetcode.cn/problems/merge-two-binary-trees/description/
解答：
https://programmercarl.com/0617.%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
*/

/*
递归法，同时操纵两棵树 
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        root1 -> val += root2 -> val;

        root1 -> left = mergeTrees(root1->left, root2->left);
        root1 -> right = mergeTrees(root1 -> right, root2 -> right);
        return root1;
    }
};

/*
迭代法，层序遍历 
迭代法中，一般一起操作两个树都是使用队列模拟类似层序遍历，同时处理两个树的节点，
这种方式最好理解，如果用模拟递归的思路的话，要复杂一些。
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        queue<TreeNode* > que;
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1 -> val += node2 -> val;

            if(node1 -> left && node2 -> left){
                que.push(node1 -> left);
                que.push(node2 -> left);
            }
            if(node1 -> right && node2 -> right){
                que.push(node1 -> right);
                que.push(node2 -> right);
            }
            if(!node1 -> left && node2 -> left){
                node1 -> left = node2 -> left;
            }
            if(!node1 -> right && node2 -> right){
                node1 -> right = node2 -> right;
            }
        }
        return root1;
    }
};
