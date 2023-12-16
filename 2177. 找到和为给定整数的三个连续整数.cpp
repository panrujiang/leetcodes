/*
题目来源：
https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=61
*/

/*
我的做法： very stupid 
*/
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num % 3 == 0){
            ans.push_back(num / 3 - 1);
            ans.push_back(num / 3 );
            ans.push_back(num / 3 + 1);
        }
        return ans;
    }
};

/*
英雄哪里出来 
*/
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3){
            return {};
        }
        return {num / 3 - 1, num / 3, num / 3 + 1};
    }
};
