/*
ԭ�⣺
https://leetcode.cn/problems/climbing-stairs/description/ 
���
https://leetcode.cn/problems/climbing-stairs/solutions/286022/pa-lou-ti-by-leetcode-solution/
*/

/*
��̬�滮���Զ�����
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        ans[2] = 2;
        for(int i = 3; i <= n; i++){
            ans[i] = ans[i - 1] + ans[i -2]; 
        }
        return ans[n];
    }
};

/*
��̬�滮������汾ʮ�ּ�࣬ʡȥ�˷������ۣ���ʼ״̬Ϊ0 0 1��n=1ʱ�����r = 1. 
*/ 
class Solution {
public:
    int climbStairs(int n) { 
        int  p = 0, q = 0,r = 1;
        for(int i = 1;i <= n; i ++){
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
/*
��������ݣ�
https://zhuanlan.zhihu.com/p/95902286 
*/
class Solution {
public:
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
        vector<vector<long long>> c(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long>> ret = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = matrixPow(ret, n);
        return res[0][0];
    }
};

/*
���ݵ��㷨����Դ��Hello�㷨����ϧ��n̫���ʱ��Ͳ������� 
*/
class Solution {
private:
    int ans = 0;
    void trackback(int count, int n){
        if(count == n){
            ans ++;
            return;
        }
        for(int i = 1; i <= 2; i ++){
            if(count + i > n){
                break;
            }
            trackback(count + i, n);
        }
    }
public:
    int climbStairs(int n) {
        trackback(0, n);
        return ans;
    }
};

