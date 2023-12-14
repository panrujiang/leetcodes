/*
题目来源：
https://leetcode.cn/problems/convert-a-number-to-hexadecimal/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=33&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/convert-a-number-to-hexadecimal/solutions/1027527/gong-shui-san-xie-yi-ti-shuang-jie-jin-z-d93o/
*/
/*
1.将负数转换成无符号 2.每四位转换成16进制 
*/
class Solution {
private:
    char code(int n){
        if(n >= 10){
            return n - 10 + 'a';
        }
        return n + '0';
    }
public:
    string toHex(int num) {
        unsigned int n = num;
        if(!n){
            return "0";
        }
        string ret;
        while(n){
            ret += code (n & 0xf);
            n >>= 4;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/*
取余的方法 
*/
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        long n = num;
        string ans;
        if(num < 0)  {
            n = num + pow(2,32);
        }
        while(n != 0){
            long u = n % 16;
            char c = u >= 10 ? (u - 10 + 'a') : u + '0';
            ans.push_back(c);
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
小技巧，最后不用反转了  ret = code (n & 0xf) + ret;
*/
class Solution {
private:
    char code(int n){
        if(n >= 10){
            return n - 10 + 'a';
        }
        return n + '0';
    }
public:
    string toHex(int num) {
        unsigned int n = num;
        if(!n){
            return "0";
        }
        string ret;
        while(n){
            ret = code (n & 0xf) + ret;
            n >>= 4;
        }
        return ret;
    }
};
