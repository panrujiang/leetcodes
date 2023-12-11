/*
题目来源：
https://leetcode.cn/problems/power-of-two/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=8&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        double ans = 1;
        while(1){
            ans *= 2;
            if(ans == n){
                return true;
            }else if(ans > n){
                return false;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        while( n % 2 == 0) n /= 2;
        return n == 1;
    }
};

