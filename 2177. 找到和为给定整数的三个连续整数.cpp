/*
��Ŀ��Դ��
https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/
���
https://www.bilibili.com/video/BV1da411M798?p=61
*/

/*
�ҵ������� very stupid 
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
Ӣ��������� 
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
