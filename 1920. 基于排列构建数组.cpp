/*
题目来源：
https://leetcode.cn/problems/build-array-from-permutation/description/
解答：
https://leetcode.cn/problems/build-array-from-permutation/solutions/858017/ji-yu-pai-lie-gou-jian-shu-zu-by-leetcod-gjcn/
*/

/*
简单解法,创建一个数组，按题意来就行 
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for(int i = 0; i < size; i ++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

/*
力扣官方给出，直接在原来数组上改，将元素赋予含义 
为了使得构建过程可以完整进行，我们需要让 nums 中的每个元素
nums[i] 能够同时存储「当前值」（即 nums[i])和「最终值」（即 nums[nums[i]])
商放目标值，余数放当前值 
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++){
            nums[i] += 1000 * (nums[nums[i]]%1000);
        }
        for(int i = 0 ; i < nums.size(); i ++){
            nums[i] /= 1000;
        }
        return nums;
    }
};

