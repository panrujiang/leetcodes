/*
原题：https://leetcode.cn/problems/fibonacci-number/description/
一些比较好的解答：
https://blog.csdn.net/weixin_57544072/article/details/121969045?app_version=6.1.7&csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22121969045%22%2C%22source%22%3A%22m0_53573725%22%7D&utm_source=app
https://leetcode.cn/problems/fibonacci-number/solutions/545049/fei-bo-na-qi-shu-by-leetcode-solution-o4ze/
https://leetcode.cn/problems/fibonacci-number/solutions/2361746/509-fei-bo-na-qi-shu-dong-tai-gui-hua-qi-so8h/ 
*/
/*
暴力递推，操作过于复杂 
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        if(n == 2)
            return 1;
        return fib(n-1) + fib(n - 2);

    }
};
/*
动态规划，记忆式搜索。
即然低效的原因是重复计算，那么我们可以造一个「备忘录」，每次算出某个子问题的答案后别急着返回，先记到「备忘录」里再返回；每次遇到一个子问题先去「备忘录」里查一查，如果发现之前已经解决过这个问题了，直接把答案拿出来用，不要再耗时去计算了。
一般使用一个数组充当这个「备忘录」，当然你也可以使用哈希表（字典），思想都是一样的。
*/
class Solution {
public:
	int fib(int n){
		if(n <= 1){
			return n;
		}
		vector<int> ans(n + 1,0);
		ans[0] = 0;
		ans[1] = 1;
		for(int i =2; i <= n; i++){
			ans[i] = ans[i-1] + ans[i - 2];
		}
		return ans[n];
	}
}; 
/*
也是动态规划，不同的展示方式 
*/
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int p = 0, q = 1, r = 1;
        int loop = n - 2;
        while(loop -- > 0){
            p = q;
            q = r;
            r = p + q;
        } 
        return r;
    }
};
