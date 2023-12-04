/*
题目来源：
https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
解答：
https://www.bilibili.com/video/BV1hG411q7q6/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
我的解法 
*/ 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> result;
        int store[100000] = {0};
        for(int i = 0; i < nums.size(); i ++){
            if(store[nums[i]] == 0){
                store[nums[i]] --;
            }
            else{
                result.push_back(nums[i]);
            }
        }
    return result;
    }
};
/*
对数组先排序 
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i ++){
            if(nums[i] == nums[i + 1]){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
