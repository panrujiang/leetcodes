/*
题目来源：
https://leetcode.cn/problems/sqrtx/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=57&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
英雄不问出处的解法 ，当mid * mid小于x,把该值记录下来，作为一次有效值 
*/
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans;
        while(left <= right){
            int mid = (left + right) >> 1;
            if((long long) mid * mid <= x){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};
/*
这些数不一定全是完全平方根，如果是完全平方数，直接在while()中返回了 
跳出循环的时候，说明这个数不是完全平方根，返回right即可 ，right就是答案 
*/
class Solution {
public:
    int mySqrt(int x) {
        int  left = 0, right = x;

        while(left <= right){
            int mid = left + (right - left)/2;
            if((long long)mid * mid < x )
                left = mid + 1;
            else if((long long)mid * mid > x)
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
