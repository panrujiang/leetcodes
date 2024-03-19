/*
问题来源：
https://leetcode.cn/problems/string-rotation-lcci/description/
解答：

*/

/*
像这种轮转的问题，一般有两种套路，第一种将轮转后字符串连接，这样就会出现未轮转之前的字符串，然后使用find函数；
第二种方法就是以轮转次数为边界，先反转前一部分，再反转后一部分，然后再全部反转，这样就得到了初始字符串 
*/
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }
        s2 += s2;
        return s2.find(s1) != string::npos;

    }
};
