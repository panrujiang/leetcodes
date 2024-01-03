/*
��Ŀ��Դ��
https://leetcode.cn/problems/range-sum-of-bst/description/
���
https://leetcode.cn/problems/range-sum-of-bst/solutions/6703/hua-jie-suan-fa-938-er-cha-sou-suo-shu-de-fan-wei-/
*/
/*
�ݹ鷨������Ӧ���뵽�ݹ������� 
*/
class Solution {
private:
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        if(root -> val < low){
            return rangeSumBST(root -> right, low, high);
        }
        if(root -> val > high){
            return rangeSumBST(root -> left, low, high);
        }
        return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
    }
};

/*
�ݹ�Ľⷨ 
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        int sum = rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        if(root -> val >= low && root -> val <= high){
            sum += root -> val;
        }
        return sum;
    }
};

/*
dfs
*/
class Solution {
public:
    int s, l ,h;
    int rangeSumBST(TreeNode* root, int low, int high) {
        s = 0; l = low; h = high;
        dfs(root);
        return s; 
    }
    void dfs(TreeNode * root){
        if(root){
            dfs(root -> left);
            if(root -> val >= l && root -> val <= h) s += root -> val;
            else if (root -> val >h) return ;
            dfs(root -> right);
        }
    }
};
