/*
题目来源：
https://leetcode.cn/problems/reverse-string-ii/description/
解答：
https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
*/

/*
遍历就行，只不过要巧一点，i每次跳2 * k的距离
end()指向最后一个元素的下一个位置
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i =0; i < s.size(); i += (2 * k)){
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i,s.end());
            }
        }
        return s;
    }
};