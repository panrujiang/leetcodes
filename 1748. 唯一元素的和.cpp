/*
问题来源：
https://leetcode.cn/problems/sum-of-unique-elements/description/
解答：
https://www.bilibili.com/video/BV1Ra41177RB/?spm_id_from=333.788&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a

*/


/*
暴力解法 
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans[101] = {0};
        int count = 0;
        for(int i =0; i < nums.size(); i ++){
            ans[nums[i]] ++;
        }
        for(int i =0; i <101; i ++){
            if(ans[i] == 1)
                count += i;
        }
        return count;
    }
};

/*
双指针还是厉害，for语句不确定i的步长时可以先空着 
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && nums[j] == nums[i]) j ++;
            if(j - i == 1) sum += nums[i];
            i = j;
        }
        return sum;
    }
};
