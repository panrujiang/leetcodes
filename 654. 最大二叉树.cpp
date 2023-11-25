/*
问题来源：
https://leetcode.cn/problems/maximum-binary-tree/description/
解答：
https://programmercarl.com/0654.%E6%9C%80%E5%A4%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/maximum-binary-tree/solutions/1762400/zhua-wa-mou-si-by-muse-77-myd7/
*/

/*
空间复杂度高 
*/ 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if(nums.size() == 1){
            node -> val = nums[0];
            return node;
        }

        int maxValue = 0;
        int maxValueIndex = 0;
        for(int i =0; i < nums.size(); i ++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node -> val = maxValue;

        if(maxValueIndex > 0){
            vector<int> newVec(nums.begin(),nums.begin() + maxValueIndex);
            node -> left = constructMaximumBinaryTree(newVec);
        } 
        if(maxValueIndex < nums.size() - 1){
            vector<int> newVec(nums.begin() + maxValueIndex + 1,nums.end());
            node -> right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};
/*
优化版 ，左闭右开 
*/

class Solution {
private:
    TreeNode* traversal(vector<int>& nums,int left, int right){
       if(left >= right) return NULL;
        int maxValueIndex = left;
        for(int i = left + 1; i < right; i ++){
            if(nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* node = new TreeNode(nums[maxValueIndex]);

        node -> val = nums[maxValueIndex];
        node -> left = traversal(nums,left,maxValueIndex);
        node -> right = traversal(nums,maxValueIndex + 1, right);

        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};

/*
单调栈的超屌解法 ，Java版本 
*/

class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        Deque<TreeNode> deque = new ArrayDeque();
        for (int i = 0; i < nums.length; i++) {
            TreeNode node = new TreeNode(nums[i]);
            while(!deque.isEmpty()) {
                TreeNode topNode = deque.peekLast();
                if (topNode.val > node.val) {
                    deque.addLast(node);
                    topNode.right = node;
                    break;
                } else {
                    deque.removeLast(); // 出栈操作
                    node.left = topNode;
                }
            }
            if (deque.isEmpty()) deque.addLast(node);
        }
        return deque.peek();
    }
}
