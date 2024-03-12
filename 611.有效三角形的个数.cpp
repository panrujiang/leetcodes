/*
问题来源：
https://leetcode.cn/problems/valid-triangle-number/
解答：
https://blog.csdn.net/weixin_64904163/article/details/136557858
*/

/*
解法一：暴力搜索（也叫遍历）
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n ; i ++){
            for(int j = i + 1; j < n; j ++){
                for(int k = j + 1; k < n; k ++){
                    if(nums[i] + nums[j] > nums[k]){
                        cnt ++;
                    }
                }
            }
        }
        return cnt ;

    }
};
/*
解法二：对撞双指针
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0 ; i --){
            int l = 0, r = i - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    cnt += r - l;
                    r --;
                }else{
                    l ++;
                }

            }
        }
        return cnt;
    }
};
