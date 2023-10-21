/*
 * @Author: panrujiang 3144571429@qq.com
 * @Date: 2023-10-19 17:03:17
 * @LastEditors: panrujiang 3144571429@qq.com
 * @LastEditTime: 2023-10-19 17:08:36
 * @FilePath: \leetcodes\151. 反转字符串中的单词.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
题目来源：
https://leetcode.cn/problems/reverse-words-in-a-string/description/
解答：
https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html#%E6%80%9D%E8%B7%AF
*/

class Solution {
public:
    //双指针实现字符串的反转
    void reverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --){
            swap(s[i],s[j]);
        }
    }
    //去除空格，双指针，只对非空格进行处理，最后自行在每个单词后面加上空格
    void removeExtraSpaces(string& s){
        int slow = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] != ' '){
                //如果还有非空格，说明还有单词，在之前的单词后面加上空格
                if(slow != 0) s[slow ++] = ' ';
                while(i < s.size() && s[i] != ' '){
                    s[slow ++] = s[i ++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s,0,s.size() - 1);
        int start = 0;
        for(int i = 0; i <= s.size(); i ++){
            if(i == s.size() || s[i] == ' '){
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
