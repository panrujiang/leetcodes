/*
题目来源：
https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/
解答：
https://programmercarl.com/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
*/

/*
三次反转，C++ 
*/
class Solution {
public:
    string dynamicPassword(string password, int target) {
           reverse(password.begin(), password.begin() + target);
           reverse(password.begin() + target, password.end());
           reverse(password.begin(), password.end());
           return password;
    }
};

/*
python的切片函数 
*/

class Solution:
    def dynamicPassword(self, password: str, target: int) -> str:
        return password[target:] + password[:target]




