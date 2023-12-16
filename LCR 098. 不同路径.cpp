/*
题目来源：
https://leetcode.cn/problems/2AoeFn/description/
解答：
https://www.bilibili.com/video/BV1da411M798/?p=62&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
动态数组，用一维数组 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n,1);
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                ans[j] += ans[j - 1];
            }
        }
        return ans[n - 1];
    }
};

/*
英雄哪里出来 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        int f[110][110];
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == 1 || j == 1){
                    f[i][j] = 1;
                }else{
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};
