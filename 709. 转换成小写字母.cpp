/*
题目来源：
https://leetcode.cn/problems/to-lower-case/description/
解答：
https://leetcode.cn/problems/to-lower-case/solutions/1151839/zhuan-huan-cheng-xiao-xie-zi-mu-by-leetc-5e29/
https://leetcode.cn/problems/to-lower-case/solutions/766281/ming-ming-zhi-you-26ge-zi-mu-wei-shi-yao-d2ec/
*/

/*
方法一：使用语言 API
*/
class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch : s){
            ch = tolower(ch);
        }
        return s;
    }
};
/*
或的方法
大写变小写、小写变大写：字符 ^= 32 （大写 ^= 32 相当于 +32，小写 ^= 32 相当于 -32）
大写变小写、小写变小写：字符 |= 32 （大写 |= 32 就相当于+32，小写 |= 32 不变）
大写变大写、小写变大写：字符 &= -33 （大写 &= -33 不变，小写 &= -33 相当于 -32）
*/
class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch : s){
            if(ch >= 65 && ch <= 90){
                ch |= 32;
            }
        }
        return s;
    }
};
