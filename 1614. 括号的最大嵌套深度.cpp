/*
��Ŀ��Դ��
https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/description/
���
https://www.bilibili.com/video/BV1da411M798/?p=82&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
������������ ��һ����������һ 
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
