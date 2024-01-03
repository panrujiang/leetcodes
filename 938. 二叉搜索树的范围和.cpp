/*
题目来源：
https://leetcode.cn/problems/range-sum-of-bst/description/
解答：
https://leetcode.cn/problems/range-sum-of-bst/solutions/6703/hua-jie-suan-fa-938-er-cha-sou-suo-shu-de-fan-wei-/
*/
/*
递归法，树就应该想到递归后序遍历 
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
递归的解法 
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
