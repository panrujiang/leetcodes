/*
题目来源：
https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
解答：
https://leetcode.cn/problems/remove-duplicates-from-sorted-array/solutions/34033/shuang-zhi-zhen-shan-chu-zhong-fu-xiang-dai-you-hu/
*/

/*
双指针 
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        while(right < nums.size()){
            if(nums[right] != nums[left]){
                nums[++ left] = nums[right];
            }
                right ++;
        }
        return left + 1;
    }
};
