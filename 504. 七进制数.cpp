/*
题目来源：
https://leetcode.cn/problems/base-7/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=34&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
我的解法 
*/
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans;
        int n = abs(num);
        while(n){
            ans  = (char)(n % 7  +  '0' ) +  ans;
            n /= 7;
        }
        return ans = num > 0 ? ans : "-" + ans;
    }
};
