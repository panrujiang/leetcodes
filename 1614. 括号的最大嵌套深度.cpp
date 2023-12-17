/*
题目来源：
https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/description/
解答：
https://www.bilibili.com/video/BV1da411M798/?p=82&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
遍历，遇到（ 加一，遇到）减一 
*/
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int res = 0;
        for(char ch : s){
            if(ch == '(') ans ++;
            if(ch == ')') ans --;
            res = max(ans, res);
        }
        return res;
    }
};
