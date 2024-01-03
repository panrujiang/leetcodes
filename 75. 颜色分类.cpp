/*
题目来源：
https://leetcode.cn/problems/sort-colors/description/
解答：
https://www.bilibili.com/video/BV1ab4y137N3/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
荷兰三色旗问题 
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        for(int i = 0; i < nums.size() && i <= right; i ++){
            if(nums[i] == 0){
                swap(nums[i],nums[left]);
                left ++;
            }else if(nums[i] == 2){
                swap(nums[i],nums[right]);
                i --;
                right --;
            }
        }
    }
};

