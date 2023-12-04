/*
题目来源：
https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[size - 1] - 1) * (nums[size - 2] - 1);
    }
};
/*
维护最大元素和第二大元素 
*/
class Solution {
public
    int maxProduct(vectorint& nums) {
        int a = INT_MIN, b = INT_MIN;
        for(int i =0; i  nums.size(); i ++){
            if(nums[i]  a){
                b = a;
                a = nums[i];
            }
            else if(nums[i]  b){
                b = nums[i];
            }
        }
    return (a - 1)  (b - 1);
    }
};
