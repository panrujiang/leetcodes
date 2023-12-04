/*
题目来源：
https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked
*/


/*
用一个长度为 nums.size()/2 + 1的滑动数组，先排序，检验首末两端的元素是否相同 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        int size = nums.size()/2 + 1;
        int slow = 0, fast = slow + size - 1;
        sort(nums.begin(), nums.end());
        while(fast < nums.size()){
            if(nums[slow] == nums[fast]){
                result = nums[slow];
                break;
             }
             slow ++;
             fast ++;
        }
        return result;
    }
};

