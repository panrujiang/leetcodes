/*
题目来源：
https://leetcode.cn/problems/missing-number/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=18&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/missing-number/solutions/1086545/gong-shui-san-xie-yi-ti-wu-jie-pai-xu-ji-te3s/
*/

/*
把所有数字加起来，再依次减去 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) /2;
        for(int i = 0; i < n; i ++){
            sum -= nums[i];
        }
        return sum;
    }
};


/*
对数组排序，比下标 ，找不到返回最大值 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++){
            if(i != nums[i]){
               return i;
            }
        }
        return n;
    }
};

/*
哈希表 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n + 1, false);
        for(int i = 0; i < n; i ++){
            result[nums[i]] = true;
        }
        for(int i = 0; i < n; i ++){
            if(!result[i]){
                return i;
            }
        }
        return n;
    }
};

/*
本人异或的做法，有点拉 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n + 1);
        for(int i = 0; i < n + 1; i ++){
            result[i] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans ^= nums[i];
        }
        for(int i = 0; i < n + 1; i ++){
            ans^=result[i];
        }
        return ans;
    }
};

/*
宫水三叶的异或法 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i ++){
            ans ^= i;
        }
        for(int i = 0; i < nums.size(); i ++){
            ans ^= nums[i];
        }
        return ans;
    }
};
