/*
题目来源：
https://leetcode.cn/problems/rotate-string/description/
解答：
https://leetcode.cn/problems/rotate-string/solutions/61978/c-yi-xing-ti-jie-by-da-li-wang-4/
*/

/*
将旋转后的字符串并起来，然后再寻找
find()函数如果找不到字符串，就会返回 string::npos
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (goal + goal).find(s) != string::npos;
    }
};

