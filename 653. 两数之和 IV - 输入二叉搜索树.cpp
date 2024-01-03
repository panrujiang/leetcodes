/*
题目来源：
https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/
解答：
https://www.bilibili.com/video/BV1da411M798?p=95&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/solutions/621832/suan-fa-si-wei-yang-cheng-ji-er-fen-cha-1vttm/
*/

/*
二叉搜索树的性质 + 单调递增数列 + 双指针 
*/
class Solution {
    vector<int> res;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root -> left);
        res.push_back(root -> val);
        dfs(root -> right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int left = 0, right = res.size() - 1;
        while(left < right){
            if(res[left] + res[right] == k){
                return true;
            }else if(res[left] + res[right] < k){
                left ++;
            }else{
                right --;
            }
        }
        return false;
    }
};

/*
哈希表查找 
*/
class Solution {
bool find(TreeNode* node, int target, unordered_set<int>& set){
    if(node == NULL) return false;
    if(set.count(target - node -> val)) return true;
    set.insert(node -> val);
    return find(node -> left, target, set) || find(node -> right, target, set);
}
public:
    bool findTarget(TreeNode* root, int k) {
        if( root == NULL) return false;
        unordered_set<int> set;
        return find(root, k, set);
    }
};
