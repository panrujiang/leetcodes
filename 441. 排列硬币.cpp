/*
题目来源：
https://leetcode.cn/problems/arranging-coins/description/
解答：
https://www.bilibili.com/video/BV1dY4y1m7YB?p=13&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/
/*
解法一 ：模拟 
*/
class Solution {
public:
    int arrangeCoins(int n) {
        for(int i = 1; i <= n; i ++){
            n-= i;
            if(n <  i + 1){
                return i;
            }
        }
        return -1;
    }
};

/*
二分法 
使用了long，因为int类型放不下 
*/
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        while(left <= right){
            long mid = left + (right - left) / 2;
            long sum = (mid + 1) * mid / 2;
            if(sum == n){
                return mid;
            }else if(sum < n){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        return right;
    }
};
/*
三叶的解法（也是二分） 
*/
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = n;
        while(left < right){
            long mid = (left + right + 1) >> 1;
            long sum = (mid + 1) * mid  / 2;
            if(sum <= n){
                left = mid;
            }else{
                right = mid -1;
            }
        }
        return right;
    }
};
/*
牛顿迭代法 
*/
class Solution:
    def arrangeCoins(self, n: int) -> int:
        value = n
        while abs(value * value + value - 2 * n) > 0.01:
            value = (value * value + 2 * n)/(2 * value + 1)
        return int(value)
