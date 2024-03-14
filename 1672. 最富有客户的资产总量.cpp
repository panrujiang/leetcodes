/*
��Ŀ��Դ��
https://leetcode.cn/problems/richest-customer-wealth/description/
*/

/*
ģ�� 
*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int sum = 0;
        for(int i = 0; i < accounts.size(); i ++){
            for(int j = 0; j < accounts[0].size(); j ++){
                sum += accounts[i][j];
            }
            max = max > sum? max : sum;
            sum = 0;
        }
        return max;
    }
};

/*
ջ������ 
*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        stack<int> stk;
        //��ֹ��ջ 
        stk.push(0);
        for(int i = 0 ; i < m; i ++){
            int sum = 0;
            for(int j = 0 ; j < n ; j ++){
                sum += accounts[i][j];
            }
            if( sum > stk.top()){
                stk.push(sum);
            }
        }
        return stk.top();
    }
};
