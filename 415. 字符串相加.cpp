/*
题目来源：
https://leetcode.cn/problems/add-strings/description/?envType=study-plan-v2&envId=selected-coding-interview
解答：
https://leetcode.cn/problems/add-strings/solutions/12250/add-strings-shuang-zhi-zhen-fa-by-jyd/?envType=study-plan-v2&envId=selected-coding-interview
*/


/*
从最后面开始,长度不够用0来补，定义进位变量，如果最后carry == 1,在加上1，字符串的连接操作，字符串的反转 
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int up = num1.size() - 1, down = num2.size() - 1, carry = 0;
        while(up >= 0 || down >= 0){
            int n = up >= 0 ? num1[up] - '0' : 0;
            int m = down >= 0 ? num2[down] - '0' : 0;
            int temp =  n + m + carry;
            carry = temp / 10;
            ans += to_string(temp % 10);
            up --;
            down --;
        }
        if(carry == 1){
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
