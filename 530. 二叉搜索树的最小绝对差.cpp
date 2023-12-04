/*
问题来源：
https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
解答：
https://programmercarl.com/0530.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
中序遍历，变成数组 
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
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int slow = 0, fast = slow + 1;
        int min = INT_MAX;
        while(fast <vec.size()){
            min = min < abs(vec[fast] - vec[slow]) ? min : abs(vec[fast] - vec[slow]);
            slow ++;
            fast ++;
        } 
        return min;
    }
};

/*
不用数组 
*/
class Solution {
private:
    int result = INT_MAX;
    TreeNode* pre = NULL;
    void traversal(TreeNode* cur){
        if(cur == NULL) return;
        traversal(cur -> left);
        if(pre != NULL){
            result = min(result,cur -> val - pre -> val);
        }
        pre = cur;
        traversal(cur -> right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
            traversal(root);
            return result;
    }
};
