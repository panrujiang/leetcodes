/*
题目来源：
https://leetcode.cn/problems/valid-palindrome/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=42&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/valid-palindrome/solutions/292148/yan-zheng-hui-wen-chuan-by-leetcode-solution/
*/

/*
英雄哪里出来的解法，第一次见将小写转换成大写，第二次双指针遍历，判断，跳过非字母数字 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i ++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] += 'A' - 'a';
            }
        }
        int l = 0, r = n - 1;
        while(l <= r){
            if(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9'))){
                l ++;
                continue;
            }
            if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9'))){
                r --;
                continue;
            }
            if(s[l] != s[r]){
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};

/*
C++的API直接拿来用 
isalnum(ch)判断是否是字母数字
string的构造 string sgood_rev(sgood.rbegin(), sgood.rend());
rbegin()末尾元素位置， rend()首元素位置 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for(char ch : s){
            if(isalnum(ch)){
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};

/*
在原数组上修改 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left ++;
            }
            while(left < right && !isalnum(s[right])){
                right --;
            }
            if(left < right){
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left ++;
                right --;
            }
        }
        return true;
    }
};

