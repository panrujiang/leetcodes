/*
题目来源：
https://leetcode.cn/problems/palindrome-number/description/
解答：
https://leetcode.cn/problems/palindrome-number/solutions/6170/dong-hua-hui-wen-shu-de-san-chong-jie-fa-fa-jie-ch/
*/


/*
我的数学做法，判断逆转之后的数字是否相同 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long ans = 0;
        int num = x;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return num == ans;
    }
};
/*
我的做法：
to_string()转化为字符串，双指针 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string ans = to_string(x);
        int left = 0, right = ans.size() - 1;
        while(left < right){
            if(ans[left] != ans[right]){
                return false;
            }
            left ++;
            right --;
        }
       return true;
    }
};
/*
数学的方法 最前面的数和最后面的数判断 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x / div >= 10) {
            div *= 10;
        }
        while(x > 0){
            int left = x / div;
            int right = x % 10;
            if(left != right){
                return false;
            }
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

/*
将后半部分翻折过来
但要排除一些特殊情况 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int left = x, right = 0;
        while(left > right){
            right = right * 10 + left % 10;
            left /= 10;
        }
        return left == right || left == right /10;
    }
};
